function writeTweedleCoefficients(n)

    cosCoefficients = cos((0:(n-1))/n*2*pi);
    cosCoefficients = floor(2^15 * cosCoefficients) / 2^15;


    fileID = fopen('tweedle_cos.txt','w');
    fprintf(fileID, "%1.15f,",cosCoefficients(1:end-1));
    fprintf(fileID, "%1.15f\n", cosCoefficients(end));
    fclose(fileID);
    
    sinCoefficients = sin((0:(n-1))/n*2*pi);
    sinCoefficients = floor(2^15 * sinCoefficients) / 2^15;


    fileID = fopen('tweedle_sin.txt','w');
    fprintf(fileID, "%1.15f,",sinCoefficients(1:end-1));
    fprintf(fileID, "%1.15f\n", sinCoefficients(end));
    fclose(fileID);
end