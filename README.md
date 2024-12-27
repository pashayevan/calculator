# Калькулятор

Это базовый калькулятор, способный вычислять математические выражения, поддерживая следующие выражения:

- Сложение (`+`)
- Вычитание (`-`)
- Умножение (`*`)
- Деление (`/`)
- Возведение в степень (`^`)

Калькулятор включает в себя проверку входных выражений и обработку ошибок для недопустимых входных данных или операций (например, деление на ноль).

## Возможности

1. **Проверка выражений:** Проверка входных данных на соответствие допустимым символам и операторам.
2. **Вычисление выражений:** Анализ и вычисление результатов с учетом приоритетов операций.
3. **Обработка ошибок:** Обработка некорректных входных данных, недопустимых выражений и математических ошибок.

## Файлы

1. **calc.h**
   - Заголовочный файл. Объявляет функции калькулятора.
2. **main.cpp**
   - Точка входа в программу. Считывает пользовательский ввод, вычисляет выражения и отображает результаты.
3. **calc.cpp**
   - Реализует основную функциональность, включая проверку выражений, разбор и вычисление.
4. **tests.cpp**
   - Содержит модульные тесты для проверки функций и вычислений.


### Примеры выражений
- Верные:
- ```bash
    5*57
    7.8-5.7
    3.4^2
    6--5 — вычитание отрицательного числа.
- Неверные:
- ```bash
     gfhl_jkr
     8++*++9
     
## Модульные тесты

Проект включает в себя модульные тесты, охватывающие проверку валидации, операторных функций и вычислений:

- Проверка граничных случаев, таких каких как деление на ноль и пустой ввод.
- Тестирование корректных и некорректных выражений.
- Проверка правильной реализации приоритетов операций.
