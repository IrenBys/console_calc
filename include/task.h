#ifndef TASK_H
#define TASK_H


enum Status 
{
    OK = 0,             // успешное выполнение
    ERROR = -1,         // ошибка
    HELP = 2,           // вызов справка
    OVERFLOW,           // переполнение
    DIV_BY_ZERO,        // деление на ноль
    NEGATIVE_FACTORIAL, // отрицательный факториал
    UNKNOWN_OPERATION   // неизвестная операция  
};

// Структура Task для передачи данных между Parser, Checker, Calculator и Printer
struct Task
{
    int value1;       // Первое число
    int value2;       // Второе число
    char operation;   // Операция (+, -, *, /, ^, !)
    double result;    // Результат вычисления
    Status status;    // Статус выполнения  
};

#endif // TASK_H
