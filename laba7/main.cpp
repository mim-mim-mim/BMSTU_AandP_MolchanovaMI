/*Рекурсивная степень: power(a, n) за O(log
n) через возведение в квадрат.
Дополнительно: сравнить с наивной
версией по числу умножений.*/
#include <iostream>
using namespace std;
int cnt = 0;
long double power (int a,int n) {
    if (n == 0) {
        return 1;
    }
    if (n%2==0) {
        cnt++;
        return power(a * a, n / 2);
    }
    else{
        cnt++;
        return a*power(a * a, (n - 1)/2);
    }
}
int main() {
    setlocale(LC_ALL, "RU");
    int a, n;

    cout << "Введите число(основание степени): "; cin >> a;
    int b = 1;
    cout << "Введите число (показатель степени):"; cin >> n;
    cout <<"Число "<<a<<" в степени "<<n<<" => " << power(a, n)<<endl;
    cout << "==============ПРОВЕРКА (наивная версия)==============" << endl;
    for (int i = 0; i < n; i++) {
        b *= a;
    }
    cout << "Число " << a << " в степени " << n << " => " <<b<< endl;
    cout << "Кол-во итераций для ускоренного варианта: " << cnt<<endl;
    cout << "Кол-во итераций для 'наивного' варианта: " << n << endl;
}