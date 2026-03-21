#include "parser.h"
#include <getopt.h>
#include <cstdio>
#include <cstdlib>
#include "printer.h"

// Функция для установки статуса ошибки и печати сообщения об ошибке
void setError(Task& task, const char* message) 
{
    if (message)
    {
        fprintf(stderr, "Error: %s\n", message);
    }
    fprintf(stderr, "See --help for usage\n");
    task.status = ERROR;
}

// Проверка --help
bool parseHelp(int argc, char** argv, Task& task) 
{
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'}, 
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "h", long_options, NULL)) != -1) 
    {
        if (opt == 'h') 
        {
            printHelp();
            task.status = HELP;
            return true;
        }
    }
    return false;
}

// Основная функция parse
void parse(int argc, char** argv, Task& task) 
{
    task.status = OK;

    // 1. Проверяем --help
    if (parseHelp(argc, argv, task)) 
    {
        return;
    }

    // 2. Парсим первый аргумент
    if (optind >= argc) {
        setError(task, "Error: First number missing\n");
        return;
    }
    task.value1 = atoi(argv[optind]);
  
    // 3. Парсим операцию
    if (optind + 1 >= argc) {
        setError(task, "Error: Operation missing\n");
        return;
    }
    task.operation = argv[optind + 1][0];


    // 4. Парсим второй аргумент (если бинарная операция)
    if (task.operation != '!') 
    {
        if (optind + 2 >= argc) {
            setError(task, "Error: Second number missing\n");
            return;
        }
        task.value2 = atoi(argv[optind + 2]);
    }



}