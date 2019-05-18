function [filterArray,triangleArray] = createStructs(R,delay,finalIR,filterID,E1,E2,E3,PM)

% create array of filter structs
filterArray = struct('orientation',zeros(3,1),'delay',0,...
                     'IR',zeros(150,1));

N = 187;                 
M = 370;                 
for n = 1:N                 

    filterArray(n).orientation = R(n,:)';
    filterArray(n).delay = delay(n);
    filterArray(n).IR = finalIR(:,n);
    
end
%% create array of triangle structs
triangleArray = struct('filterIDs',zeros(1,3),'edges',...
                       zeros(3,3),'projectionMatrix',zeros(3,3));
                   
for n = 1:M
   
    triangleArray(n).filterIDs = filterID(n,:);
    triangleArray(n).edges = [E1(n,:);E2(n,:);E3(n,:)];
    triangleArray(n).projectionMatrix = PM(:,:,n);
    
end

end