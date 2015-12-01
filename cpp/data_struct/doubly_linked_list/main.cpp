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
    return 0;
}

