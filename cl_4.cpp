#include <iostream>
#include "cl_3.h"
#include "cl_4.h"
#include "cl_application.h"

using namespace std;

cl_4::cl_4(string object_name, cl_1 *parent): cl_1(object_name, parent) {}

void cl_4::signal_set_values(cl_3* object_3, TYPE_HENDLER hendler, cl_1 *ob_cl_application) {
    (object_3->*hendler)(ob_cl_application);
}