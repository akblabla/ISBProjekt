function writeCoefficients(finalIR)

M = size(finalIR,2);

fileID = fopen('impulse_responses.txt','w');
for n = 1:M
    fprintf(fileID, "{\n\t.filterID = %d,\n",n-1);
    fprintf(fileID, "\t.coefficients = {\n");
    fprintf(fileID, "\t\t%1.15f,\n",finalIR(1:end-1,n));
    fprintf(fileID, "\t\t%1.15f\n", finalIR(end,n));
    fprintf(fileID, "\t}\n");
    fprintf(fileID, "}");
    if n<M
        fprintf(fileID, ",");
    end
    fprintf(fileID, "\n\n");

end
fclose(fileID);

end