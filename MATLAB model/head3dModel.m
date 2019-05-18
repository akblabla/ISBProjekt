function head3dPatch = head3dModel()
%HEAD3DMODEL Generate crude 3d polygon model of human head
%
%   HEAD3DPATCH = HEAD3DMODEL() returns a crude 3d model
%   of a human head

% define 3D head model outline
vert = [1,1;-1,1;-1,-1;1,-1];

vert = [vert, 3/2 * ones(size(vert,1),1);
        vert, -3/2 * ones(size(vert,1),1)];
       
fac = [1:4; 5:8];

fac = [fac; NaN * ones(4,4)];

fac(3,1:4) = [1,4,8,5];
fac(4,1:4) = [1,2,6,5];
fac(5,1:4) = [2,3,7,6];
fac(6,1:4) = [3,4,8,7];

% define 3D model headset
% right ear
vert = [vert; horzcat([5/4,1/2; 1,1/2; 1,-1/2; 5/4,...
        -1/2],1/2*ones(4,1))];

vert = [vert; vert(end-3:end,1:2), -1/2*ones(4,1)];

fac = [fac; NaN * ones(5,4)];

fac(7,1:4) = 9:12;
fac(8,1:4) = 13:16;
fac(9,1:4) = [9,10,14,13];
fac(10,1:4) = [11,12,16,15];
fac(11,1:4) = [9,12,16,13];

% left ear
vert = [vert;
        horzcat([-1,1/2;-5/4,1/2;-5/4,...
        -1/2;-1,-1/2],1/2*ones(4,1))];

vert = [vert; vert(end-3:end,1:2), -1/2*ones(4,1)];

fac = [fac; NaN * ones(5,4)];

fac(12,1:4) = 17:20;
fac(13,1:4) = 21:24;
fac(14,1:4) = [17,18,22,21];
fac(15,1:4) = [19,20,24,23];
fac(16,1:4) = [18,19,23,22];

% nose
vert = [vert; 1/4,5/4,1/4; -1/4,5/4,1/4; -1/4,1,1/4;
        1/4,1,1/4; 1/4,5/4,-1/4; -1/4,5/4,-1/4;
        -1/4,1,-1/4; 1/4,1,-1/4;];

fac = [fac; NaN * ones(5,4)];

fac(17,1:4) = 25:28;
fac(18,1:4) = 29:32;
fac(19,1:4) = [25,28,32,29];
fac(20,1:4) = [26,27,31,30];
fac(21,1:4) = [25,26,30,29];

% eyes

vert = [vert; 3/4,1,1; 1/4,1,1; 3/4,1,3/4; 1/4,1,3/4;
        -3/4,1,1; -1/4,1,1; -3/4,1,3/4; -1/4,1,3/4];

fac = [fac; NaN * ones(2,4)];
    
fac(22,1:4) = [33,34,36,35];
fac(23,1:4) = [37,38,40,39];

% mouth

vert = [vert; 3/4,1,0; 1/4,1,-3/4; -1/4,1,-3/4; -3/4,1,0;
        3/4,1,-1/4; 1/4,1,-1; -1/4,1,-1; -3/4,1,-1/4];

fac = [fac; NaN * ones(1,4)];

fac = horzcat(fac, NaN * ones(size(fac,1),4));

fac(24,:) = [41,42,43,44,48,47,46,45];

% color model

facColors = ones(24,3);

facColors(22:24,:) = zeros(3,3);

facColors(1,:) = zeros(1,1);

% rotate 90 degrees clockwise

angle = deg2rad(-90);

rotMat = [cos(angle), -sin(angle), 0;
          sin(angle), cos(angle), 0;
          0, 0, 1];
      
vert = (rotMat * vert')';

% rotate 180 degrees about x axis

rotMat = [1,0,0;0,cos(pi),-sin(pi);0,sin(pi),cos(pi)];

vert = (rotMat * vert')';

% build 3D model
head3dPatch = patch('Vertices', vert, 'Faces', fac,...
                    'FaceVertexCData', facColors,...
                    'FaceColor', 'flat','AmbientStrength',.9);


end