#include "Error.h"
#include<iostream>
#include <string>
//#include <climits> 
using namespace std;

// ͨ���쳣���ʵ�ֲ���
Error::Error(const string mes)
// �����������mes����ͨ���쳣����
{
    message = mes;				// �����쳣��Ϣ
}

string Error::Show()const
// �����������ʾ�쳣��Ϣ
{
    return message ;			// ��ʾ�쳣��Ϣ	
}