#include "printer.h"
#include <iostream>

// Функция для печати результата вычисления в формате "число1 операция число2 = результат"
void printResult(int a, int b, int c, char operation)
{
    std::cout << a << ' ' << operation << ' ' << b << " = " << c << '\n';
}

// Функция для печати результата или сообщения об ошибке в зависимости от статуса задачи
void printTask(const Task& task)
{
    if (task.status == 0)
    {
        printResult(task.value1, task.value2, task.result, task.operation);
    }
    else if (task.status == -1)
    {
        std::cout << "Error! Division by zero!\n";
    }
    else if (task.status == 1)
    {
        std::cout << "Error! Unknown operation!\n";
    }
    else
    {
        std::cout << "Unknown error.\n";
    }
}
