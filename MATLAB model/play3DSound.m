function play3DSound(soundFile,filterArray,triangleArray)

fig = figure;
azimut = 0;
elevation = 0;
%% human head 3D model
head3dModel();
setup3DPlot([-6,6],[-6,6],[-6,6]);
view(45,25);
title('3D sound simulator');

%% sphere representing audio direction
spherePatch = drawSphere;
initSphereVert = spherePatch.Vertices;

%% add light
for n = 1:8
light('Position',zeros(1,3),'Style','local');
end

%% extract input signal from sound file
[y,fs] = audioread(soundFile);
y = y(:,1); % use only one channel
y = resample(y,48000,fs);
fs = 48000;

%% add sliders
azimutSlider = uicontrol('Parent',fig,'Style','slider','Position',[81,74,419,23],...
                         'Value',azimut,'min',-180,'max',180);
elevationSlider = uicontrol('Parent',fig,'Style','slider','Position',[81,20,419,23],...
                         'Value',elevation,'min',-90,'max',90);   
            
%% add callback and listeners
sliderCallback = @(~,~) applyRotation(spherePatch,get(azimutSlider,'Value'),get(elevationSlider,'Value'),...
                        initSphereVert,filterArray,triangleArray,y,fs);
addlistener(azimutSlider,'Value','PostSet',sliderCallback);
addlistener(elevationSlider,'Value','PostSet',sliderCallback);


%% add text
annotation(fig,'textbox','String','Azimuth:','Units','pixels','Position',...
           [1,130,0,0],'FontSize',20,'Interpreter','Latex');
annotation(fig,'textbox','String','Elevation:','Units','pixels','Position',...
           [1,75,0,0],'FontSize',20,'Interpreter','Latex');
annotation(fig,'textbox','String','-180$^\circ$','Units','pixels','Position',...
           [1,105,0,0],'FontSize',20,'Interpreter','Latex');
annotation(fig,'textbox','String','+180$^\circ$','Units','pixels','Position',...
           [500,105,0,0],'FontSize',20,'Interpreter','Latex');
annotation(fig,'textbox','String','-90$^\circ$','Units','pixels','Position',...
           [1,50,0,0],'FontSize',20,'Interpreter','Latex');
annotation(fig,'textbox','String','+90$^\circ$','Units','pixels','Position',...
           [500,50,0,0],'FontSize',20,'Interpreter','Latex');
end

function applyRotation(spherePatch,azimut,elevation,initSphereVert,filterArray,triangleArray,y,fs)

clear sound;

R = eul2rotm(deg2rad([azimut,elevation,0]));

spherePatch.Vertices = (R * initSphereVert')';

r = R * [1,0,0]';
rMirror = [r(1),-r(2),r(3)]';

triangleID = findFilterTriangle(r,triangleArray);
mirrorTriangleID = findFilterTriangle(rMirror,triangleArray);

weights = findWeights(triangleID,triangleArray,r);
mirrorWeights = findWeights(mirrorTriangleID,triangleArray,rMirror);
for n = 1:3
   
    if abs(weights(n)) < 1e-6
        weights(n) = 0;
    end
    if abs(mirrorWeights(n)) < 1e-6
        mirrorWeights(n) = 0;
    end
    
end

ipIRLeft = interpolateFilter(weights,triangleID,filterArray,triangleArray);
ipIRRight = interpolateFilter(mirrorWeights,mirrorTriangleID,filterArray,triangleArray);

yLeft = filter(ipIRLeft,1,y);
yRight = filter(ipIRRight,1,y);

yLeft = yLeft ./ max(yLeft);
yRight = yRight ./ max(yRight);

soundsc([yLeft,yRight],fs);

end