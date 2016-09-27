function a = get_arrow(fr, dist, deg)

if nargin == 3
    color = 'k';
    thick = 2;
end
if nargin == 4
    thick = 2;
end

arrow_rate = 1/3;

rad  = deg * pi / 180;
fr_x = fr(1);
fr_y = fr(2);
to_x = fr_x + dist*cos(rad);
to_y = fr_y + dist*sin(rad);

c_x = fr_x + (1-arrow_rate)*dist*cos(rad);
c_y = fr_y + (1-arrow_rate)*dist*sin(rad);

l_x = c_x + arrow_rate*dist*cos(rad+pi/2);
l_y = c_y + arrow_rate*dist*sin(rad+pi/2);
r_x = c_x + arrow_rate*dist*cos(rad-pi/2);
r_y = c_y + arrow_rate*dist*sin(rad-pi/2);

a.l1 = [fr_x fr_y ; to_x to_y];
a.l2 = [l_x l_y ; to_x to_y];
a.l3 = [r_x r_y ; to_x to_y];

% plot(l1(:, 1), l1(:, 2), 'LineWidth', thick ...
%     , 'Color', color);
% plot(l2(:, 1), l2(:, 2), 'LineWidth', thick ...
%     , 'Color', color);
% plot(l3(:, 1), l3(:, 2), 'LineWidth', thick ...
%     , 'Color', color);
