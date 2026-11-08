/*Вариант 15
Дана целочисленная прямоугольная матрица. Определить номер первого из столбцов, содержащих хотя бы один нулевой элемент.
Переставляя строки заданной матрицы, расположить их в соответствии с убыванием характеристик.
ПРИМЕЧАНИЕ: характеристикой строки целочисленной матрицы назовём сумму её отрицательных чётных элементов.
*/
#include<iostream>
#include<cmath>
int found(int** mass, int m, int n, bool flag = false) {
    using namespace std;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mass[i][j] == 0) {
                flag = true;
                cout << "Столбец с первым нулевым элементом:" << j + 1;
                break;
            }
        }
    }
    cout << "Нулевой элемент не найден" << endl;
    return 0;
}
//cумма отриц четных эл-тов строки
int Sum_otr_el(int* mass, int n) {
    int su = 0;
    for (int j = 0; j < n; j++) {
        if (mass[j] < 0 && mass[j] % 2 == 0) {
            su += mass[j];
        }
    }
    return su;
}
int main()
{
    setlocale(LC_ALL, "RU");
    int m, n;
    using namespace std;
    cout << "Введите кол-во строк:"; cin >> m;
    cout << "Введите кол-во столбцов:"; cin >> n;
    int** mass = new int* [m];
    for (int i = 0; i < m; i++) {
        mass[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mass[i][j];
        }
    }
    //вывод масс
    cout << "Исходный массив" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
    //первый нулевой столбец
    found(mass, m, n);

    // сортировка строк по убыванию характеристик
    for (int i = 0; i < m - 1; i++) {
        int maxIdx = i;
        int maxHar = Sum_otr_el(mass[i], n);
        for (int k = i + 1; k < m; k++) {
            int h = Sum_otr_el(mass[k], n);
            if (h > maxHar) {
                maxHar = h;
                maxIdx = k;
            }
        }
        if (maxIdx != i) {
            int* tmp = mass[i];
            mass[i] = mass[maxIdx];
            mass[maxIdx] = tmp;
        }
    }

    cout << "Массив после сортировки строк:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mass[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}