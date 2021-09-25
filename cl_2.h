#ifndef _CL_2_H_
#define _CL_2_H_
#include <iostream>
#include <vector>
#include <string>
#include "cl_1.h"
class cl_2: public cl_1 {
public:
    string object_name; //наименование
    cl_1* parent; //указатель на родителя

    cl_2(string, cl_1*); //конструктор
    void signal_set_function(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application); //сигнал для ввода логического выражения
    void signal_get_values(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application); //сигнал для вывода логических переменных
    void signal_make_postfix(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application); //сигнал для создания постфиксной записи и вычисления результата
    void signal_make_values(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application); //сигнал для преобразования логических переменных
};
#endif