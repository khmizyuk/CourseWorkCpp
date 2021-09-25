#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "cl_application.h"

using namespace std;
int main() {
    cl_application *ob_cl_application = new cl_application("0", nullptr);
    ob_cl_application->exec_app();
    delete ob_cl_application;
    return 0;
}
