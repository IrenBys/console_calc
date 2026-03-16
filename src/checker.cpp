#include "checker.h"

void check(Task& task)
{
    // Проверяем деление на 0
    if (task.operation == '/' && task.value2 == 0)
    {
        task.status = -1;
    }

    // Проверка неизвестной операции
    if (!(task.operation == '+' || task.operation == '-' || task.operation == '*' ||
          task.operation == '/' || task.operation == '^' || task.operation == '!'))
    {
        task.status = 1;
    }
}
