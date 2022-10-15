clc
clear all

A=[1.062          -3.212           0.537           4.307            4.117
   1.301          -1.662           1.649           2.372            3.469
   0.608          -4.669          -6.293           0.596            5.993
   2.985          -2.431          18.323           8.973            2.152
   0.326          -1.008          -4.243           2.340           10.741
   2.467          -2.821          13.752           7.178            2.424
  -0.219          -3.505         -17.488           2.708          -12.953
   2.840          -4.326          17.329           9.196            2.250
   1.799          -1.255          11.671           4.499            3.335
   0.280          -1.279         -11.426           3.150           11.610
   2.844          -2.419          13.806          10.913            1.891
   0.329          -2.465         -15.012           4.147            9.587
   2.398          -3.521           4.799           7.651            1.633
   1.107          -2.269           2.091           1.757            4.114
   0.603          -5.984          -6.848           2.260            5.985
  -1.215          -4.210         -24.452           5.650           -1.400
   3.073          -4.103          20.478          12.937            2.251
   2.516          -3.293          10.150           7.371            1.991
   1.747          -2.653           3.038           3.234            2.574
   1.159          -1.549           0.013           2.552            3.732
  -0.708          -3.275         -18.459           5.334           -3.072
   2.941          -3.042          21.258           9.662            2.504
   3.008          -1.332          12.526           8.755            1.542
   3.102          -3.950          13.961          11.131            1.561
   1.032          -3.692          -1.787           3.026            3.995
   1.517          -3.446           7.525           1.322            3.512
   1.190          -5.583           1.118           1.446            3.741
   0.324          -3.475          -8.101           2.764           10.415
   1.249          -3.272          -4.785           0.920            2.973
   2.543          -2.414          12.814           8.853            2.218
   3.777          -2.085          22.881          15.900            1.606
   0.470          -5.095         -13.782           3.589            6.834
   1.120          -3.852          -2.922           2.179            3.565
   0.691          -3.546          -9.721           2.519            4.977
   0.219          -4.335         -11.543           1.812           14.598
   0.562          -1.964          -8.812           2.285            6.192
   2.022          -1.754           7.841           6.218            2.546
   1.826          -4.253           2.544           4.699            2.372
   2.169          -2.687           7.184           5.505            2.233
   2.540          -2.652          16.254           7.000            2.567
   1.606          -1.778          -0.144           5.255            2.547
   1.461          -0.400          -1.066           3.924            2.785
   0.353          -3.768         -11.985           1.753            9.255
   0.780          -1.794          -4.587           2.422            4.907
   0.426          -4.937         -13.081           2.485            7.602
  -0.080          -3.433         -17.209           2.996          -36.648
  -0.799          -1.373         -17.999           6.058           -2.454
   3.353          -0.195          19.833          14.467            1.826
   2.041          -1.053           9.893           4.561            2.719
   0.576          -3.960          -3.778           2.177            6.553
   1.525          -3.366          -1.506           3.301            2.592
   2.193          -2.034          12.111           4.900            2.686
   0.519          -2.251          -3.250           1.201            7.239
   1.523          -2.237          -0.575           3.900            2.689
   1.546          -3.391           4.464           1.900            3.141
   1.872          -1.683           7.594           6.027            2.789
   1.208          -2.869          -0.764           2.600            3.498
  -1.634          -3.416         -33.640          11.436           -1.266
   1.758          -3.102           7.819           4.687            3.031
   2.614          -2.805          15.500           7.886            2.384
   1.584          -6.259           1.583           2.099            2.767
   3.784          -7.646          28.901          18.163            2.199
   3.964           0.691          22.100          17.041            1.302
   3.210          -3.253          17.855          10.951            1.809
   1.599          -2.762           4.822           3.254            3.059
   3.051          -4.122          17.450          11.491            1.977
   3.212          -3.532          25.746          11.198            2.597
   2.732          -4.199          19.316           9.436            2.598
   2.053          -3.008           8.372           4.563            2.546
   4.873          -1.531          36.956          28.595            1.738
   1.813          -2.588          -1.786           4.873            1.963
   1.519          -3.759           1.673           4.096            2.924
   0.940          -2.845           3.122           3.240            4.865
   0.460          -4.072          -4.883           2.037            7.873
   3.436          -3.866          24.882          14.174            2.226];


