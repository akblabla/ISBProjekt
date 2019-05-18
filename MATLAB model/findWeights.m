function weights = findWeights(triangleID,triangleArray,orientation)

weightsNotNormalized = orientation' * triangleArray(triangleID).projectionMatrix;

weights = weightsNotNormalized * 1/norm(orientation);

end