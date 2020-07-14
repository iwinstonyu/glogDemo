#include <iostream>
#include <glog/logging.h>
#include <windows.h>
using namespace std;


// 使用glog记录日志。
// 1. 默认是以默认格式写入到默认路径（不是运行路径），所以通常需要设置FLAGS_log_dir修改路径，
//	  并且需要设置FLAGS_alsologtostderr = true, 把日志同时输出到控制台
// 2. 低级别的日志总是会记录高级别的日志。
//    比如一条ERROR日志会记录到ERROR文件，同时也会记录到INFO文件和WARNING文件。
// 3. 不会自动创建目录，所以需要先手动创建，否则会导致创建日志文件失败。
// 4. glog目前只考虑反斜杠，没考虑到windows下的斜杆
// 5. windows下最新日志文件的符号链接暂未实现


// 以默认的文件名格式写入到指定目录中
// 例如: glogDemo.exe.DESKTOP-EBIVT21.Administrator.log.WARNING.20200714-154047.39648
void Test1(const char* exe) {
	google::InitGoogleLogging(exe);

	string logDir("log");
	CreateDirectory(logDir.c_str(), NULL);
	FLAGS_log_dir = logDir;

	FLAGS_alsologtostderr = true;
	FLAGS_colorlogtostderr = true;

	LOG(INFO) << "Hello glog info" << time(nullptr) << endl;
	LOG(WARNING) << "Hello glog warning" << time(nullptr) << endl;
	LOG(ERROR) << "Hello glog error" << time(nullptr) << endl;
}

// 以指定的文件名路径写入
// 例如: log\\INFO.20200714-154637.25672
// 由于没设置ERROR的文件参数，WARNING不会写入文件
void Test2(const char* exe) {
	google::InitGoogleLogging(exe);

	CreateDirectory("log", NULL);
	google::SetLogDestination(google::GLOG_INFO, "log/INFO.");
	google::SetLogDestination(google::GLOG_ERROR, "log/ERROR.");

	FLAGS_alsologtostderr = true;
	FLAGS_colorlogtostderr = true;

	LOG(INFO) << "Hello glog info" << time(nullptr) << endl;
	LOG(WARNING) << "Hello glog warning" << time(nullptr) << endl;
	LOG(ERROR) << "Hello glog error" << time(nullptr) << endl;
}

// 设置每个日志文件的大小为1MB
void Test3(const char* exe) {
	google::InitGoogleLogging(exe);

	string logDir("log\\log");
	CreateDirectory(logDir.c_str(), NULL);
	FLAGS_log_dir = logDir;

	FLAGS_alsologtostderr = true;
	FLAGS_colorlogtostderr = true;
	FLAGS_max_log_size = 1;

	while (true) {
		LOG(INFO) << "Hello glog info" << time(nullptr) << endl;
		LOG(WARNING) << "Hello glog warning" << time(nullptr) << endl;
		LOG(ERROR) << "Hello glog error" << time(nullptr) << endl;
	}
}

int main(int argc, char **argv) {
	Test1(argv[0]);
	
	return 0;
}