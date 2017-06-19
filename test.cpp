#include <iostream>
#include <stdio.h>
#include <windows.h>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int Display();

int main()
{
	Display();
	return 0;
}

int Display()
{
	//SendMessage(FindWindow(0, 0), WM_SYSCOMMAND, SC_MONITORPOWER, 2);
	//关闭显示器 根据MSDN，这个参数如果是1，则 表示显示器处于低能耗状态。
	//Sleep(10000);

	while (true)
	{
		SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
		SendMessage(FindWindow(0, 0), WM_SYSCOMMAND, SC_MONITORPOWER, -1); //打开显示器
		Sleep(5*1000);
	}
	return 0;
}

