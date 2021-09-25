#ifndef _CL_6_H_
#define _CL_6_H_
#include <iostream>
#include <vector>
#include <string>
#include "cl_1.h"
#include "cl_3.h"
#include "cl_application.h"
class cl_6: public cl_1 {
public:
    string object_name; //наименование
    cl_1* parent; //указатель на родителя

    cl_6(string, cl_1*); //конструктор
    void signal_print_result(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application); //сигнал для вывода результата
};
#endif