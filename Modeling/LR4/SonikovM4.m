clc
clear
close all

% Вариант 24 (группа) -> 48 (общий список) -> 6 (задание) -> 18 (вторая таблица)

% ----- КОНСТАНТЫ ДЛЯ ЧАСТИ 1 -----
a = 27;
m = 2397; % как выбрать?
N = 1000;
X0 = 13;

% Случайная, равномерно распределенная
Y1 = init_gen(a,m,N,X0);

% ----- КОНСТАНТЫ ДЛЯ ЧАСТИ 2 -----
a = 44;
b = 147;
m = 49;
s = 2;
n = 10;
p = 0.5;
lmd = 9;

% Равномерное распределение
rvn(Y1,a,b,N);

% Распределение Рэлея
rel(Y1,a,N,s,m);

% Нормальное распределение
nrm(Y1,m,s,N);

% Биномиальное распределение
bnm(Y1,n,p,N);

% Распределение Пуассона
pua(Y1,lmd,N);

% ----- ФУНКЦИИ -----

function [X] = init_gen(a,m,N,X0)

disp("Начальное равномерное распределение:")
X(1) = X0;

for i=2:(N+1)
    X(i) = mod(a*X(i-1), m);
end

for i=1:length(X)
   X(i) = X(i)/m; 
end

% Гистограмма
figure
subplot(2,1,1)
cdfplot(X)
subplot(2,1,2)
histogram(X,round(sqrt(N)))
title('Начальная выборка')

% Проверки
flag = 0; 
for i = 2:1000
    if (X(i) == X(1))
        flag = 1;
    end
end
if (flag == 0)
    disp('Повторений нет')
else
    disp('Повторения есть')
end

example = makedist('Uniform');

if kstest(X,"CDF",example) == 0
    disp("Распределение равномерное")
else
    disp("Распределение не является равномерным")
end

if runstest(X) == 0
    disp("Распределение случайно")
else
    disp("Распределение не случайно")
end

disp("----------")

end

function [rvn] = rvn(X,a,b,N)

disp("Равномерное распределение:")

disp("Оценка:")
disp(1000)

for i=1:N
    rvn(i)=a+X(i)*(b-a);
end

disp("Полученный размер:")
disp(length(rvn))

figure
subplot(2,1,1)
cdfplot(rvn)
subplot(2,1,2)
histogram(rvn,round(sqrt(N)))
title('Равномерное распределение')

% Проверки
example = makedist('Uniform', 'lower', a, 'upper', b);

if kstest(rvn,"CDF",example) == 0
    disp("Распределение равномерное")
else
    disp("Распределение не является равномерным")
end

if runstest(rvn) == 0
    disp("Распределение случайно")
else
    disp("Распределение не случайно")
end

disp('----------')

end

function [norm] = nrm(X,m,s,N)

disp("Нормальное распределение:")
disp('Оценка:')
disp(500)

% %N = 718;
% k = 12;
% Kol1 = round(N/12);
% 
% while Kol1*12 + k > N
%     Kol1 = Kol1 - 12;
% end
% 
% for i=1:Kol1
%     sum=0;
%     for j=12*i:12*i+k
%        sum=sum+X(j); 
%     end
%     y(i)=sum - 6;             
%     yy(i)=y(i)*s + m;
% end

for i = 1:500
        X1(i) = s*sqrt(-2*log(X(2*i)))*cos(2*pi*X(2*i-1));
        X2(i) = s*sqrt(-2*log(X(2*i)))*sin(2*pi*X(2*i-1));
        nrm1(i) = X1(i)+m;
        nrm2(i) = X2(i)+m;
end
disp('Действительный размер 1:')
disp(length(nrm1))
disp('Действительный размер 2:')
disp(length(nrm2))

figure
subplot(2,2,1)
histogram(nrm1, round(sqrt(500)))
title('Нормальное распределение 1. Гистограмма')
subplot(2,2,2)
cdfplot(nrm1)
title('Нормальное распределение 1. Функция распределения')
subplot(2,2,3)
histogram(nrm2, round(sqrt(500)))
title('Нормальное распределение 2. Гистограмма')
subplot(2,2,4)
cdfplot(nrm2)
title('Нормальное распределение 2. Функция распределения')

