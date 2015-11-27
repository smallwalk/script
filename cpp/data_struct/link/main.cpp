#include "student.h"
#include "slistNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> split(std::string str,std::string pattern);
std::vector<student> student_assign(string file_path);

int main() 
{
    std::vector<student> s = student_assign("./students.txt");
    myslist<student> slist;
    for (int i=0; i<s.size(); i++) {
        slist.Add(s[i]);
        cout << s[i].name << endl;
    }
    return 0;
}

/**
 * 初始化学生数据
 */
std::vector<student> student_assign(string file_path) 
{
    ifstream fin(file_path); 
    string line;
    string pattern = " ";
    std::vector<student> result;
    while (getline(fin, line)) {
        int index = 0;
        student stu;
        std::vector<std::string> s = split(line, pattern);
        for (int i=0; i<s.size(); i++) {
            if (s[i].empty()) {
                continue;
            }
            if (index == 0) {
                stu.name = s[i];    
            }
            else if (index == 1) {
                stu.age = stoi(s[i]);
            }
            else if (index == 2) {
                stu.gender = s[i];
            }
            else if (index == 3) {
                stu.height = stoi(s[i]);
            }
            else {
                stu.weight = stoi(s[i]);
            }
            index++;
        }
        result.push_back(stu);
    }
    return result;
}

/**
 * 分拆字符串
 */
std::vector<std::string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

