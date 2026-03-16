#include "calculator.h"
#include "mathlib.h"
#include <iostream>

// Функция для выполнения вычислений в зависимости от операции, указанной в структуре Task.
// Результат сохраняется в поле result, а статус ошибки (если есть) сохраняется в поле status.
void calculate(Task& task)
{
    task.status = 0;
    switch (task.operation)
    {
    case '+':
        task.result = mathlib::addition(task.value1, task.value2);
        break;
    case '-':
        task.result = mathlib::substraction(task.value1, task.value2);
        break;
    case '*':
        task.result = mathlib::multiplication(task.value1, task.value2);
        break;
    case '/':
        task.status = mathlib::division(task.value1, task.value2, &task.result);
        break;
    case '^':
        task.result = mathlib::power(task.value1, task.value2);
        break;
    case '!':
        task.result = mathlib::factorial(task.value1);
        // Проверяем, не возникла ли ошибка при вычислении факториала (например, для отрицательныx чисел)
        if (task.result == -1) 
        {
            task.status = 3; 
        }
        break;
    default:
        task.status = 1;
    }
}
