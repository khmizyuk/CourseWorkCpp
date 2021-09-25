#ifndef _CL_4_H_
#define _CL_4_H_
#include <iostream>
#include <vector>
#include <string>
#include "cl_1.h"
class cl_4: public cl_1 {
public:
    string object_name; //наименование
    cl_1* parent; //указатель на родителя

    cl_4(string, cl_1*); //конструктор
    void signal_set_values(cl_3* object_3, TYPE_HENDLER hendler, cl_1
    *ob_cl_application); //сигнал для получения логических переменных

};
#endif 