#ifndef _CL_APPLICATION_H_
#define _CL_APPLICATION_H_
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "cl_1.h"

using namespace std;
class cl_application: public cl_1 {

public:
    string object_name; //наименование
    cl_1* parent; //указатель на родителя

    cl_application(string, cl_1*); //конструктор
    ~cl_application(); //деструктор класса
    void exec_app(); //метод запуска приложения
};
#endif 