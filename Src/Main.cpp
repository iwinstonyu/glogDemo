#include <iostream>
#include <glog/logging.h>
using namespace std;

int main(int argc, char **argv) {
	google::InitGoogleLogging(argv[0]);
	google::SetLogDestination(google::GLOG_INFO, ".");
	FLAGS_alsologtostderr = true;
	FLAGS_colorlogtostderr = true;

	LOG(INFO) << "Hello glog" << endl;
	LOG(ERROR) << "Hello glog" << endl;
	
	return 0;
}