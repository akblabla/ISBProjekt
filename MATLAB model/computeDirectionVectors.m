function r = computeDirectionVectors(azimuth,elevation)

ORIENTATIONS = size(azimuth,1);

i = [1,0,0]';
r = zeros(3,ORIENTATIONS);

for n = 1:ORIENTATIONS
    
    r(:,n) = eul2rotm(deg2rad([azimuth(n),elevation(n),0])) * i;
    
end

end