if runstest(nrm1) == 0
    disp("Распределение 1 случайно")
else
    disp("Распределение 1 не случайно")
end

if chi2gof(nrm1) == 0
    disp("Распределение 1 нормальное")
else
    disp("Распределение 1 не является нормальным")
end

if runstest(nrm2) == 0
    disp("Распределение 2 случайно")
else
    disp("Распределение 2 не случайно")
end

if chi2gof(nrm2) == 0
    disp("Распределение 2 нормальное")
else
    disp("Распределение 2 не является нормальным")
end

disp('----------')

end

function [pua] = pua(X,lmd,N)

%N = 718;
xi_puass = [];
%lmd = 8;
%Kol1 = N/lmd;
b = 1;
j = 0; 

disp('Оценка:')
disp(floor(1000/lmd))

for i = 1:N
    b = b*X(i);
    j = j + 1;
    % Условие СВ Пуассона
    if (b < exp(-lmd))
        xi_puass = [xi_puass j];
        b = X(i);
        j = 1;
    end
end

disp('Полученный размер:')
disp(length(xi_puass))

figure
subplot(2,1,1)
cdfplot(xi_puass)
title('Распределение Пуассона — функция вероятности')
subplot(2,1,2)
histogram(xi_puass,round(sqrt(N)))
title('Распределение Пуассона — гистограмма')
pua = xi_puass;

example = poissrnd(lmd,[1 1000]);
if (runstest(pua) == 0)
    disp('Распределение случайно')
else
    disp('Распределение не случайно')
end

if (kstest2(pua, example) == 0)
    disp('Распределение является распределением Пуассона')
else
    disp('Распределение не является распределением Пуассона')
end

disp('----------')

end

function [rel] = rel(X,a,N,s,m)

disp("Распределение Релея:")
disp('Оценка:')
disp(1000)

for i = 1:500
        X1(i) = s*sqrt(-2*log(X(2*i)))*cos(2*pi*X(2*i-1));
        X2(i) = s*sqrt(-2*log(X(2*i)))*sin(2*pi*X(2*i-1));
%         nrm1(i) = X1(i)+m;
%         nrm2(i) = X2(i)+m;
end

for i = 1:500
    %rel(i) = X(i)/a^2 * exp(-(X(i)^2 / 2*a^2));
    rel(i) = sqrt((X1(i)^2) + (X2(i)^2));
end

disp('Полученный размер:')
disp(length(rel))

figure
subplot(2,1,1)
cdfplot(rel)
title('Распределение Релея - функция вероятности')
subplot(2,1,2)
histogram(rel,round(sqrt(N)))
title('Распределение Релея - гистограмма')

% Проверки
example = makedist("Rayleigh",2);
if kstest(rel,"CDF",example) == 0
    disp("Распределение является распределением Релея")
else
    disp("Распределение не является распределением Релея")
end

if runstest(rel) == 0
    disp("Распределение случайно")
else
    disp("Распределение не случайно")
end

end

function [bnm] = bnm(X,n,p,N)

disp("Биномиальное распределение:")
disp('Оценка:')
disp(1000/n)

start = 1;
End = n;
bnm_count = 0;

while End <= N
    bnm_count = bnm_count + 1;
    count = 0;
    for i = start : End
        if X(i) < p
            count = count + 1;
        end
    end
    bnm(bnm_count) = count;
    start = start + n;
    End = End + n;
end

% for i = 1:n
%     count = 0;
%     for j = i*10+1-10 : i*10
%         if X(j) < p
%             count = count + 1;
%         end
%     end
%     bnm(i) = count;
% 
% end

disp('Полученный размер:')
disp(length(bnm))

figure
subplot(2,1,1)
cdfplot(bnm)
title('Биномиальное распределение — функция вероятности')
subplot(2,1,2)
histogram(bnm,round(sqrt(N)))
title('Биномиальное распределение — гистограмма')

example = binornd(n,p,[1 100]);
if (runstest(bnm) == 0)
    disp('Распределение случайно')
else
    disp('Распределение не случайно')
end
if (kstest2(bnm, example) == 0)
    disp('Распределение является биномиальным')
else
    disp('Распределение не является биномиальным')
end

end
