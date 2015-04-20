#include<iostream>
#include <glog/logging.h>

using namespace std;
	int main(int argc, char* argv[]) {
	google::InitGoogleLogging(argv[0]);
	google::LogToStderr();//只输出到标准错误输出
	LOG(INFO) <<"my first info"; int valueint=10;
	LOG_IF(ERROR, valueint=10)<<" valueint=10";
}