disp('------------------- КОРРЕЛЯЦИОННЫЙ АНАЛИЗ -------------------')
fprintf('\n')
disp('Корреляционная матрица: ')
fprintf('\n')

Corr_Matrix = corr(A);
disp(Corr_Matrix)

fprintf('\n')
disp('Частные коэффициенты корреляции для первого и остальных столбцов:')
fprintf('\n')

P11 = Corr_Matrix; P11(1,:) = []; P11(:,1) = [];
P22 = Corr_Matrix; P22(2,:) = []; P22(:,2) = [];
P33 = Corr_Matrix; P33(3,:) = []; P33(:,3) = [];
P44 = Corr_Matrix; P44(4,:) = []; P44(:,4) = [];
P55 = Corr_Matrix; P55(5,:) = []; P55(:,5) = [];
 
P12 = Corr_Matrix * (-1)^(1+2); P12(1,:) = []; P12(:,2) = [];
P13 = Corr_Matrix * (-1)^(1+3); P13(1,:) = []; P13(:,3) = [];
P14 = Corr_Matrix * (-1)^(1+4); P14(1,:) = []; P14(:,4) = [];
P15 = Corr_Matrix * (-1)^(1+5); P15(1,:) = []; P15(:,5) = [];

R12 = -(det(P12) / (sqrt(det(P11)*det(P22))))
R13 = -(det(P13) / (sqrt(det(P11)*det(P33))))
R14 = -(det(P14) / (sqrt(det(P11)*det(P44))))
R15 = -(det(P15) / (sqrt(det(P11)*det(P55))))

fprintf('\n')
disp('Множественные коэффициенты корреляции: ')
fprintf('\n')

T1 = sqrt(1 - det(Corr_Matrix) / det(P11))
T2 = sqrt(1 - det(Corr_Matrix) / det(P22))
T3 = sqrt(1 - det(Corr_Matrix) / det(P33))
T4 = sqrt(1 - det(Corr_Matrix) / det(P44))
T5 = sqrt(1 - det(Corr_Matrix) / det(P55))

fprintf('\n')
disp('Ранговые коэффициенты корреляции по Спирмену для первого и остальных столбцов:')
fprintf('\n')

n = 75;
%---------------------------------------------------
[NRSort NRIndex] = sort(A(:,1));
R1 = zeros(1,n);
i = 1;

while (i <= n)
    start = i;
    Numerator = i;
    Denumerator = 1;
    while ((i < n) && (NRSort(i) == NRSort(i+1)))
        Denumerator = Denumerator + 1;
        Numerator = Numerator + i + 1;
        i = i + 1;
    end
    for k = start : i
        R1(NRIndex(k)) = Numerator/Denumerator;
    end
    i = i + 1;
end
%---------------------------------------------------
[NRSort NRIndex] = sort(A(:,2));
R2 = zeros(1,n);
i = 1;

while (i <= n)
    start = i;
    Numerator = i;
    Denumerator = 1;
    while (i < n && NRSort(i) == NRSort(i+1))
        Denumerator = Denumerator + 1;
        Numerator = Numerator + i + 1;
        i = i + 1;
    end
    for k = start : i
        R2(NRIndex(k)) = Numerator/Denumerator;
    end
    i = i + 1;
end
%---------------------------------------------------
[NRSort NRIndex] = sort(A(:,3));
R3 = zeros(1,n);
i = 1;

while (i <= n)
    start = i;
    Numerator = i;
    Denumerator = 1;
    while (i < n && NRSort(i) == NRSort(i+1))
        Denumerator = Denumerator + 1;
        Numerator = Numerator + i + 1;
        i = i + 1;
    end
    for k = start : i
        R3(NRIndex(k)) = Numerator/Denumerator;
    end
    i = i + 1;
end
%---------------------------------------------------
[NRSort NRIndex] = sort(A(:,1));
R4 = zeros(1,n);
i = 1;

while (i <= n)
    start = i;
    Numerator = i;
    Denumerator = 1;
    while (i < n && NRSort(i) == NRSort(i+1))
        Denumerator = Denumerator + 1;
        Numerator = Numerator + i + 1;
        i = i + 1;
    end
    for k = start : i
        R4(NRIndex(k)) = Numerator/Denumerator;
    end
    i = i + 1;
