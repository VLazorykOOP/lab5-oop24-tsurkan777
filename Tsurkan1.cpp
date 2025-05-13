#include <iostream>
#include <cmath>

class Triad {
protected:
    double a, b, c;

public:
    Triad(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c) {}

    void setValues(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double sum() const {
        return a + b + c;
    }

    void print() const {
        std::cout << "Трійка чисел: " << a << ", " << b << ", " << c << "\n";
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
};

class Triangle : public Triad {
public:
    Triangle(double a = 1, double b = 1, double c = 1) : Triad(a, b, c) {}

    bool isValid() const {
        return a + b > c && a + c > b && b + c > a;
    }

    double area() const {
        if (!isValid()) return 0;
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void angles(double& A, double& B, double& C) const {
        if (!isValid()) {
            A = B = C = 0;
            return;
        }
        A = acos((b*b + c*c - a*a) / (2 * b * c)) * 180.0 / M_PI;
        B = acos((a*a + c*c - b*b) / (2 * a * c)) * 180.0 / M_PI;
        C = 180.0 - A - B;
    }

    void print() const {
        if (!isValid()) {
            std::cout << "Це не трикутник!\n";
            return;
        }

        std::cout << "Сторони трикутника: " << a << ", " << b << ", " << c << "\n";
        std::cout << "Площа: " << area() << "\n";

        double A, B, C;
        angles(A, B, C);
        std::cout << "Кути (в градусах): A = " << A << ", B = " << B << ", C = " << C << "\n";
    }
};

int main() {
    system("chcp 65001");
    Triad t(3, 4, 5);
    t.print();
    std::cout << "Сума: " << t.sum() << "\n\n";

    Triangle tr(3, 4, 5);
    tr.print();

    std::cout << "\nЗмінимо сторони трикутника:\n";
    tr.setValues(1, 1, 10);
    tr.print();

    return 0;
}
