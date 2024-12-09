#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cctype>

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return std::pow(a, b);
        default: return 0;
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
    std::stack<double> values;
    std::stack<char> operators;
    size_t i = 0;

    while (i < expression.size()) {
        if (isspace(expression[i])) {
            ++i;  // Пропускаем пробелы
            continue;
        }

        if (isNumber(expression[i])) {
            // Считываем число (может быть с точкой)
            std::string numberStr;
            while (i < expression.size() && isNumber(expression[i])) {
                numberStr += expression[i++];
            }
            values.push(std::stod(numberStr));  // Добавляем число в стек
        } else if (expression[i] == '(') {
            operators.push(expression[i++]);  // Открывающая скобка
        } else if (expression[i] == ')') {
            // Выполняем операции до открывающей скобки
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop();  // Убираем '(' из стека операторов
            ++i;
        } else {
            // Оператор
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(expression[i++]);  // Добавляем оператор в стек
        }
    }

    // Выполняем оставшиеся операции
    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();  // Результат будет на верхушке стека
}

int main() {
    std::cout << "Введите выражение (или пустую строку для выхода):\n";

    while (true) {
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            break;  // Выход из программы, если введена пустая строка
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
