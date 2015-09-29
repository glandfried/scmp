clear all;

x0=0; y0=0; a=0.5; b=0; c=0.125; minY=-5; maxY=5; minX=-5; maxX=5; N=100;

%X=linspace(-5,5,101);
%Y=linspace(-5,5,101);
X=-5:0.1:5;
Y=-5:0.1:5;
for k = 1:5
for i = 1:size(X,2)
    x=X(i);
    for j = 1:size(X,2)
        y=Y(j);
        Z(i,j) = k*exp(-(a*(x-x0)^2 + 2*b*(y-y0) + c*(y-y0)^2));
    end;
end;
nombre=strcat(strcat('Ej1_fig',num2str(k)),'.png'); 
figure();
surf(X,Y,Z);
colorbar();
axis([-5, 5, -5, 5, 0, 5]);
shading interp;
view(-36,36);
caxis([0,5]); 
filename=sprintf('ej1_image',k);
print(filename,'-dpng');
end; 

% %% Constantes
% x0=0; y0=0;
% a=0.5;
% b=0;
% c=0.125;
% lim_inf=-5;
% lim_sup=5;
% step=0.1;
% 
% %%
% 
% for k=1:lim_sup
%   %% Forma compacta:
%     [X, Y] = meshgrid(lim_inf:step:lim_sup, lim_inf:step:lim_sup);
%     Z = k*exp( - (a*(X-x0).^2 + 2*b*(X-x0).*(Y-y0) + c*(Y-y0).^2)) ;
%     
%   %% Plotting
%     surf(X,Y,Z); shading interp; view(-36,36);
%     xlabel('X axis');
%     ylabel('Y axis');
%     zlabel('Z axis');
%     axis ([lim_inf, lim_sup, lim_inf, lim_sup, 0, lim_sup], 'square');
%     title('A 2D gaussian function');
%     caxis([0,lim_sup])
%     colorbar;
% 
%   %% Save image to disk
%     filename=sprintf('output/%05d',k);
%     print(filename,'-dpng');
% end


