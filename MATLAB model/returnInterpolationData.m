function [r, rMirror, triangleID, IDs, mirrorTriangleID, mirrorIDs, weights, mirrorWeights, ipLeft, ipRight] =...
          returnInterpolationData(azimut,elevation,filterArray,triangleArray,filterIDs,orientations)
      
   
R = eul2rotm(deg2rad([azimut,elevation,0]));

r = R * [1,0,0]';
rMirror = [r(1),-r(2),r(3)]';

triangleID = findFilterTriangle(r,triangleArray);
mirrorTriangleID = findFilterTriangle(rMirror,triangleArray);

weights = findWeights(triangleID,triangleArray,r);
mirrorWeights = findWeights(mirrorTriangleID,triangleArray,rMirror);

ipLeft = interpolateFilter(weights,triangleID,filterArray,triangleArray);
ipRight = interpolateFilter(mirrorWeights,mirrorTriangleID,filterArray,triangleArray);

figure;
trisurf(filterIDs,orientations(1,:),orientations(2,:),orientations(3,:));
set(gca,'Zdir','reverse');
set(gca,'Ydir','reverse');
xlabel('x');
ylabel('y');
zlabel('z');
axis equal;

hold on

IDs = filterIDs(triangleID,:);
mirrorIDs = filterIDs(mirrorTriangleID,:);

for n = 1:3
  
r_ = filterArray(IDs(n)).orientation;
rMirror_ = filterArray(mirrorIDs(n)).orientation;
    
quiver3(0,0,0,1.5 * r_(1),1.5 * r_(2),...
        r_(3),'LineWidth',2,'Color','b');
quiver3(0,0,0,1.5 * rMirror_(1),1.5 * rMirror_(2),...
        rMirror_(3),'LineWidth',2,'Color','r');    

end

quiver3(0,0,0,1.5*r(1),1.5*r(2),1.5*r(3),'LineWidth',2,'Color','c');
quiver3(0,0,0,1.5*rMirror(1),1.5*rMirror(2),1.5*rMirror(3),'LineWidth',2,'Color','m');

end