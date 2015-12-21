#include <iostream>
#include <vector>
#include <stdlib.h> 
#include <fstream>

using namespace std;

struct config 
{
    string db_name;
    string host;
    string port;
    string user;
    string pass;
    int master;
};

std::vector<config> conf_assign(string file_path);

std::vector<string> conf_split(string str, string pattern);

/**
 * read batman slave slave 
 */
int main(int argc, char *argv[])
{
    string db_name = "batman";
    string env = "online";
    string from = "slave";

    if (argc >= 2) {
        db_name = argv[1];
    }
    if (argc >= 3) {
        env = argv[2];
    }
    if (argc >= 4) {
        from = argv[3];
    }
    
    string conf_path;
    conf_path = (env == "online" ? "xxxx" : "xxxxxxx");
    std::vector<config> conf = conf_assign(conf_path);

    config _conf;
    config _conn_conf;

    for (std::vector<config>::iterator iter = conf.begin(); iter != conf.end(); iter++) {
        _conf = *iter;
        if (_conf.db_name != db_name) {
            continue;
        }
        if (from == "slave" && _conf.master == 0) {
            _conn_conf = _conf; 
            break;
        }
        else if (from == "master" && _conf.master == 1) {
            _conn_conf = _conf; 
            break;
        }
    }

    cout << _conn_conf.db_name << " " << _conn_conf.port << " " << _conn_conf.host << endl;

    string comm = "mysql -u" + _conn_conf.user + " -p'" + _conn_conf.pass + "' -h" + _conn_conf.host + " --port=" + _conn_conf.port + " --default-character-set=utf8";

    cout << comm << endl;

    //system(comm);

    return 0; 
}

std::vector<std::string> conf_split(std::string str,std::string pattern)
{
    string::size_type pos;
    vector<std::string> result;
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

std::vector<config> conf_assign(string file_path)
{
    ifstream fin(file_path);
    string line;
    string pattern = " ";
    vector<config> result;
    string::size_type pos;

    string temp_str;
    string key;
    string value;
    while (getline(fin, line)) {
        int index = 0;
        config conf ;
        vector<string> s = conf_split(line, pattern);
        for (vector<string>::iterator iter = s.begin(); iter != s.end(); iter++) {
            temp_str = *iter;
            pos = temp_str.find("=");
            key = temp_str.substr(0, pos);
            value = temp_str.substr(pos+1);
            //cout << temp_str << " key:" << key << " value:" << value << endl;
            if (key == "db") {
                conf.db_name = value;
            }
            else if (key == "host") {
                conf.host = value;
            }
            else if (key == "port") {
                conf.port = value;
            }
            else if (key == "user") {
                conf.user= value;        
            }
            else if (key == "pass") {
                conf.pass = value; 
            }
            else if (key == "master") {
                conf.master = stoi(value) == 1 ? 1 : 0; 
            }
            else {
                continue;
            }
        }
        result.push_back(conf);
    }
    return result;
}
