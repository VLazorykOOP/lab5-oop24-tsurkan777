#include <iostream>
#include <string>

class MyString {
protected:
    std::string data;

public:
    MyString(const std::string& str = "") : data(str) {}

    MyString(const MyString& other) : data(other.data) {
        std::cout << "Конструктор копіювання (MyString)\n";
    }

    MyString& operator=(const MyString& other) {
        std::cout << "Оператор присвоювання (MyString)\n";
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    virtual ~MyString() {}

    virtual void print(std::ostream& os) const {
        os << data;
    }

    virtual void read(std::istream& is) {
        is >> data;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);
};

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    str.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    str.read(is);
    return is;
}

class UpperString : public MyString {
public:
    UpperString(const std::string& str = "") : MyString(str) {
        toUpper();
    }

    UpperString(const MyString& other) : MyString(other) {
        toUpper();
        std::cout << "Конструктор копіювання (UpperString)\n";
    }

    UpperString& operator=(const MyString& other) {
        std::cout << "Оператор присвоювання (UpperString)\n";
        MyString::operator=(other);
        toUpper();
        return *this;
    }

    void print(std::ostream& os) const override {
        os << data;
    }

    void read(std::istream& is) override {
        is >> data;
        toUpper();
    }

private:
    void toUpper() {
        for (char& c : data) {
            if (c >= 'a' && c <= 'z') {
                c -= ('a' - 'A');
            }
        }
    }
};

int main() {
    system("chcp 65001");
    MyString s1("Привіт");
    std::cout << "s1: " << s1 << "\n";

    UpperString s2("світ");
    std::cout << "s2: " << s2 << "\n";

    UpperString s3 = s1;
    std::cout << "s3 (копія з s1): " << s3 << "\n";

    s2 = s1;
    std::cout << "s2 (після присвоювання з s1): " << s2 << "\n";

    std::cout << "Введіть звичайний рядок: ";
    MyString input1;
    std::cin >> input1;
    std::cout << "Ви ввели: " << input1 << "\n";

    std::cout << "Введіть рядок для UpperString: ";
    UpperString input2;
    std::cin >> input2;
    std::cout << "Ви ввели: " << input2 << "\n";

    return 0;
}
