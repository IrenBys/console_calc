#include "parser.h"
#include <cstdlib>
#include <iostream>


// Функция для парсинга аргументов командной строки и заполнения структуры Task

void parse(int argc, char** argv, Task& task)
{
    // Парсим аргументы и заполняем структуру Task
    task.value1 = std::atoi(argv[1]);
    task.operation = *(argv[2]);

    // Если операция не факториал, то парсим второе число
    if (task.operation != '!') 
    {
        task.value2 = std::atoi(argv[3]);   
    }
    
	// Изначально считаем, что статус "ok"
    task.status = 0;
}
