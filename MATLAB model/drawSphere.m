function spherePatch = drawSphere()

[x,y,z] = sphere; 
spherePatch = patch(surf2patch(x+4,y,z,z));
spherePatch.AmbientStrength = .8;
shading faceted;

end