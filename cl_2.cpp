#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_application.h"
#include <iostream>
using namespace std;
cl_2::cl_2(string object_name, cl_1* parent): cl_1(object_name, parent){}
void cl_2::signal_set_function(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application){
    (object_3->*hendler)(ob_cl_application);
}
void cl_2::signal_get_values(cl_3* object_3, TYPE_HENDLER hendler, cl_1
*ob_cl_application) {
    (object_3->*hendler)(ob_cl_application);
}
void cl_2::signal_make_postfix(cl_3* object_3, TYPE_HENDLER hendler, cl_1
*ob_cl_application) {
    (object_3->*hendler)(ob_cl_application);
}
void cl_2::signal_make_values(cl_3* object_3, TYPE_HENDLER hendler, cl_1
*ob_cl_application) {
    (object_3->*hendler)(ob_cl_application);
}
