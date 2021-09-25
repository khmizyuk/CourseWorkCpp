#ifndef _CL_1_H_
#define _CL_1_H_
class cl_1;
class cl_3;
//определение нового типа данных:
typedef void (cl_1::* TYPE_HENDLER) (cl_1*);
typedef void (cl_1::* TYPE_SIGNAL) (cl_3*, TYPE_HENDLER, cl_1*);

//параметризованное макроопределение препроцессора:
//получение указателя на метод сигнала объекта:
#define SIGNAL_D(signal_f) (TYPE_SIGNAL)(&signal_f)
//получение указателя на метод обработчика объекта: 
#define HENDLER_D(hendler_f) (TYPE_HENDLER)(&hendler_f)
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <vector>
using namespace std;
class cl_1 {
public:
    string object_name; //наименование
    cl_1* parent; //указатель на родителя
    vector <cl_1*> children; //вектор подчинённых объектов
    struct connect {
        TYPE_SIGNAL new_signal; //указатель на метод сигнала:
        cl_3 *second_object; //указатель на второй объект:
        TYPE_HENDLER new_hendler; //указатель на метод обработчика:
    }; //структура задания одной связи:
    vector <connect*> connects; //хранение установленных связей
    string infix_function; //инфиксная форма записи логического выражения
    string values; //строка со значениями логических переменных
    string values_bool; //подстановка значений в строкн со значениями логических переменных
    string postfix_function; //постфиксная форма записи логического выражения
    string values_postfix_function; //постфиксная форма записи логического выражения с целочисленными параметрами
    int pos; //позиция нужного символа в
    bool result; //результат логического выражения
    stack<string> signs; //стек для хранения логических операций
    map <string, bool> pair; //контецнер для хранения значений логических переменных
    stack<bool> calculating_stack; //стэк для вычисления значения логического выражения

    cl_1(string, cl_1*); //конструктор
    void set_connect(TYPE_SIGNAL new_signal, cl_3 *second_object, TYPE_HENDLER new_hendler); //установка связи между объектами
    void emit_signal(TYPE_SIGNAL new_signal, cl_1* ob_cl_application); //передача сигнала от текущего объекта
};
#endif