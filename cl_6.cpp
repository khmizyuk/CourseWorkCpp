#include <iostream>
#include "cl_6.h"

using namespace std;
cl_6::cl_6(string object_name, cl_1 *parent): cl_1(object_name, parent) {}

void cl_6::signal_print_result(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application) {
    (object_3->*hendler)(ob_cl_application);
}
