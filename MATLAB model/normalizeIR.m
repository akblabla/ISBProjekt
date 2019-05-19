function finalIR = normalizeIR(IR)

finalIR = floor(2^15 * IR) / 2^15;

scaling = max(max(abs(finalIR)));
for n = 1:size(finalIR,2)
   
    finalIR(:,n) = finalIR(:,n) / scaling;
    finalIR(:,n) = finalIR(:,n) / (sqrt(1/sqrt(3)) *3);
    
end

end