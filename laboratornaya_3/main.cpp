#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int factorial(int n){
    int res=1;
    for (int i=1; i<=n;i++){
        res=res*i;
    }
    return res;
}

int main(){
    setlocale(LC_ALL,"RU");
    cout<<"Лабораторная работа №3"<<endl;
    cout<<"ЗАДАНИЕ 1. Таблица значений функции"<<endl;
    double x1, x2, dx;
    cout<<"Введите Xнач: ";
    cin>>x1;
    cout<<"Введите Xкон: ";
    cin>>x2;
    cout<<"Введите шаг dx: ";
    cin>>dx;
    cout<<endl<<setw(10)<<"x"<<setw(15)<<"y"<<endl;
    cout<<"------------------------------"<<endl;
    double x = x1;
    while (x <= x2 + 1e-9){
        double y;
        if (x>=-7 && x<=-6){
            y=1;
        }
        else if (x>-6 && x<=-4){
            y=-0.5*x - 2;
        }
        else if (x>-4 && x<=0){
            y=sqrt(4- pow(x+2,2));
        }
        else if (x>0 && x<=1){
            y=sqrt(1-pow(x-1,2));
        }
        else if (x>1 && x<=2){
            y=x-1;
        }
        else {
            y=-2*x+5;
        }
        cout<<setw(10)<<fixed<<setprecision(3)<<x
             <<setw(15)<<setprecision(4)<<y<<endl;
        x += dx;
    }


    cout<<"\n===== ЗАДАНИЕ 2. Стрельба по мишени =====\n";
    double R;
    cout<<"Введите радиус R: ";
    cin>>R;
    srand(time(0)); // инициализация генератора

    for (int i=1; i<=10; i++){
        double a = (rand() % 2001 - 1000) / 1000.0 * R; // [-R, R]
        double b = (rand() % 2001 - 1000) / 1000.0 * R;

        bool c = (a*a + b*b) <= (R*R);
        bool c1 = (a>=0) && (b>=0) && (b>=a);
        bool c2 = (a<=0) && (b<=0) && (b>=a);
        bool c3 = c && (c1 || c2);

        cout<<"Выстрел "<<i<<": X="<<setprecision(2)<<a
             <<" Y="<<b<<" - ";
        if (c3){
            cout<<"Попадает"<<endl;
        }
        else {
            cout<<"Не попадает"<<endl;
        }
    }


    cout<<"\n===== ЗАДАНИЕ 3. Ряд Тейлора для e^(-x) =====\n";
    double Xn, Xk, dxx, eps;
    cout<<"Введите Xнач: "; cin>>Xn;
    cout<<"Введите Xкон: "; cin>>Xk;
    cout<<"Введите шаг dx: "; cin>>dxx;
    cout<<"Введите точность eps: "; cin>>eps;

    cout<<endl<<setw(10)<<"x"<<setw(15)<<"y"
         <<setw(10)<<"n"<<endl;
    cout<<"----------------------------------------"<<endl;

    x = Xn;
    while (x <= Xk + 1e-9){
        double a = 1.0;
        double sum = 1.0;
        int n = 0;
        do {
            n++;
            a = a * (-x) / n;
            sum += a;
        } while (fabs(a) >= eps);

        cout<<setw(10)<<fixed<<setprecision(3)<<x
             <<setw(15)<<setprecision(6)<<sum
             <<setw(10)<<n<<endl;
        x += dxx;
    }

    return 0;
}