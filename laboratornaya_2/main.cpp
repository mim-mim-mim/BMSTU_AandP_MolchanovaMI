#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    cout << "Лабораторная работа 2. Вариант 15" << endl;
    double x, y = 0;
    bool defined = true;
    cout << "Введите параметр x: ";
    cin >> x;
    if (x >= -7 && x <= -6) {
        y = 1;
    }
    else if (x > -6 && x <= -4) {
        y = -0.5 * x - 2;
    }
    else if (x > -4 && x <= 0) {
        y = sqrt(4 - pow(x + 2, 2));
    }
    else if (x > 0 && x <= 2) {
        y = -sqrt(1 - pow(x - 1, 2));
        if (fabs(y) < 1e-12) y = 0;
    }
    else if (x > 2 && x <= 3) {
        y = -x + 2;
    }
    else {
        defined = false;
    }
    cout << fixed;
    if (defined) {
        cout << "Значение функции: y=" << setprecision(4)
            << y << endl;
    }
    else {
        cout << "Функция не определена для x=" << x << endl;
    }

    // Задание 2: попадание точки в область
    double R, a, b;
    cout << endl;
    cout << "Задание 2. Попадание точки в область" << endl;
    cout << "Введите радиус R: ";
    cin >> R;
    cout << "Введите координаты точки X и Y: ";
    cin >> a >> b;
    bool c1 = (a >= 0) && (b <= 0) && (a * a + b * b <= R * R);
    bool c2 = (a >= -R) && (a <= 0) && (b >= 0) && (b <= R) && ((a + R) * (a + R)+ (b - R) * (b - R) >= R * R);
    bool c3 = c1 || c2;
    cout << "Точка X=" << setprecision(2) << a
         << " Y=" << b;
    if (c3) {
        cout << " попадает в область." << endl;
    }
    else {
        cout << " не попадает в область." << endl;
    }
    return 0;
}
