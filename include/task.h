#ifndef TASK_H
#define TASK_H

// Структура Task для передачи данных между Parser, Checker, Calculator и Printer

struct Task
{
    int value1;       // Первое число
    int value2;       // Второе число
    char operation;   // Операция (+, -, *, /, ^, !)
    double result;    // Результат вычисления
    int status;       // 0 = ok, -1 = деление на 0, 1 = неизвестная операция
};

#endif // TASK_H
