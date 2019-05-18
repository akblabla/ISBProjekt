function writeDirectionVectors(r)

r = reshape(r,[187*3,1]);
for n = 1:size(r,1)
   
    if abs(r(n)) < 1e-15
        r(n) = 0;
    end
    
end

r = floor(2^15 * r)/2^15;

fileID = fopen('direction_vectors.txt','w');
fprintf(fileID, "%1.15f,",r(1:end-1));
fprintf(fileID, "%1.15f\n", r(end));
fclose(fileID);

end