end
%---------------------------------------------------
[NRSort NRIndex] = sort(A(:,1));
R5 = zeros(1,n);
i = 1;

while (i <= n)
    start = i;
    Numerator = i;
    Denumerator = 1;
    while (i < n && NRSort(i) == NRSort(i+1))
        Denumerator = Denumerator + 1;
        Numerator = Numerator + i + 1;
        i = i + 1;
    end
    for k = start : i
        R5(NRIndex(k)) = Numerator/Denumerator;
    end
    i = i + 1;
end

##R1
##R2
##R3
##R4
##R5

Ar = ranks(A);

A12 = Ar(:,1) - Ar(:,2);
A13 = Ar(:,1) - Ar(:,3);
A14 = Ar(:,1) - Ar(:,4);
A15 = Ar(:,1) - Ar(:,5);

Rs12 = 1 - ((6*sum(A12.^2)) / (n*(n^2-1)))
Rs13 = 1 - ((6*sum(A13.^2)) / (n*(n^2-1)))
Rs14 = 1 - ((6*sum(A14.^2)) / (n*(n^2-1)))
Rs15 = 1 - ((6*sum(A15.^2)) / (n*(n^2-1)))

fprintf('\n')
disp('...табличное значение при n = 75 rs = 2 при уровне значимости 0,05')
fprintf('\n')

fprintf('\n')
disp('Корреляционное отношение для первого и остальных столбцов:')
fprintf('\n')

ob_disp12 = (sum(A(:,1).^2)+sum(A(:,2).^2))/(2*n) - ((sum(A(:,1))+sum(A(:,2)))/(2*n)).^2;
ob_disp13 = (sum(A(:,1).^2)+sum(A(:,3).^2))/(2*n) - ((sum(A(:,1))+sum(A(:,3)))/(2*n)).^2;
ob_disp14 = (sum(A(:,1).^2)+sum(A(:,4).^2))/(2*n) - ((sum(A(:,1))+sum(A(:,4)))/(2*n)).^2;
ob_disp15 = (sum(A(:,1).^2)+sum(A(:,5).^2))/(2*n) - ((sum(A(:,1))+sum(A(:,5)))/(2*n)).^2;

Yob12 = (mean(A(:,1))*n+mean(A(:,2))*n) / (2*n);
Yob13 = (mean(A(:,1))*n+mean(A(:,3))*n) / (2*n);
Yob14 = (mean(A(:,1))*n+mean(A(:,4))*n) / (2*n);
Yob15 = (mean(A(:,1))*n+mean(A(:,5))*n) / (2*n);

fact_disp12 = (((mean(A(:,1))-Yob12).^2)*n+((mean(A(:,2))-Yob12).^2)*n) / (2*n);
fact_disp13 = (((mean(A(:,1))-Yob13).^2)*n+((mean(A(:,3))-Yob13).^2)*n) / (2*n);
fact_disp14 = (((mean(A(:,1))-Yob14).^2)*n+((mean(A(:,4))-Yob14).^2)*n) / (2*n);
fact_disp15 = (((mean(A(:,1))-Yob15).^2)*n+((mean(A(:,5))-Yob15).^2)*n) / (2*n);

nu12 = sqrt(fact_disp12/ob_disp12)
nu13 = sqrt(fact_disp13/ob_disp13)
nu14 = sqrt(fact_disp14/ob_disp14)
nu15 = sqrt(fact_disp15/ob_disp15)

fprintf('\n')
disp('... 0.1 – 0.3 - Слабая 0.3 – 0.5 Умеренная 0.5 – 0.7 - Заметная 0.7 – 0.9 - Тесная 0.9 – 0.99 - Весьма тесная')
fprintf('\n')

fprintf('\n')
disp('~~~ ПРОВЕРКИ НА ЗНАЧИМОСТЬ ~~~')
fprintf('\n')

##for i = 1:5
##for j = 1:5
##   Tp(i,j) = Corr_Matrix(i,j)*sqrt(n-2)/(sqrt(1-(Corr_Matrix(i,j))^2));
##end
##end
##Tp

