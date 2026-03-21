#include "runner.h"
#include "parser.h"
#include "checker.h"
#include "calculator.h"
#include "printer.h"

// Главная функция для выполнения программы, которая обрабатывает аргументы командной строки, выполняет проверку, вычисление и печать результата
int run(int argc, char** argv)
{
    Task task;                  // Создаем структуру Task для хранения данных о задаче
	parse(argc, argv, task);    // Парсим аргументы командной строки и заполняем структуру Task
    check(task);                // Проверяем корректность задачи
    calculate(task);            // Выполняем вычисление
    printTask(task);            // Печатаем результат или сообщение об ошибке
    return 0;
}
