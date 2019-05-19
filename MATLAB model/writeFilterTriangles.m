function writeFilterTriangles(filterID,E1,E2,E3,PM)

fileID = fopen('filterTriangle.txt','w');

M = size(filterID,1);
for n = 1:M
   
    ID = filterID(n,:) - 1;
    
    fprintf(fileID, "%d,%d,%d,",ID(1),ID(2),ID(3));
    fprintf(fileID, "%1.31f,%1.31f,%1.31f,",E1(n,1),E1(n,2),E1(n,3));
    fprintf(fileID, "%1.31f,%1.31f,%1.31f,",E2(n,1),E2(n,2),E2(n,3));
    fprintf(fileID, "%1.31f,%1.31f,%1.31f,",E3(n,1),E3(n,2),E3(n,3));
    
    if n < M
        fprintf(fileID, "%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,",...
                        PM(1,1,n),PM(1,2,n),PM(1,3,n),PM(2,1,n),PM(2,2,n),PM(2,3,n),PM(3,1,n),PM(3,2,n),PM(3,3,n));
    else
        fprintf(fileID, "%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f,%1.15f\n",...
                        PM(1,1,n),PM(1,2,n),PM(1,3,n),PM(2,1,n),PM(2,2,n),PM(2,3,n),PM(3,1,n),PM(3,2,n),PM(3,3,n));
    end
end
fclose(fileID);

end