function triangleID = findFilterTriangle(orientation, triangleArray)

triangleID = 0;
dotProduct = zeros(1,3);

for n = 1:370
    for j = 1:3
        dotProduct(j) = dot(triangleArray(n).edges(j,:),orientation);
    end
    if( (dotProduct(1) >= 0) && (dotProduct(2) >= 0) && (dotProduct(3) >= 0))
        triangleID = n;
        return;
    end
    
end

end