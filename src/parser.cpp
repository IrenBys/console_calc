#include "parser.h"
#include "printer.h"
#include <cstdlib>
#include <iostream>


// Функция для парсинга аргументов командной строки и заполнения структуры Task

void parse(int argc, char** argv, Task& task)
{
    // Если пользователь вызвал --help
    if (argv[1] == std::string("--help"))
    {
        printHelp();
        task.status = 2;  // Устанавливаем статус, чтобы не выполнять дальнейшие действи
        return;
    }

    // Парсим первое число
    task.value1 = std::atoi(argv[1]);

    // Парсим первое число
    task.value1 = std::atoi(argv[1]);

    // Берем второй аргумент как строку
    std::string opStr = argv[2];

    // Если операция это "*", и она разбилась shell'ом на несколько аргументов
    if (opStr.find('*') != std::string::npos) {
        task.operation = '*';
    } 
    else 
    {
        task.operation = opStr[0];
    }

    // Если операция не факториал, то парсим второе число
    if (task.operation != '!') 
    {
        task.value2 = std::atoi(argv[3]);   
    }
    
	// Изначально считаем, что статус "ok"
    task.status = 0;
}
