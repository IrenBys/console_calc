#include "calculator.h"
#include "mathlib.h"


// Устанавливаем статус и при необходимости выводим подсказку
void setTaskStatus(Task& task, mathlib::Status status) 
{
    task.status = status;
    if (status != mathlib::OK) 
    {
        fprintf(stderr, "See --help for usage\n");
    }
}

// Функция для выполнения вычислений в зависимости от операции, указанной в структуре Task.
// Результат сохраняется в поле result, а статус ошибки (если есть) сохраняется в поле status.
void calculate(Task& task) {
    switch (task.operation) {
        case '+':
            setTaskStatus(task, mathlib::addition(task.value1, task.value2, &task.result));
            break;
        case '-':
            setTaskStatus(task, mathlib::substraction(task.value1, task.value2, &task.result));
            break;
        case '*':
            setTaskStatus(task, mathlib::multiplication(task.value1, task.value2, &task.result));
            break;
        case '/':
            setTaskStatus(task, mathlib::division(task.value1, task.value2, &task.result));
            break;
        case '^':
            setTaskStatus(task, mathlib::power(task.value1, task.value2, &task.result));
            break;
        case '!':
            setTaskStatus(task, mathlib::factorial(task.value1, &task.result));
            break;
        default:
            setTaskStatus(task, mathlib::ERROR);
            fprintf(stderr, "Error! Unknown operation\n");
            break;
    }
}