#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    using namespace std;

    string filename;
    cout << "Enter filename:" << endl;
    cin >> filename;

    ofstream fout(filename.c_str());
    fout << "For your eyes only!\n";
    float secret;
    cin >> secret;

    fout << "Your secret number is " << secret << endl;
    fout.close();

    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << endl;
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    cout << "Done\n";
    fin.close();

    return 0;
}
