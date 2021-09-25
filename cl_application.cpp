#include <iostream>
#include <string>
#include "cl_application.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"

using namespace std;
cl_application::cl_application(string object_name, cl_1* parent): cl_1(object_name, parent){}

cl_application::~cl_application(){
    for (int i = 0; i < children.size(); i++)
        delete children[i];
}

void cl_application::exec_app(){
    cout << "OUT";
    cl_2 *object_2_1 = new cl_2("1", this);
    cl_4 *object_2_2 = new cl_4("2", this);
    cl_5 *object_2_3 = new cl_5("3", this);
    cl_6 *object_2_5 = new cl_6("4", this);
    cl_3 *object_3 = new cl_3("5", this);

    object_2_1->set_connect(SIGNAL_D(cl_2::signal_set_function), object_3,
                            HENDLER_D(cl_3::hendler_set_function));
    object_2_1->set_connect(SIGNAL_D(cl_2::signal_make_values), object_3,
                            HENDLER_D(cl_3::hendler_make_values));
    object_2_1->set_connect(SIGNAL_D(cl_2::signal_get_values), object_3,
                            HENDLER_D(cl_3::hendler_get_values));
    object_2_1->set_connect(SIGNAL_D(cl_2::signal_make_postfix), object_3,
                            HENDLER_D(cl_3::hendler_make_postfix));
    object_2_2->set_connect(SIGNAL_D(cl_4::signal_set_values), object_3,
                            HENDLER_D(cl_3::hendler_set_values));
    object_2_3->set_connect(SIGNAL_D(cl_5::signal_print_postfix),object_3,
                            HENDLER_D(cl_3::hendler_print_postfix));
    object_2_5->set_connect(SIGNAL_D(cl_6::signal_print_result), object_3,
                            HENDLER_D(cl_3::hendler_print_result));
    object_2_1->emit_signal(SIGNAL_D(cl_2::signal_set_function), this);
}
