function normalizedWeights = taylorInvSqrt(weights)

    w = sum(weights.*weights)
    invSqrt = 1-0.5*(w-1)+((w-1).^2)*0.75/2;
    normalizedWeights = weights*invSqrt;
end