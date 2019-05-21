function writeHeaders(r,delays)

M = size(r,2);

for n = 1:size(r,1)
    for m = 1:M
        if abs(r(n,m)) < 1e-15
            r(n,m) = 0;
        end
    end
end

r = floor(2^15 * r)/2^15;

fileID = fopen('filter_headers.txt','w');
for n = 1:M
    fprintf(fileID, "{\n\t.filterID = %d,\n",n-1);
    fprintf(fileID, "\t.orientation = {\n");
    fprintf(fileID, "\t\t%1.15f,\n",r(1,n));
    fprintf(fileID, "\t\t%1.15f,\n",r(2,n));
    fprintf(fileID, "\t\t%1.15f\n",r(3,n));
    fprintf(fileID, "\t},\n");
    fprintf(fileID, "\t.delay = %d\n",delays(n));
    fprintf(fileID, "}");

    if n<M
        fprintf(fileID, ",");
    end
    fprintf(fileID, "\n\n");
    

end
fclose(fileID);

end