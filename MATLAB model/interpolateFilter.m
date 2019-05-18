function interpolatedIR = interpolateFilter(weights,triangleID,filterArray,triangleArray)

% get filter IDs
filterIDs = triangleArray(triangleID).filterIDs;
% get impulse responses
IR1 = filterArray(filterIDs(1)).IR;
IR2 = filterArray(filterIDs(2)).IR;
IR3 = filterArray(filterIDs(3)).IR;
% get delays
delay1 = filterArray(filterIDs(1)).delay;
delay2 = filterArray(filterIDs(2)).delay;
delay3 = filterArray(filterIDs(3)).delay;

delayAvg = (delay1 + delay2 + delay3)/3;

% interpolate
coefficients = sqrt(weights(1)) * IR1 + ...
               sqrt(weights(2)) * IR2 + ...
               sqrt(weights(3)) * IR3;
           
interpolatedIR = [zeros(floor(delayAvg),1); coefficients;...
                  zeros(256-(floor(delayAvg)+150),1)];

end