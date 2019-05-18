% setup 3D plot axis limits etc.
% input: range of x, y and z axes
function setup3DPlot(xlimit,ylimit,zlimit)

xlabel('x');
ylabel('y');
zlabel('z');
axis equal;
xlim(xlimit);
ylim(ylimit);
zlim(zlimit);
view(3);
set(gca,'ZDir','reverse');
set(gca,'YDir','reverse');

end