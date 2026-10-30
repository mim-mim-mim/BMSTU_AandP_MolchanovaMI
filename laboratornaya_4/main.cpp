#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int N;
    double Amax;
    double su = 0;
    srand(time(0));
    cout << "Лабораторная работа №4" << endl;
    cout << "Количество элементов N (5-30): ";
    cin >> N;
    if (N > 30) N = 30;
    else if (N < 5) N = 5;

    // Формирование массива: числа из диапазона [-5.0; 5.0]
    vector<double> mass(N);
    for (int i = 0; i < N; i++) {
        mass[i] = -5.0 + (double)rand() / RAND_MAX * 10.0;
    }
    cout << fixed << setprecision(3);
    cout << "Начальное состояние массива:" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(8) << mass[i] << " ";
    }
    cout << endl;

    // 1. Два максимальных по модулю элемента.
    // Пузырьковая сортировка по убыванию модуля выполняется
    // на копии, чтобы не нарушить порядок элементов mass.
    vector<double> tmp = mass;
    for (int k = N - 1; k > 0; k--) {
        bool flag = false;
        for (int i = 0; i < k; i++) {
            if (fabs(tmp[i]) < fabs(tmp[i + 1])) {
                swap(tmp[i], tmp[i + 1]);
                flag = true;
            }
        }
        if (flag == false) {
            break;
        }
    }

    // 2. Сумма элементов, модуль которых меньше единицы
    for (int i = 0; i < N; i++) {
        if (fabs(mass[i]) < 1.0) {
            su += mass[i];
        }
    }

    cout << "1. Два максимальных по модулю: "
         << tmp[0] << "; " << tmp[1] << endl;
    cout << "2. Сумма элементов с модулем < 1: "
         << su << endl;

    // 3. Обнуление элементов, модуль которых больше Amax
    cout << "Введите Amax: ";
    cin >> Amax;
    for (int i = 0; i < N; i++) {
        if (fabs(mass[i]) > Amax) {
            mass[i] = 0.0;
        }
    }

    // 4. Сжатие: ненулевые элементы - в начало (порядок
    // сохраняется), нулевые элементы - в конец массива
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (fabs(mass[i]) > 0.00001) {
            mass[j] = mass[i];
            j++;
        }
    }
    for (int i = j; i < N; i++) {
        mass[i] = 0.0;
    }

    cout << "Конечное состояние массива:" << endl;
    for (int i = 0; i < N; i++) {
        cout << setw(8) << mass[i] << " ";
    }
    cout << endl;
    return 0;
}