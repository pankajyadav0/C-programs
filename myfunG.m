%function f = myfun(x)
%f = (x-3)^2 ;

%function f = myfun(x,a)
%f = (x-a)^2;

%end
function f1 = myfunG(~)
a(1) = 2;
for i = 1:400
    c(i) = fminbnd(@(x) myfunG1(x,a(i)),0.001,0.499);
    d(i) = fminbnd(@(x) myfunG1(x,a(i)),0.501,0.999);
    a(i+1) = a(i) + 0.001;
end
for i = 1:400
    b(i) = a(i);
end
plot(c,1./b)
hold on
plot(d,1./b)

f1 = myfungpp;
end

function f = myfungpp(~)
y(1) = 2.01;
x0 = [0.0001;0.5001];
x1 = [0.4999;0.9999];
for j = 1:400
    f(j) = fzero(@(x) myfungpp1(x,y(j)), x0);
    g(j) = fzero(@(x) myfungpp1(x,y(j)), x1);
    y(j+1) = y(j) + 0.001;
end
for j = 1:400
    v(j) = y(j);
end
hold on
plot(f,1./v);

plot(g,1./v);
end


function f = myfunG1(x,a)
f = a.*x.*(1-x) + x.*log(x) + (1-x).*log(1-x);
end

function z = myfungpp1(x,y)
z = -2*y + 1./x + 1./(1-x);
end




