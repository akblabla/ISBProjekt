function [filterID, E1, E2, E3, PM] = computeTriangleData(r)

R = r';

filterID = convhulln(R);

M = 370;
N = 187;
PM = zeros(3,3,M);
E1 = zeros(N,3);
E2 = zeros(N,3);
E3 = zeros(N,3);

for n = 1:M

L1 = R(filterID(n,1),:);
L2 = R(filterID(n,2),:);
L3 = R(filterID(n,3),:);
    
PM(:,:,n) = inv([L1;L2;L3]);
                    

E1(n,:) = -(cross((L2+L3),(L2-L3)));
E2(n,:) = -(cross((L1+L3),(L3-L1)));
E3(n,:) = -(cross((L1+L2),(L1-L2)));
E1(n,:) = E1(n,:)/norm(E1(n,:));
E2(n,:) = E2(n,:)/norm(E2(n,:));
E3(n,:) = E3(n,:)/norm(E3(n,:));

if (dot(E1(n,:),L1+L2+L3) < 0)
    E1(n,:) = -E1(n,:);
end

if (dot(E2(n,:),L1+L2+L3) < 0)
    E2(n,:) = -E2(n,:);
end

if (dot(E3(n,:),L1+L2+L3) < 0)
    E3(n,:) = -E3(n,:);
end



end

end