#include "cl_1.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
#include "cl_application.h"
#include <iostream>

using namespace std;
cl_3::cl_3(string object_name, cl_1 *parent): cl_1(object_name, parent) {}
void cl_3::hendler_set_function(cl_1* ob_cl_application){
    pair.clear();
    getline(cin, infix_function);
    if (infix_function != ".")
        ob_cl_application->children[1]->emit_signal(SIGNAL_D(cl_4::signal_set_values), ob_cl_application);
    else
        return;
}
void cl_3::hendler_set_values(cl_1* ob_cl_application){
    getline(cin, values);
    string values_copy = values;
    while (values_copy.length()>0) {
        pos = values_copy.find('=');
        if (values_copy[ pos+2 ] == '1')
            pair[ values_copy.substr(0,pos-1) ] = true;
        else
            pair[ values_copy.substr(0,pos-1) ] = false;
        values_copy.erase(0, pos+4);
    }
    ob_cl_application->children[0]->emit_signal(SIGNAL_D(cl_2::signal_make_values), ob_cl_application);
}
void cl_3::hendler_make_values(cl_1* ob_cl_application){
    values_bool = "";
    string substring;
    for (int i=0; i<values.length(); i++){
        if (values[i]=='1'){
            values_bool.append("true");
        }
        else if (values[i]=='0'){
            values_bool.append("false");
        }
        else {
            values_bool += values[i];
        }
    }
    ob_cl_application->children[0]->emit_signal(SIGNAL_D(cl_2::signal_get_values), ob_cl_application);
}
void cl_3::hendler_get_values(cl_1* ob_cl_application){
    cout << endl << "Values: " << values_bool;
    ob_cl_application->children[0]->emit_signal(SIGNAL_D(cl_2::signal_make_postfix), ob_cl_application);
}
void cl_3::hendler_make_postfix(cl_1* ob_cl_application){
    string substring;
    values_postfix_function = "";
    for (int i=0; i<infix_function.size(); i++) {
        if (isdigit(infix_function[i]) || isalpha(infix_function[i])
            || infix_function[i]=='(' || infix_function[i]==')' || infix_function[i]=='<'
            || infix_function[i]=='>' || infix_function[i]=='=') {
            substring += infix_function[i];
        }
        else if (isspace(infix_function[i]) || infix_function[i]=='.')
        {
            //переменные записываются в результирующую строку в первоначальном порядке
            if (!is_sign(substring) && substring!="(" &&
                substring!=")") {
                postfix_function += substring;
                postfix_function += " ";
            }
                //при появлении символа операции
            else if (is_sign(substring)) {
                //если стек пуст или его верхний элемент открывающая скобка
                if (signs.empty() || signs.top() == "(")
                    signs.push(substring);
                //если новая операция имеет больший приоритет, чем верхняя операция в стеке
                else if (get_priority(signs.top()) <
                         get_priority(substring))
                    signs.push(substring);
                //если новая операция имеет меньший или равный приоритет, чем верхняя операция в стеке
                else if (get_priority(signs.top()) >=
                         get_priority(substring)) {
                    //операции, находящиеся в стеке, до ближайшей отрывающейся скобки
                    //или до операции с приоритетом меньшим, чем у новой операции, перекладываются в итоговую строку
                    while (!signs.empty() && signs.top() !="(" && (get_priority(signs.top()) >= get_priority(substring))){
                        postfix_function =
                                postfix_function + signs.top() + " ";
                        signs.pop();
                    }
                    //после этого новая операция кладётся в стек
                    signs.push(substring);
                }
            }
                //отрывающая скобка кладётся в стек
            else if (substring == "(") {
                signs.push(substring);
            }
            //закрывающая скобка выталкивает из стека в итоговую строку все операции до ближайшей открывающей скобки
            else if (substring == ")") {
                while (!signs.empty() && signs.top() != "(") {
                    postfix_function += signs.top();
                    postfix_function += " ";
                    signs.pop();
                }
                //после этого удаляется и сама открывающая скобка
                if (signs.top() == "(")
                    signs.pop();
            }
            substring = "";
        }
        if (infix_function[i]=='.')
            break;
    }
    //после того, как мы добрались до конца исходного выражения, операции, оставшиеся в стеке, перекладываются в исходную строку
    while (!signs.empty()) {
        postfix_function += signs.top();
        postfix_function += " ";
        signs.pop();
    }
    postfix_function.erase(postfix_function.length()-1, 1);
    //подстановка значений
    values_postfix_function = "";
    postfix_function += " ";
    for (int i=0; i<postfix_function.size(); i++) {
        if (!isspace(postfix_function[i])) {
            substring += postfix_function[i];
        }
        else {
            if (is_sign(substring)) {
                values_postfix_function.append(substring);
                values_postfix_function.append(" ");
                substring = "";
            }
            else {
                if (pair[substring] == true) {

                    values_postfix_function.append("true");
                    values_postfix_function.append(" ");
                }
                else {

                    values_postfix_function.append("false");
                    values_postfix_function.append(" ");
                }
                substring = "";
            }
        }
    }

    postfix_function.erase(postfix_function.length()-1, 1);

    substring = "";

    ob_cl_application->children[2]->emit_signal(SIGNAL_D(cl_5::signal_print_postfix), ob_cl_application);
}
void cl_3::hendler_print_postfix(cl_1* ob_cl_application){
    cout << endl << "Polish Notation: " << postfix_function ;
    postfix_function = "";

    string substring = "";

    for (int i=0; i<values_postfix_function.length(); i++) {
        if (!isspace(values_postfix_function[i])) {
            substring += values_postfix_function[i];
        }
        else {
            if (substring=="false"){
                calculating_stack.push(false);
                substring="";
            }
            else if (substring=="true"){
                calculating_stack.push(true);
                substring="";
            }

            else if (is_sign(substring)){
                if (substring!="NOT"){
                    bool n2 = calculating_stack.top();
                    calculating_stack.pop();
                    bool n1 = calculating_stack.top();
                    calculating_stack.pop();

                    bool res = calculate(n1, substring,
                                         n2);
                    calculating_stack.push(res);
                    substring = "";
                }
                else {
                    bool n = calculating_stack.top();
                    calculating_stack.pop();
                    calculating_stack.push(!n);
                    substring = "";
                }
            }
        }
    }
    ob_cl_application->children[3]->emit_signal(SIGNAL_D(cl_6::signal_print_result), ob_cl_application);
}
void cl_3::hendler_print_result(cl_1* ob_cl_application){
    //подсчёт выражения
    result = calculating_stack.top();
    calculating_stack.pop();
    if (result == true)
        cout << endl << "Result: true";
    else if (result == false)
        cout << endl << "Result: false";
    ob_cl_application->children[0]->emit_signal(SIGNAL_D(cl_2::signal_set_function), ob_cl_application);
}
bool cl_3::calculate(bool n1, string operation, bool n2){
    if (operation == "AND")
        return n1*n2;
    if (operation == "OR"){
        if (n1 + n2 >= 1)
            return true;
        else
            return false;
    }
    if (operation == "XOR") {
        if ((n1==false && n2 == false) || (n1==true && n2 == true))
            return false;
        else
            return true;
    }
    if (operation == "=>") {
        if (n1==true && n2==false)
            return false;
        else
            return true;
    }
    if (operation == "<=>") {
        if (n1==n2)
            return true;
        else
            return false;
    }
}
int cl_3::get_priority(string sign){
    if (sign == "<=>") return 1;
    else if (sign == "=>") return 2;
    else if (sign == "OR") return 3;
    else if (sign == "XOR") return 3;
    else if (sign == "AND") return 4;
    else if (sign == "NOT") return 5;
}
bool cl_3::is_sign(string substring) {
    return (substring=="AND")||(substring=="OR")||(substring=="NOT")||
           (substring=="XOR")||(substring=="=>")||(substring=="<=>");
}
