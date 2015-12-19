#include "include/mysqlxx.h"
#include "include/mystack.h"
#include "include/order.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
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