fprintf('\n')
disp('Частные коэффициенты корреляции:')
fprintf('\n')

alpha = 0.01;
k = 5;
n = 75;
Tkr1 = tinv(1-alpha,n-k);
disp('Распеределение Стьюдента:')
disp(Tkr1)
fprintf('\n')

Tp_R12 = R12*sqrt(n-k)/(sqrt(1-(R12)^2)) 
if abs(Tp_R12) > Tkr1
    fprintf('(значимый)\n')
end

Tp_R13 = R13*sqrt(n-k)/(sqrt(1-(R13)^2)) 
if abs(Tp_R13) > Tkr1
    fprintf('(значимый)\n')
end

Tp_R14 = R14*sqrt(n-k)/(sqrt(1-(R14)^2))
if abs(Tp_R14) > Tkr1
    fprintf('(значимый)\n')
end

Tp_R15 = R15*sqrt(n-k)/(sqrt(1-(R15)^2)) 
if abs(Tp_R15) > Tkr1
    fprintf('(значимый)\n')
end


fprintf('\n')
disp('Множественные коэффициенты корреляции:')
fprintf('\n')

Tkr2 = finv(1-alpha,k-1,n-k);
disp('Распределение Фишера: ')
disp(Tkr2)
fprintf('\n')

Tp_T1 = (T1^2*58)/((1-T1^2)*1) 
if abs(Tp_T1) > Tkr2
    fprintf('(значимый)\n')
end

Tp_T2 = (T2^2*58)/((1-T2^2)*1)
if abs(Tp_T2) > Tkr2
    fprintf('(значимый)\n')
end

Tp_T3 = (T3^2*58)/((1-T3^2)*1)
if abs(Tp_T3) > Tkr2
    fprintf('(значимый)\n')
end

Tp_T4 = (T4^2*58)/((1-T4^2)*1)
if abs(Tp_T4) > Tkr2
    fprintf('(значимый)\n')
end

Tp_T5 = (T5^2*58)/((1-T5^2)*1)
if abs(Tp_T5) > Tkr2
    fprintf('(значимый)\n')
end

fprintf('\n')
disp('Ранговые коэффициенты корреляции:')
fprintf('\n')

Tkr3=norminv(0.975,0,1);
disp('Стандартное нормальное распределение: ')
disp(Tkr3)
fprintf('\n')

Tp_Rs12 = Rs12*sqrt(59)
if abs(Tp_Rs12)>(Tkr3)
     fprintf('(значимый)\n')
end
Tp_Rs13 = Rs13*sqrt(59)
if abs(Tp_Rs13) > Tkr3
     fprintf('(значимый)\n')
end
Tp_Rs14 = Rs14*sqrt(59)
if abs(Tp_Rs14) > Tkr3
     fprintf('(значимый)\n')
end
Tp_Rs15 = Rs15*sqrt(59)
if abs(Tp_Rs15) > Tkr3
     fprintf('(значимый)\n')
end

fprintf('\n\n')
disp('------------------- РЕГРЕССИОННЫЙ АНАЛИЗ -------------------')

data1 = A(:,1);
data2 = A(:,2);
data3 = A(:,3);
data4 = A(:,4);
data5 = A(:,5);

fprintf('\n~~~~ 1 и 2 выборки ~~~~\n')
coef = polyfit(data1,data2,1);
fprintf('b0 = %3.3f, b1 = %3.3f\n\n', coef(2), coef(1))

fprintf('Качество аппроксимации:\n')
Q1 = 0;
for i = 1:n
   Q1 = Q1 + (data2(i)-coef(2)-coef(1)*data1(i)).^2; % Остаточная сумма квадратов 
end
fprintf('Q1 = %3.3f\n',Q1)
S = Q1/(n-2);
fprintf('S^2 = %3.3f\n\n',S)

fprintf('Значимость:\n')
sum = 0;
for i=1:n
   sum = sum + (data1(i)-mean(data1)).^2;
end
t = (coef(1).^2*sum)/S;
if t < finv(0.95,1,n-2)
   fprintf('Модель не значима\n\n')
else
   fprintf('Модель значима\n\n')
end

