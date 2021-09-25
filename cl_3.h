#ifndef _CL_3_H_
#define _CL_3_H_
#include <iostream>
#include <vector>
#include <string>
#include "cl_1.h"
class cl_3: public cl_1 {
public:
    string object_name; //наименование
    cl_1* parent; //указатель на родителя

    cl_3(string, cl_1*); //конструктор
    int get_priority(string); //метод для получение приоритета переданной в параметре операции
    bool calculate(bool, string, bool); //метод вычисление логоческого выражения
    bool is_sign(string); //метод проверки - является ли строка знаком лочической операции
    void hendler_set_function(cl_1* ob_cl_application); //обработчик для ввода логического выражения
    void hendler_set_values(cl_1* ob_cl_application); //обработчик для ввода логических переменных
    void hendler_get_values(cl_1* ob_cl_application); //обработчик для вывода логических переменных
    void hendler_make_postfix(cl_1* ob_cl_application); //обработчик для создания постфиксной записи и вычисления результата
    void hendler_print_result(cl_1* ob_cl_application); //обработчик для вывода результата
    void hendler_make_values(cl_1* ob_cl_application); //обработчик для преобразования логических переменных
    void hendler_print_postfix(cl_1* ob_cl_application); //обработчик для вывода постфикной формы записи логической функции
};
#endif