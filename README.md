# Console Calculator

Простой консольный калькулятор на C++ с поддержкой основных математических операций и проверкой ошибок переполнения.

## Возможности
- Сложение, вычитание, умножение, деление
- Возведение в степень (включая отрицательные степени)
- Вычисление факториала (только для неотрицательных чисел)
- Проверка деления на ноль
- Проверка переполнения целых чисел
- Поддержка справки через `--help`

## Пример использования
```bash
./console_calc 5 + 3        # Сложение
./console_calc 7 - 2        # Вычитание
./console_calc 4 \* 6      # Умножение (звёздочку нужно экранировать или взять в кавычки)
./console_calc 8 / 2        # Деление
./console_calc 2 ^ -3       # Степень (отрицательная степень)
./console_calc 5 !          # Факториал
./console_calc --help        # Справка
```

## Вывод ошибок
```bash
Error! Division by zero! — деление на ноль
Error! Overflow — переполнение типа int
Error! Factorial of negative number. — попытка вычислить факториал отрицательного числа
Error! Unknown operation! — неизвестная операция
```

## Структура проекта
```bash
src/ — исходники калькулятора (main.cpp, runner.cpp, parser.cpp, checker.cpp, calculator.cpp, printer.cpp)
include/ — заголовочные файлы, включая mathlib
install/ — папка, куда устанавливается скомпилированный бинарник
CMakeLists.txt — конфигурация сборки проекта
```


## Сборка под Linux
```bash
cmake -B build
cmake --build build
sudo cmake --build build --target install
```




