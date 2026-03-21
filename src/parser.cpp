#include "parser.h"
#include "printer.h"
#include <cstdlib>
#include <getopt.h>
#include <cstdio>


// Обработка --help
bool parseHelp(int opt, Task& task) 
{
    if (opt == 'h') 
    {
        printHelp();    // Печатаем справку и устанавливаем статус, чтобы не выполнять дальнейшие действия
        task.status = 2;
        return true;  
    }
    return false;
}

// Проверка операций
bool checkOperationArgs(int args_number, Task& task) 
{
    // Для бинарных операций должно быть 3 аргумента: число1, операция, число2
    if (args_number != 3) 
    {
        fprintf(stderr, "Binary operation requires two numbers\n");
        task.status = 1;
        return false;
    }
    return true;
}


// Проверка факториала 
bool checkFactorialArgs(int args_number, Task& task) 
{
    // Для факториала должно быть 2 аргумента: число и операция
    if (args_number != 2) {
        fprintf(stderr, "Error: factorial requires only one number\n");
        task.status = 1;
        return false;
    }
    return true;
}


// Функция для парсинга аргументов командной строки и заполнения структуры Task
void parse(int argc, char** argv, Task& task)
{
    // Изначально считаем, что статус "ok"
    task.status = 0;
    
    // Определяем длинные опции для getopt_long
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}};

    // Сначала проверяем, не вызван ли --help
    int opt;  // Переменная для хранения текущей опции
    while ((opt = getopt_long(argc, argv, "h", long_options, NULL)) != -1) 
    {
        if (parseHelp(opt, task)) 
        {
            return; // ��сли был вызван --help, то завершаем парсинг
        }
    }

    // Если --help не был вызван, то продолжаем парсинг остальных аргуме��тов
    if (optind >= argc) 
    {
        fprintf(stderr, "Error: No arguments provided\n");
        task.status = 1;
        return;
    }

    
    task.value1 = atoi(argv[optind]);        // Парсим первое число
    task.operation = *(argv[optind + 1]);    // Парсим операцию 

    // Проверяем, является ли операция факториалом
    if (task.operation == '!') 
    {
        if (!checkFactorialArgs(argc - optind, task)) 
        {
            return; // Если аргументы для факториала некорректные, то завершаем парсинг
        }
    } 
    else 
    {
        if (!checkOperationArgs(argc - optind, task)) 
        {
            return; // Если аргументы для бинарной операции некорректные, то завершаем парсинг
        }
        task.value2 = atoi(argv[optind + 2]); // Парсим второе число для бинарных операций
    }
}
