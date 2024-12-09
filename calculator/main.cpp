#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>

int main() {
    std::cout << "Введите выражение (или пустую строку для выхода):\n";

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            break;
        }
        double result = 0.0, num = 0.0;
        char operation = '+';
        size_t i = 0;
        while (i < input.length()) {
            while (i < input.length() && input[i] == ' ') ++i;
            std::string numberStr;
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.' || input[i] == '-')) {
                numberStr += input[i++];
            }
            num = std::stod(numberStr);
            switch (operation) {
                case '+': result += num; break;
                case '-': result -= num; break;
                case '*': result *= num; break;
                case '/':
                    if (num != 0) result /= num;
                    else { std::cout << "Ошибка: деление на ноль!" << std::endl; return 1; }
                break;
                case'^':return std::pow(result, num);
                break;
            }
            while (i < input.length() && input[i] == ' ') ++i;
            if (i < input.length()) operation = input[i++];
        }
        std::cout << "Результат: " << result << std::endl;
    }
    return 0;
}