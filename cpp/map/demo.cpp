#include<map>
#include<iostream>

using namespace std;

int main()
{
	//声明
	typedef map<string, int> MY_MAP;
	MY_MAP m_map;

	//向map写入数据
	//方式直观，但不建议使用
	m_map["a"] = 2;
	m_map["b"] = 1;
	m_map.insert(pair<string, int>("c", 100));
	m_map.insert(make_pair("d", 10));
	m_map.insert(map<string, int> :: value_type("e", 2000));


	//声明迭代器
	MY_MAP::iterator my_lr;

	//查找数据
	//只有当map中有这样的键的实例才对，否则会自动插入一个实例，值为初始化值。
	int i = m_map["d"];
	string key = "d";
	my_lr = m_map.find(key);
	if (my_lr == m_map.end()) {
		cout << "key = " << key << " not exists" << endl;
	}
	else {
		cout << "found" << m_map[key] << endl;
	}


	//遍历
	for (my_lr = m_map.begin(); my_lr != m_map.end(); my_lr++) {
		cout << my_lr->first << " " << my_lr->second << endl;
	}

	//返回元素数目
	cout << "count :" << m_map.size() << endl;

	//删除数据
	m_map.erase("c");

	cout << "del c count :" << m_map.size() << endl;

	//清空所有数据
	m_map.clear();

	//判断是否为空
	if (m_map.empty()) {
		cout << "map is empty" << endl;
	}

	return 0;
}