fprintf('Адекватность:\n')
L = load('regress_analysis.TXT');
data_L1 = L(:,1);
data_L2 = L(:,2);
l = length(data_L1);
lni = 1;
Q2 = 0;
while lni < l
   X = data_L1(lni);
   sum = 0;
   ni = 0;
   for j = 1:l
      if X == data_L1(j)
         sum = sum + data_L2(j);
         ni = ni + 1;
      end
   end
   lni = lni + ni;
   y_mid = sum / ni;
   yi = coef(2) + coef(1)*X;
   Q2 = Q2 + ni*((y_mid-yi).^2);
end
fprintf('Q2 = %3.3f\n',Q2)
Q3 = Q1 - Q2;
fprintf('Q3 = %3.3f\n', Q3)
m = length(unique(data_L1))
t = (Q2*(n-m))/((m-2)*Q3)
if t < finv(0.95,m-2,n-m) % распределение Фишера 
   fprintf('Модель адекватна\n\n')
else
   fprintf('Модель не адекватна\n\n')
end

fprintf('\n~~~~ 1 и 3 выборки ~~~~\n')
coef=polyfit(data1,data3,1);
fprintf('b0 = %3.3f, b1 = %3.3f\n\n', coef(2), coef(1))

fprintf('Качество аппроксимации:\n')
Q1 = 0;
for i = 1:n
   Q1 = Q1 + (data3(i)-coef(2)-coef(1)*data1(i)).^2; 
end
fprintf('Q1 = %3.3f\n',Q1)
S = Q1/(n-2);
fprintf('S^2 = %3.3f\n\n', S)

disp('Значимость:\n')
sum = 0;
for i=1:n
   sum = sum + (data1(i)-mean(data1)).^2;
end
t = (coef(1).^2*sum)/S;
if t < finv(0.95,1,n-2)
   fprintf('Модель не значима\n\n')
else
   fprintf('Модель значима\n\n')
end

fprintf('Адекватность:\n')
L = load('regress_analysis.TXT');
data_L1 = L(:,1);
data_L3 = L(:,3);
l = length(data_L1);
lni = 1;
Q2 = 0;
while lni < l
   X = data_L1(lni);
   sum = 0;
   ni = 0;
   for j = 1:l
      if X == data_L1(j);
         sum = sum + data_L3(j);
         ni = ni + 1;
      end
   end
   lni = lni+ni;
   y_mid = sum/ni;
   yi = coef(2) + coef(1)*X;
   Q2 = Q2 + ni*((y_mid-yi).^2);
end
fprintf('Q2 = %3.3f\n',Q2)
Q3 = Q1 - Q2;
fprintf('Q3 = %3.3f\n', Q3)
m = length(unique(data_L1))
t = (Q2*(n-m))/((m-2)*Q3)
if t < finv(0.95,m-2,n-m)
   fprintf('Модель адекватна\n\n')
else
   fprintf('Модель не адекватна\n\n')
end

fprintf('\n~~~~ 1 и 4 выборки ~~~~\n')
coef = polyfit(data1,data4,5);
fprintf('b0 = %3.3f\n b1 = %3.3f\n b2 = %3.3f\n b3 = %3.3f\n b4 = %3.3f\n b5 = %3.3f\n\n',coef(6),coef(5),coef(4),coef(3), coef(2), coef(1))

fprintf('Качество аппроксимации:\n')
Q1 = 0;
for i = 1:n
   Q1 = Q1 + power((data4(i)-coef(1)*data1(i).^5-coef(2)*data1(i).^4-coef(3)*data1(i).^3-coef(4)*data1(i).^2-coef(5)*data1(i)-coef(6)),2) ;
end
fprintf('Q1 = %3.3f\n',Q1)
S = Q1/(n-2);
fprintf('S^2 = %3.3f\n\n', S)

fprintf('Значимость:\n')
sum = 0;
for i = 1:n
   sum = sum + (data1(i)-mean(data1)).^2;
end
t = (coef(1).^2*sum) / S;
if t < finv(0.95,1,n-2)
   fprintf('Модель не значима\n\n')
else
   fprintf('Модель значима\n\n')
end

