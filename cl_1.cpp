#include "cl_1.h"
#include "cl_application.h"

cl_1::cl_1(string object_name, cl_1* parent) {
    this->object_name = object_name;
    this->parent = parent;
    if (parent != nullptr)
        //добавление в векор подчинённых головному объектов:
        parent->children.push_back(this);
}
void cl_1::set_connect(TYPE_SIGNAL new_signal, cl_3 *second_object,
                       TYPE_HENDLER new_hendler) {
    //исключение повторного установления связи:
    for (int i=0; i<this->connects.size(); i++)
        if ( (connects[i]->new_signal == new_signal) && (connects[i]->second_object == second_object) && (connects[i]->new_hendler == new_hendler) )
            return;

    connect *new_connection = new connect(); //cоздание новой связи

    new_connection->new_signal = new_signal;
    new_connection->second_object = second_object;
    new_connection->new_hendler = new_hendler;
    this->connects.push_back(new_connection); //добавить связь для текущего объекта
}
void cl_1::emit_signal(TYPE_SIGNAL new_signal, cl_1* ob_cl_application) {
    //цикл по всем связям сигнал-обработчик текущего объекта:
    for (int i = 0; i < this->connects.size(); i++) {
        if (connects.empty()) {
            return;
        }
        //если в очередной связи учавствует метод сигнала, переданный по параметру:
        if ((this->connects[i]->new_signal == new_signal)) {
            //cout<<endl<<"find";
            (this->*new_signal)(connects[i]->second_object, connects[i]->new_hendler, ob_cl_application);
            return;
        }
    }
}