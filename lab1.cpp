#include <iostream>
#include <cmath>
using namespace std; 

double ploshad(double a, double b, double h) { 
    return (a + b) * h / 2; 
}

double perimetr(double a, double b, double c, double d) {
    return a + b + c + d;
}

double srednLin(double a, double b) {
    return (a + b) / 2;
}

double vvod(const char* text) {
    double x;
    
    while (true) {
        cout << text;
        
        if (cin >> x) {
            break;
        } else {
            cout << "Ошибка! Введите число: ";
            cin.clear(); 
            cin.ignore(100, '\n');
        }
    }
    
    return x;
}

bool proverka(double a, double b, double c, double d, double h) {
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0 || h <= 0) {
        cout << "Ошибка все стороны и высота должны быть положительными\n";
        return false;
    }
    if (a >= b) {
        cout << "Ошибка! Верхнее основание должно быть меньше нижнего!\n";
        return false;
    }
    if (h >= c || h >= d) {
        cout << "Ошибка! Высота должна быть меньше боковых сторон!\n";
        return false;
    }
    double proekciyaC = sqrt(c*c - h*h);
    double proekciyaD = sqrt(d*d - h*h);
    double raznosti = b - a;
    
    if (abs(proekciyaD + proekciyaC - raznosti) > 0.001) {
        cout << "\nОшибка! Трапеция с такими параметрами не существует!\n";
        cout << "Объяснение: Из вершин верхнего основания опускаем высоты.\n";
        cout << "Получаем два прямоугольных треугольника.\n";
        cout << "Их катеты (проекции) должны в сумме давать разность оснований.\n";
        cout << "Проекция левой стороны = " << proekciyaC << endl;
        cout << "Проекция правой стороны = " << proekciyaD << endl;
        cout << "Их сумма = " << proekciyaC + proekciyaD << endl;
        cout << "Разность оснований (b-a) = " << raznosti << endl;
        cout << "Эти числа должны быть равны!\n";
        return false;
    }
    
    return true;
}

int main() {
    double a, b, c, d, h;
    
    cout << "Введите данные для трапеции:\n";
    do {
        a = vvod("Верхнее основание (a): ");
        b = vvod("Нижнее основание (b): ");
        c = vvod("Левая боковая сторона (c): ");
        d = vvod("Правая боковая сторона (d): ");
        h = vvod("Высота (h): ");
        
        if (!proverka(a, b, c, d, h)) {
            cout << "\nПопробуйте ввести данные заново:\n";
            cout << "--------------------------------\n";
        }
        
    } while (!proverka(a, b, c, d, h));
    cout << "Результаты:\n";
    cout << "Площадь = " << ploshad(a, b, h) << endl;
    cout << "Периметр = " << perimetr(a, b, c, d) << endl;
    cout << "Средняя линия = " << srednLin(a, b) << endl;
    
    return 0;
}