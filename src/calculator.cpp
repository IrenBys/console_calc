#include "calculator.h"
#include "mathlib.h"

// Функция для выполнения вычислений в зависимости от операции, указанной в структуре Task.
// Результат сохраняется в поле result, а статус ошибки (если есть) сохраняется в поле status.
void calculate(Task& task)
{
    task.status = 0;
    switch (task.operation)
    {
    case '+':
        task.status = mathlib::addition(task.value1, task.value2, &task.result);
        break;
    case '-':
        task.status = mathlib::substraction(task.value1, task.value2,&task.result);
        break;
    case '*':
        task.status = mathlib::multiplication(task.value1, task.value2, &task.result);
        break;
    case '/':
        task.status = mathlib::division(task.value1, task.value2, &task.result);
        break;
    case '^':
        task.status = mathlib::power(task.value1, task.value2, &task.result);
        break;
    case '!':
        task.status = mathlib::factorial(task.value1, &task.result);
        break;
    default:
        task.status = 1;
    }
}
