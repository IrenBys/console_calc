#include "parser.h"
#include <cstdlib>

// Функция для парсинга аргументов командной строки и заполнения структуры Task

void parse(int argc, char** argv, Task& task)
{
	// Проверяем, что передано достаточно аргументов (число1, операция, число2)
    if (argc < 4)
    {
        task.status = 1;
        return;
    }

	// Парсим аргументы и заполняем структуру Task
    task.value1 = std::atoi(argv[1]);
    task.operation = *(argv[2]);
    task.value2 = std::atoi(argv[3]);

	// Изначально считаем, что статус "ok"
    task.status = 0;
}
