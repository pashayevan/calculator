#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <stdexcept>

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return std::pow(a, b);  // отрицательная степень
        default:
            throw std::invalid_argument("Недопустимый оператор");
    }
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isNumber(char c) {
    return std::isdigit(c) || c == '.' || c == '-';
}

double evaluateExpression(const std::string& expression) {
    std::vector<double> values;
    std::vector<char> operators;
    size_t i = 0;

    while (i < expression.size()) {
        if (isspace(expression[i])) {
            ++i;
            continue;
        }

        if (isNumber(expression[i])) {
            std::string numberStr;
            if (expression[i] == '-') {
                numberStr += expression[i++];
                if (i < expression.size() && (isdigit(expression[i]) || expression[i] == '.')) {
                    numberStr += expression[i++];
                    while (i < expression.size() && (isdigit(expression[i]) || expression[i] == '.')) {
                        numberStr += expression[i++];
                    }
                    values.push_back(std::stod(numberStr));
                    continue;
                }
                numberStr.clear();
            }

            while (i < expression.size() && (isdigit(expression[i]) || expression[i] == '.')) {
                numberStr += expression[i++];
            }
            if (!numberStr.empty()) {
                values.push_back(std::stod(numberStr));
            }
        } else {
            while (!operators.empty() && precedence(operators.back()) >= precedence(expression[i])) {
                double b = values.back(); values.pop_back();
                double a = values.back(); values.pop_back();
                char op = operators.back(); operators.pop_back();
                values.push_back(applyOperation(a, b, op));
            }
            operators.push_back(expression[i]);
            ++i;
        }
    }

    while (!operators.empty()) {
        double b = values.back(); values.pop_back();
        double a = values.back(); values.pop_back();
        char op = operators.back(); operators.pop_back();
        values.push_back(applyOperation(a, b, op));
    }

    return values.back();
}

int main() {
    std::cout << "Введите выражение (или пустую строку для выхода):\n";

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            break;
        }

        try {
            double result = evaluateExpression(input);
            std::cout << "Результат: " << result << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }
    }
    return 0;
}