fprintf('Адекватность:\n')
L = load('regress_analysis.TXT');
data_L1 = L(:,1);
data_L4 = L(:,4);
l = length(data_L1);
lni = 1;
Q2 = 0;
while lni < l
   X = data_L1(lni);
   sum = 0;
   ni = 0;
   for j = 1:l
      if X == data_L1(j)
         sum = sum + data_L4(j);
         ni = ni + 1;
      end
   end
   
   lni = lni + ni;
   y_mid = sum / ni;
   yi = data4(i)-coef(1)*X.^5-coef(2)*X.^4-coef(3)*X.^3-coef(4)*X.^2-coef(5)*X-coef(6);
   Q2 = Q2 + ni*((y_mid-yi).^2);
end
fprintf('Q2 = %3.3f\n',Q2)
while lni < l
   X = data_L1(lni);
   sum = 0;
   ni = 0;
   for j = 1:l
      if X == data_L1(j)
         sum = sum + data_L4(j);
         ni = ni + 1;
      end
   end
   
   lni = lni + ni;
   y_mid = sum / ni;
   Q3 = 0;
   for j = 1:l
      if X == data_L1(j)
         Q3 = Q3 + (data_L4(j)-y_mid).^2;
         ni = ni + 1;
      end
   end
end
fprintf('Q3 = %3.3f\n', Q3)
m = length(unique(data_L1))
t = (Q2*(n-m)) / ((m-2)*Q3)
if t < finv(0.95,m-2,n-m)
   fprintf('Модель адекватна\n\n')
else
   fprintf('Модель не адекватна\n\n')
end

fprintf('\n~~~~ 1 и 5 выборки ~~~~\n')
coef = polyfit(data1,data5,5);
fprintf('b0 = %3.3f\n b1 = %3.3f\n b2 = %3.3f\n b3 = %3.3f\n b4 = %3.3f\n b5 = %3.3f\n\n',coef(6),coef(5),coef(4),coef(3), coef(2), coef(1))

fprintf('Качество аппроксимации:\n')
Q1 = 0;
for i = 1:n
    Q1 = Q1 + power((data5(i)-coef(1)*data1(i).^5-coef(2)*data1(i).^4-coef(3)*data1(i).^3-coef(4)*data1(i).^2-coef(5)*data1(i)-coef(6)),2) ;
end
fprintf('Q1 = %3.3f\n',Q1)
S = Q1/(n-2);
fprintf('S^2 = %3.3f\n\n', S)

fprintf('Значимость:\n')
sum = 0;
for i = 1:n
   sum = sum + (data1(i)-mean(data1)).^2;
end
t = (coef(1).^2*sum) / (S.^2);
if t < finv(0.95,1,n-2)
   fprintf('Модель не значима\n\n')
else
   fprintf('Модель значима\n\n')
end

fprintf('Адекватность:\n')
L = load('regress_analysis.TXT');
data_L1 = L(:,1);
data_L5 = L(:,5); 
l = length(data_L1);
lni = 1;
Q2 = 0;
while lni < l
   X = data_L1(lni);
   sum = 0;
   ni = 0;
   for j = 1:l
      if X == data_L1(j)
         sum = sum + data_L5(j);
         ni = ni + 1;
      end
   end
   lni = lni + ni;
   y_mid = sum / ni;
   yi = coef(1)*X.^5+coef(2)*X.^4+coef(3)*X.^3+coef(4)*X.^2+coef(5)*X+coef(6);
   Q2 = Q2 + ni*((y_mid-yi).^2);
end
fprintf('Q2 = %3.3f\n',Q2)
while lni < l
   X = data_L1(lni);
   sum = 0;
   ni = 0;
   for j = 1:l
      if X == data_L1(j)
         sum = sum + data_L5(j);
         ni = ni + 1;
      end
   end
   lni = lni + ni;
   y_mid = sum / ni;
   Q3 = 0;
   for j = 1:l
      if X == data_L1(j)
         Q3 = Q3 + (data_L5(j)-y_mid).^2;
      end
   end
end
fprintf('Q3 = %3.3f\n', Q3)
m = length(unique(data_L1))
t = (Q2*(n-m))/((m-2)*Q3)
if t < finv(0.95,m-2,n-m) 
   fprintf('Модель адекватна\n\n')
else
   fprintf('Модель не адекватна\n\n')
end