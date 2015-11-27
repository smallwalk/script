#include <iostream>
#include <fstream>
#include <string>
    
using namespace std;

struct student 
{
    string name;
    int age;
    string gender;
    int height;
    int weight;
};

int main()
{
    ifstream fin("./students.txt");
    cout << "下面是文件内容:\n";
    string line;
    string pattern = " ";

    student stu[10];
    int x = 0;
    while(getline(fin, line)) {
        int size = line.size();
        int pos = 0;
        int j = 0;
        for (int i=0; i<size; i++) {
            pos = line.find(pattern, i);
            string s;
            if (pos < 0) {
                s = line.substr(i);
                if (!s.empty()) {
                    j++;
                }
            }
            else {
                s = line.substr(i, pos - i); 
                if (!s.empty()) {
                    i = pos;
                    j++;
                }
            }

            if (s.empty()) {
                continue;
            }

            if (j == 1) {
                stu[x].name = s;
            }
            else if (j == 2) {
                stu[x].age = stoi(s);
            }
            else if (j == 3) {
                stu[x].gender = s;
            }
            else if (j == 4) {
                stu[x].height = stoi(s);
            }
            else if (j == 5) {
                stu[x].weight = stoi(s);
            }
        }
        x++;
    }

    for (x=0; x<4; x++) {
        cout << "x:" << x << "name:" << stu[x].name << " age:" << stu[x].age << " 性别:" << stu[x].gender << "身高:" << stu[x].height << " 体重:" << stu[x].weight << endl;
    }

    fin.close();
    return 0;
}
