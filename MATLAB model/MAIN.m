%%
clc
close all
clear

%% load data from library of head-related impulse responses (any S0*.mat file from the library should work
load 'HRIRrepository/S001_marl-nyu.mat';
[IR,delay,azimuth,elevation] = loadData(data);


%% compute direction vectors corresponding to existing sound directions
r = computeDirectionVectors(azimuth,elevation);

%% plot all direction vectors
figure;
view(3);
for n = 1:187

quiver3(0,0,0,r(1,n),r(2,n),r(3,n),'LineWidth',2);
hold on

end
title('Direction vectors');
axis equal;
set(gca,'Zdir','reverse');
set(gca,'Ydir','reverse');
xlabel('x');
ylabel('y');
zlabel('z');

%% write filter coefficients, delays and direction vectors to files for import to Blackfin 533 EZ-Kit
writeCoefficients(IR);
writeHeaders(r,delay);

%% compute filter IDs, triangle edges and projection matrices
[filterIDs, E1, E2, E3, PM] = computeTriangleData(r);

%% plot triangles
figure;
trisurf(filterIDs,r(1,:),r(2,:),r(3,:));
title('Triangles used for interpolation');
set(gca,'Zdir','reverse');
set(gca,'Ydir','reverse');
xlabel('x');
ylabel('y');
zlabel('z');
axis equal;

%% write filter IDs, triangle edges and projection matrices to file for use on Blackfin 533 EZ-Kit
writeFilterTriangles(filterIDs,E1,E2,E3,PM);

%% write tweedle values, for faster sinudal computation
writeTweedleCoefficients(24);

%% create filter and triangle structs
[filterArray,triangleArray] = createStructs(r',delay,IR,filterIDs,E1,E2,E3,PM);

%% start 3D sound simulator
play3DSound('thank-god-its-friday.wav',filterArray,triangleArray);

%%
% [direction,mirrorDirection,ID,mirrorID,weights,mirrorWeights,irLeft,irRight] = ...
% returnInterpolationData(-10,-5,filterArray,triangleArray,filterIDs,r);
% direction
% ID
% weights
% mirrorDirection
% mirrorID
% mirrorWeights