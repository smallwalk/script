#include <iostream>
#include "student.h"
#include "dlist.h"

using namespace std;

int main()
{
    std::vector<student> s = student_assign("./students.txt");    
    dlist<student> stu_list;
    for (int i=0; i<s.size(); i++) {
        stu_list.Add(s[i]);
        //cout << s[i].name << endl;
    }

    stu_list.traversal();
    cout << "长度:" << stu_list.length() << endl;

    //---------------删除测试---------------------
    cout << "删除测7" << endl;
    student s2 = {
        "101", "测7", 27, "女", 165, 65
    };
    stu_list.Delete(s2);
    stu_list.traversal();

    return 0;
}

