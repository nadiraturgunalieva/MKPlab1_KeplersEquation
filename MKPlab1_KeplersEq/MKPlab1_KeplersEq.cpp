#include <iostream>
#include <cmath>

const double epsilon = 1e-10; // Точность вычислений

// Уравнение Кеплера
double keplerEquation(double E, double M, double e) {
    return E - e * sin(E) - M;
}

// Часть 1. Метод итераций
double eccentricAnomalyByIteration(double M, double e) {
    double E = M; // Нулевая итерация
    double diff;

    do {
        diff = (E - e * sin(E) - M) / (1 - e * cos(E));
        E -= diff;
    } while (fabs(diff) > epsilon);

    return E;
}

// Часть 2. Метод половинного деления
//double eccentricAnomalyByBisection(double M, double e) {
    //double a = 0.0;
    //double b = M;
    //double c;

    //do {
        //c = (a + b) / 2;
        //double fc = keplerEquation(c, M, e);

        //if (fc == 0) {
            //break;
        //}
        //else if (fc * keplerEquation(a, M, e) < 0) {
            //b = c;
        //}
        //else {
            //a = c;
        //}
    //} while (fabs(b - a) > 2 * epsilon || fabs(keplerEquation(c, M, e)) > epsilon);

    //return c;
//}

// Часть 3. Метод золотого сечения
//    double eccentricAnomalyByGoldenSection (double M, double e, double a, double b, double tolerance, int max_iterations) {
//     const double golden_ratio = (1 + sqrt(5)) / 2;
//     double E_a = a;
//     double E_b = b;
//     double x1 = E_b - (E_b - E_a) / golden_ratio;
//     double x2 = E_a + (E_b - E_a) / golden_ratio;
//     for (int i = 0; i < max_iterations; ++i) {
//         double f_x1 = x1 - e * sin(x1) - M;
//         double f_x2 = x2 - e * sin(x2) - M;
//         if (std::abs(E_b - E_a) < tolerance) {
//             return (E_a + E_b) / 2;
//         }
//         if (f_x1 < f_x2) {
//             E_b = x2;
//             x2 = x1;
//             x1 = E_b - (E_b - E_a) / golden_ratio;
//         }
//         else {
//             E_a = x1;
//             x1 = x2;
//             x2 = E_a + (E_b - E_a) / golden_ratio;
//         }
//     }
//     return -1;
// }

// Часть 4. Метод Ньютона
//double eccentricAnomalyByNewton(double M, double e) {
    //double E = 0.0; // Нулевая итерация

    //do {
        //double f = keplerEquation(E, M, e);
        //double df = 1 - e * cos(E);
        //E -= f / df;
    //} while (fabs(keplerEquation(E, M, e)) > epsilon);

    //return E;
//}

int main() {
    setlocale(LC_ALL, "RU");

    // Данные для уравнения Кеплера
    double M = 4.87 * pow(10, 24); // Средняя аномалия
    double e = 0.8276646992; // Эксцентриситет

    // Вычисление эксцентрической аномалии
    double E_iteration = eccentricAnomalyByIteration(M, e);
    //double E_bisection = eccentricAnomalyByBisection(M, e);
    //double E_goldenSection = eccentricAnomalyByGoldenSection(M, e);
    //double E_newton = eccentricAnomalyByNewton(M, e);

    // Вывод результатов
    std::cout << "Вычисление эксцентрической аномалии методом простых итераций: " << E_iteration << std::endl;
    //std::cout << "Вычисление эксцентрической аномалии методом половинного деления: " << E_bisection << std::endl;
    //std::cout << "Вычисление эксцентрической аномалии методом золотого сечения: " << E_goldenSection << std::endl;
    //std::cout << "Вычисление эксцентрической аномалии методом Ньютона: " << E_newton << std::endl;

    return 0;
}
