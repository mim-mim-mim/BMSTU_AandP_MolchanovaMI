#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

// функции для лабы 5
float** MakeMatr(int n, int m) {
    float** mass = new float* [n];
    for (int i = 0; i < n; i++) {
        mass[i] = new float[m];
        for (int j = 0; j < m; j++) {
            mass[i][j] = rand() % 15 - 7;
        }
    }
    return mass;
}

void PrintMatr(float** mass, int n, int m, ofstream& out) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << setw(8) << mass[i][j];
        }
        out << endl;
    }
}

float Midle(float** mass, int n, int m) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += mass[i][j];
        }
    }
    return s / (n * m);
}

float Disp(float** mass, int n, int m, float midl) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            s += pow(mass[i][j] - midl, 2);
        }
    }
    return s / (n * m - 1);
}

void CorrectMatr(float** mass, int n, int m, float midl, float sigma) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fabs(mass[i][j] - midl) > sigma) {
                mass[i][j] = midl;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    // ================= ЛАБОРАТОРНАЯ 1 ==============================
    {
        ifstream fin("lab1_in.txt");
        ofstream fout("lab1_out.txt");
        if (fin.is_open() && fout.is_open()) {
            double b, b2;
            fin >> b >> b2;

            fout << "Лабораторная работа №1" << endl;

            if (b >= 2) {
                double z1 = sqrt(2 * b + 2 * sqrt(b * b - 4)) / (sqrt(b * b - 4) + b + 2);
                fout << "z1 = " << z1 << endl;
            }
            else {
                fout << "z1 не определена" << endl;
            }

            if (b2 > -2) {
                double z2 = 1 / sqrt(b2 + 2);
                fout << "z2 = " << z2 << endl;
            }
            else {
                fout << "z2 не определена" << endl;
            }

            fin.close();
            fout.close();
        }
    }

    // ================ ЛАБОРАТОРНАЯ 4 ==============
    {
        ifstream fin("lab4_in.txt");
        ofstream fout("lab4_out.txt");
        if (fin.is_open() && fout.is_open()) {
            int N;
            double Amax;
            fin >> N >> Amax;

            if (N > 30) {
                N = 30;
            }
            else if (N < 5) {
                N = 5;
            }

            srand(time(0));

            double* mass = new double[N];
            for (int i = 0; i < N; i++) {
                mass[i] = -5.0 + (double)rand() / RAND_MAX * 10.0;
            }

            fout << fixed << setprecision(3);
            fout << "Начальный массив:" << endl;
            for (int i = 0; i < N; i++) {
                fout << setw(8) << mass[i];
            }
            fout << endl;

            // 1. 2 макс по модулю эл-та
            double* mass2 = new double[N];
            for (int i = 0; i < N; i++) {
                mass2[i] = mass[i];
            }

            for (int k = N - 1; k > 0; k--) {
                bool flag = false;
                for (int i = 0; i < k; i++) {
                    if (fabs(mass2[i]) < fabs(mass2[i + 1])) {
                        swap(mass2[i], mass2[i + 1]);
                        flag = true;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            fout << "1. Два максимальных по модулю: " << mass2[0] << "; " << mass2[1] << endl;

            // 2. сумма х< 1
            double su = 0;
            for (int i = 0; i < N; i++) {
                if (fabs(mass[i]) < 1.0) {
                    su += mass[i];
                }
            }
            fout << "2. Сумма элементов с модулем < 1: " << su << endl;

            // 3. обнуление x большего Amax
            for (int i = 0; i < N; i++) {
                if (fabs(mass[i]) > Amax) {
                    mass[i] = 0;
                }
            }

            // 4. сжатие
            int j = 0;
            for (int i = 0; i < N; i++) {
                if (fabs(mass[i]) > 0.00001) {
                    mass[j++] = mass[i];
                }
            }
            for (int i = j; i < N; i++) {
                mass[i] = 0;
            }

            fout << "Конечный массив:" << endl;
            for (int i = 0; i < N; i++) {
                fout << setw(8) << mass[i];
            }
            fout << endl;

            // очистка памти
            delete[] mass;
            delete[] mass2;
            fin.close();
            fout.close();
        }
    }

    // ================= ЛАБОРАТОРНАЯ 5 =================
    {
        ifstream fin("lab5_in.txt");
        ofstream fout("lab5_out.txt");
        if (fin.is_open() && fout.is_open()) {
            int n, m;
            fin >> n >> m;
            fin.close();

            srand(time(0));
            float** mass = MakeMatr(n, m);

            fout << fixed << setprecision(4);
            fout << "Исходная матрица:" << endl;
            PrintMatr(mass, n, m, fout);

            float midl = Midle(mass, n, m);
            float disp = Disp(mass, n, m, midl);
            float sigma = sqrt(disp);

            fout << "Среднее = " << midl << endl;
            fout << "Дисперсия = " << disp << endl;
            fout << "Сигма = " << sigma << endl;

            CorrectMatr(mass, n, m, midl, sigma);

            fout << "После коррекции:" << endl;
            PrintMatr(mass, n, m, fout);

            // очистка памяти
            for (int i = 0; i < n; i++) {
                delete[] mass[i];
            }
            delete[] mass;

            fout.close();
        }
    }

    return 0;
}