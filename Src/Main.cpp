#include <iostream>
#include <glog/logging.h>
#include <windows.h>
using namespace std;


// ʹ��glog��¼��־��
// 1. Ĭ������Ĭ�ϸ�ʽд�뵽Ĭ��·������������·����������ͨ����Ҫ����FLAGS_log_dir�޸�·����
//	  ������Ҫ����FLAGS_alsologtostderr = true, ����־ͬʱ���������̨
// 2. �ͼ������־���ǻ��¼�߼������־��
//    ����һ��ERROR��־���¼��ERROR�ļ���ͬʱҲ���¼��INFO�ļ���WARNING�ļ���
// 3. �����Զ�����Ŀ¼��������Ҫ���ֶ�����������ᵼ�´�����־�ļ�ʧ�ܡ�
// 4. glogĿǰֻ���Ƿ�б�ܣ�û���ǵ�windows�µ�б��
// 5. windows��������־�ļ��ķ���������δʵ��


// ��Ĭ�ϵ��ļ�����ʽд�뵽ָ��Ŀ¼��
// ����: glogDemo.exe.DESKTOP-EBIVT21.Administrator.log.WARNING.20200714-154047.39648
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

// ��ָ�����ļ���·��д��
// ����: log\\INFO.20200714-154637.25672
// ����û����ERROR���ļ�������WARNING����д���ļ�
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

// ����ÿ����־�ļ��Ĵ�СΪ1MB
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