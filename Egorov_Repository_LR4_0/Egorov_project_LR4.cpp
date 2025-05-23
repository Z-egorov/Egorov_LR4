#include <iostream>
#include <map>
#include <string>
#include <functional>


int side1;

// Проверка корректности вводимых данных
bool UserInput(std::string input) {
    // Если строка пустая - ввод некорректен
    if (input.empty()) return false;
    
    // Попытаться преобразовать введенное значение в int
    try {
        int number = stoi(input);
        if (number < 0) return false; // Отрицательные числа недопустимы
    }
    catch (...) { // Если возникла ошибка (например, нечисловой ввод)
        return false;
    }
    return true; // Ввод корректен
}

// Функция ввода данных
void enterNumber(int& varLink, std::string label) {
    std::string str_input;
    std::cout << label << " = ";
    std::getline(std::cin, str_input); // Ввод значения в текстовом виде
    
    // Пока ввод некорректен, повторять запрос
    while (!UserInput(str_input)) {
        std::cout << label << " = ";
        std::getline(std::cin, str_input);
    }
    
    // Присвоить переменной varLink преобразованное значение
    varLink = stoi(str_input);
}

void enterSide1()
{
    //разрабатывается Developer1 - ветка branch_fun_1
}

void calcArea()
{
    //разрабатывается Developer3 - ветка branch_fun_2
}

void calcPerim()
{
    //разрабатывается Developer4 - ветка branch_fun_3
    std::cout << 3 * side1 << '\n';
}

struct MenuItem {
    std::string title;
    std::function<void()> action; 
};

int main() {
    std::map<int, MenuItem> menu = {
        {1, {"Ввод 1-й стороны прямоугольника", enterSide1}},
        {2, {"Calculate of Area", calcArea}},
        {3, {"Calculate of Perimetr", calcPerim}}
    };

    int choice = 0;

    while (true) {
        std::cout << "Меню:" << "\n";
        for (const auto& item : menu) {
            std::cout << "Task " << item.first << ". " << item.second.title << "\n";
        }
        std::cout << "0. Выход" << "\n";
        enterNumber(choice, "Input number of menu: ");
        if (choice == 0) {
            std::cout << "0 2025 FirstName LastName" << "\n";
            break;
        }
        std::cout << '\n';
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            std::cout << "Некорректный ввод.";
        }
        std::cout << "\n";
    }

    return 0;
}