function [finalIR, delay, azimuth, elevation] = loadData(data)

ORIGINALFSIZE = size(data(1).IR,1);
FILTERSIZE = 150;
ORIENTATIONS = size(data,2);

originalIR = zeros(ORIGINALFSIZE,1);
finalIR = zeros(FILTERSIZE,ORIENTATIONS);
delay = zeros(ORIENTATIONS,1);
azimuth = zeros(187,1);
elevation = zeros(187,1);

% load coefficients
for n = 1:ORIENTATIONS

    originalIR(:,n) = data(n).IR(:,1);
    
    for i = 1:size(originalIR,1)
      
       if abs(originalIR(i,n)) > .015
           delay(n) = i - 1;
           finalIR(:,n) = originalIR(i:i+149,n);
           break;
       end
       
    end
    
end

delay = delay - min(delay);

for n = 1:ORIENTATIONS
   
    azimuth(n) = data(n).azimuth;
    elevation(n) = data(n).elevation;
    
end

end