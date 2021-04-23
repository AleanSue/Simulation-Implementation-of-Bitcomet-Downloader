#include"boost/filesystem.hpp"
#include"client.h"

void helloworld(const httplib::Request &req, httplib::Response &rsp)
{
	rsp.set_content("<html><h1>helloworld<h1><html>","text/html");
	rsp.status = 200;
}

void Scandir()
{
	const char *ptr = "./";
	boost::filesystem::directory_iterator begin(ptr);//定义一个目录迭代器对象
	boost::filesystem::directory_iterator end;
	for (; begin != end; ++begin) {
		//begin->status()  目录中当前文件的状态信息
		//boost::filesystem::is_dirctory() 判断当前文件是否是一个目录
		if (boost::filesystem::is_directory(begin->status())) {
			//begin->path().string() 获取当前迭代文件的文件名
			std::cout << begin->path().string() << "是一个目录\n";
		}
		else {
			std::cout << begin->path().string() << "是一个普通文件\n";
			// begin->path().filename()  只要文件名，不要路径
			std::cout << "文件名：" << begin->path().filename().string() << std::endl;
		}
	}
}

void test()
{
/*
	Scandir();
	Sleep(1111111);
	httplib::Server srv;

	srv.Get("/",helloworld);

	srv.listen("0.0.0.0",9000);*/
}
void ClientRun()
{
	//Sleep(1);
	Client cli;
	cli.Start();
}
int main(int argc, char *argv[])
{
	//在主线程中要运行客户端和服务器端模块
	//创建一个线程运行客户端模块，主线程运行服务器端模块
	std::thread thr_client(ClientRun);//若客户端运行，而服务器端还未启动
	Server srv;
	srv.Start();
	return 0;
}
