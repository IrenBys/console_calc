#include "printer.h"
#include <iostream>

// Функция для печати результата вычисления в формате "число1 операция число2 = результат"
void printResult(int a, int b, double c, char operation)
{
    // Если операция не факториал, то печатаем в формате "число1 операция число2 = результат"
    if (operation != '!')
    {
        std::cout << a << ' ' << operation << ' ' << b << " = " << c << '\n';    
    } 
    else 
    {
        std::cout << a << operation << " = " << c << '\n';
    }
}

// Функция для печати результата или сообщения об ошибке в зависимости от статуса задачи
void printTask(const Task& task)
{
    switch (task.status)
    {
        case OK:
            printResult(task.value1, task.value2, task.result, task.operation);
            break;
        case UNKNOWN_OPERATION:
            std::cout << "Error! Unknown operation!\n";
            break;
        case HELP:
            break;
        case DIV_BY_ZERO:
            std::cout << "Error! Division by zero!\n";
            break;
        case OVERFLOW:
            std::cout << "Error! Overflow!\n";
            break;
        case NEGATIVE_FACTORIAL:
            std::cout << "Error! Negative factorial!\n";
            break;
        case ERROR:
            std::cout << "Unknown error.\n";
        default:
            break;
    } 
}

// Функция для печати справки по использованию программы 
void printHelp() 
{
    std::cout << "Usage: ./console_calc <number1> <operation> <number2>\n";
    std::cout << "Operations:\n";
    std::cout << "  + : addition\n";
    std::cout << "  - : subtraction\n";
    std::cout << "  \\* : multiplication\n";
    std::cout << "  / : division\n";
    std::cout << "  ^ : power\n";
    std::cout << "  ! : factorial (only number1 is used)\n";

    std::cout << "Example:\n";
    std::cout << "  ./console_calc 1 + 3\n";
    std::cout << "  ./console_calc 3 !\n";
    std::cout << "  ./console_calc 2 \\* 3\n";
}
