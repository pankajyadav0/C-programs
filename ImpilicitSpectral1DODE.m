clear
N = 128;
c = zeros(N,1);
M = 2; %number of waves in the interval
D = 1;
delt = 1.0; %Allow to take larger delt. does not affect stability in Implicit method
             % though smaller delt gives more accurate results

%Initial Sinusoidal Profile
for j=1:N
    c(j,1) = 0.5*(1+sin(2*pi*M*j/N));  
    %sin goes from -1 to 1. if multiplied by 2, goes from 0 to 2.
    %again multiplied by 0.5, goes from 0 to 1 which we want
end
plot(c)
hold on

%For periodic boundary condition

%Define half length of the box
halfN = N/2;

%Define the grid spacing in the Fourier space
delk = 2*pi/N;

ctilde = zeros(N,1);
for k = 1:10 %loop for plotting
for m = 1:1200 %loop for evolving the composition
    ctilde = fft(c);
for  i = 1:N
       if (i<halfN), k = i*delk; %PBC are implemented
       else k = (i-N)*delk;
       end
    ctilde(i) = ctilde(i)/(1+D*k*k*delt);
end
end


c = real(ifft(ctilde));
plot(c)
end