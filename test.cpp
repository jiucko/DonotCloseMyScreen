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
	//�ر���ʾ�� ����MSDN��������������1���� ��ʾ��ʾ�����ڵ��ܺ�״̬��
	//Sleep(10000);

	while (true)
	{
		SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
		SendMessage(FindWindow(0, 0), WM_SYSCOMMAND, SC_MONITORPOWER, -1); //����ʾ��
		Sleep(5*1000);
	}
	return 0;
}

