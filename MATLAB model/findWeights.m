function weights = findWeights(triangleID,triangleArray,orientation)

weightsNotNormalized = orientation' * triangleArray(triangleID).projectionMatrix;

weights = weightsNotNormalized / norm(weightsNotNormalized);

end