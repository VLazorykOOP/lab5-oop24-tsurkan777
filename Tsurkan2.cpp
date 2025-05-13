#include <iostream>
#include <functional>

class Title {
    std::string text;
public:
    Title(const std::string& t) : text(t) {}
    void print() const {
        std::cout << "Назва: " << text << "\n";
    }
};

class Button {
    std::string label;
    std::function<void()> callback;

public:
    Button(const std::string& l) : label(l) {}

    void setCallback(std::function<void()> cb) {
        callback = cb;
    }

    void pressKey() {
        std::cout << "клавіша натиснута. ";
        if (callback) callback();
        else std::cout << "No callback set.\n";
    }

    void print() const {
        std::cout << "Кнопка: [" << label << "]\n";
    }
};

class Window {
    Title title;
    Button button;

public:
    Window(const std::string& titleText, const std::string& buttonText)
        : title(titleText), button(buttonText) {
        button.setCallback([this]() { onButtonPressed(); });
    }

    void display() const {
        std::cout << "вікно:\n";
        title.print();
        button.print();
    }

    void simulateKeyPress() {
        button.pressKey();
    }

    void onButtonPressed() {
        std::cout << "Callback: Кнопка нажата!\n";
    }
};

int main() {
    system("chcp 65001");
    // Create window with title and button
    Window w("Main Window", "OK");
    w.display();

    // Simulate key press
    w.simulateKeyPress();

    return 0;
}
