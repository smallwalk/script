#include "include/mysqlxx.h"
#include "include/mystack.h"
#include "include/order.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int test();
string infix_2_suffix(string);
int compair(int, int);

int main()
{
    string infix = "9+(3-1)*3+10/2";
    //中缀转后缀
    string suffix = infix_2_suffix(infix);

    cout << "infix:" << infix << endl;
    cout << "suffix:" << suffix << endl;

    return 0;
}

/**
 * 当读到一个操作数时，立即将它放到输出中;操作符则不立即输出，放入栈中。遇到左圆括号也推入栈中。
 * 如果遇到一个右括号，那么就将栈元素弹出，将符号写出直到遇到一个对应的左括号。但是这个左括号只被弹出，并不输出
 * 在读到操作符时，如果此时栈顶操作符优先性大于或等于此操作符，弹出栈顶操作符直到发现优先级更低的元素位置。
 * 除了处理）的时候，否则决不从栈中移走"（"。操作符中，+-优先级最低，（）优先级最高。
 * 如果读到输入的末尾，将栈元素弹出直到该栈变成空栈，将符号写到输出中。
 */
string infix_2_suffix(string infix)
{
    mystack<int> int_stack;
    int length = infix.length();
    char c_suffix[length+1];
    int i = 0;
    for (string::iterator iter = infix.begin(); iter != infix.end(); iter++) {
        if (isdigit(*iter)) {
            //是数字，直接输出
            c_suffix[i++] = *iter;
        }
        else if (int_stack.isEmpty()) {
            //空栈，进栈
            int_stack.push(*iter);
        }
        else {
            int top = int_stack.top();
            if (*iter == ')') {
                //出栈直到遇到'('
                while (!int_stack.isEmpty()) {
                    int_stack.pop();
                    if (top == '(') {
                        break;
                    }
                    c_suffix[i++] = top;
                    top = int_stack.top();
                }
            }
            else if (*iter == '(') {
                //优先级最高，直接进栈
                int_stack.push(*iter);
            }
            else {
                if (*iter == '+' || *iter == '-') {
                    if (top == '(') {
                        int_stack.push(*iter);
                    }
                    else {
                        //出栈
                        while (!int_stack.isEmpty()) {
                            c_suffix[i++] = top;
                            int_stack.pop();
                            top = int_stack.top();
                        }
                        int_stack.push(*iter);
                    }
                }
                else {
                    if (top == '(') {
                        int_stack.push(*iter);
                    }
                    else {
                        //出栈，直到遇到+ -
                        while (!int_stack.isEmpty() && top != '+' && top != '-') {
                            c_suffix[i++] = top;
                            int_stack.pop();
                            top = int_stack.top();
                        }
                        int_stack.push(*iter);
                    }
                }
            }
        }
    }
    //栈非空，则输出
    int top = int_stack.top();
    while (!int_stack.isEmpty()) {
        c_suffix[i++] = top;
        int_stack.pop();
        top = int_stack.top();
    }
    c_suffix[length] = '\0';
    return c_suffix;
}

int test() 
{
    MysqlXX mysql;
    bool r = mysql.Connect("", "", "", "test", 0);
    if (!r) {
        cout << "connect error:" << mysql.GetLastError() << endl;
        return -1;
    }
    r = mysql.Query("select id,order_id,ctime from t_bat_order_seller order by id desc limit 100000");
    if (!r) {
        cout << "query error:" << mysql.GetLastError() << endl;
        return -1;
    }

    //订单集合
    mystack<order> orders;

    for (MysqlXX::iterator i = mysql.begin(); i != mysql.end(); ++i) {
        std::map<std::string, std::string> _row;
        cout << "id=" << (*i)["id"] << " order_id=" << (*i)["order_id"] << " ctime=" << (*i)["ctime"] << endl;
        order o;
        o.id = stoi((*i)["id"]);
        o.order_id = (*i)["order_id"];
        o.ctime = (*i)["ctime"];
        orders.push(o);
    }

    cout << endl;

    order o = orders.top();
    cout << "id=" << o.id << " order_id=" << o.order_id << " ctime=" << o.ctime << endl;
    cout << orders.length() << endl;
    orders.pop();

    o = orders.top();
    cout << "id=" << o.id << " order_id=" << o.order_id << " ctime=" << o.ctime << endl;
    cout << orders.length() << endl;
    orders.pop();

    o = orders.top();
    cout << "id=" << o.id << " order_id=" << o.order_id << " ctime=" << o.ctime << endl;
    cout << orders.length() << endl;
    return 0;
}
