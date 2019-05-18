function writeCoefficients(finalIR)

finalIR = floor(2^15 * finalIR) / 2^15;

scaling = max(max(abs(finalIR)));
for n = 1:size(finalIR,2)
   
    finalIR(:,n) = finalIR(:,n) / scaling;
    finalIR(:,n) = finalIR(:,n) / (sqrt(1/sqrt(3)) *3);
    
end

finalIRrow = reshape(finalIR,187*150,1);

fileID = fopen('impulse_responses.txt','w');
fprintf(fileID, "%1.15f,",finalIRrow(1:end-1));
fprintf(fileID, "%1.15f\n", finalIRrow(end));
fclose(fileID);

end