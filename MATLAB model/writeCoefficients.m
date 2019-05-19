function writeCoefficients(finalIR)

finalIRrow = reshape(finalIR,size(finalIR,2)*size(finalIR,1),1);

fileID = fopen('impulse_responses.txt','w');
fprintf(fileID, "%1.15f,",finalIRrow(1:end-1));
fprintf(fileID, "%1.15f\n", finalIRrow(end));
fclose(fileID);

end