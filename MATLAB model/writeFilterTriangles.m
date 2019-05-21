function writeFilterTriangles(filterID,E1,E2,E3,PM)

fileID = fopen('filter_triangle.txt','w');

M = size(filterID,1);
for n = 1:M
   
    fprintf(fileID, "{\n\t.triangleID = %d,\n",n-1);
    ID = filterID(n,:) - 1;
    
    fprintf(fileID, "\t.filterIDs={%d,%d,%d},\n",ID(1),ID(2),ID(3));
    fprintf(fileID, "\t.edges={\n");
    fprintf(fileID, "\t\t{.x=%1.31f, .y=%1.31f, .z=%1.31f},\n",E1(n,1),E1(n,2),E1(n,3));
    fprintf(fileID, "\t\t{.x=%1.31f, .y=%1.31f, .z=%1.31f},\n",E2(n,1),E2(n,2),E2(n,3));
    fprintf(fileID, "\t\t{.x=%1.31f, .y=%1.31f, .z=%1.31f}\n",E3(n,1),E3(n,2),E3(n,3));
    fprintf(fileID, "\t},\n");
    fprintf(fileID, "\t.projectionMatrix={\n");    
    if n < M
        fprintf(fileID, "\t\t{%1.15f, %1.15f, %1.15f},\n\t\t{%1.15f, %1.15f, %1.15f},\n\t\t{%1.15f, %1.15f, %1.15f}\n",...
                        PM(1,1,n),PM(1,2,n),PM(1,3,n),PM(2,1,n),PM(2,2,n),PM(2,3,n),PM(3,1,n),PM(3,2,n),PM(3,3,n));
    end
    fprintf(fileID, "\t}\n");
    fprintf(fileID, "}\n\n");
    if n<M
            fprintf(fileID, ",");
    end
end
fclose(fileID);

end