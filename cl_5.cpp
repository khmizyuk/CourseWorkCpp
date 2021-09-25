#include <iostream>
#include "cl_5.h"

using namespace std;

cl_5::cl_5(string object_name, cl_1 *parent): cl_1(object_name, parent) {}

void cl_5::signal_print_postfix(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application) {
    (object_3->*hendler)(ob_cl_application);
}