#ifndef STUDENT_HXX
#define STUDENT_HXX
#include <vector>
#include <string>
#include <fstream>
struct student
{
    std::string id; //学号
    std::string name; 
    int age; 
    std::string gender;
    int height;
    int weight;
};

std::vector<std::string> student_split(std::string str,std::string pattern);

std::vector<student> student_assign(std::string file_path);

#endif
