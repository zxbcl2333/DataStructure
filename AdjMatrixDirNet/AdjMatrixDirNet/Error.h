#pragma once
#include <iostream>
using namespace std;
enum Status {
    SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW, RANGE_ERROR, DUPLICATE_ERROR,
    NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED
};

// ͨ���쳣��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
//#define MAX_ERROR_MESSAGE_LEN 100
class Error
{
private:
    // ���ݳ�Ա
    string message;// �쳣��Ϣ

public:
    //  ��������
    Error(const string mes = "һ�����쳣!");	// ���캯�� 
    ~Error(void) {};					// ��������	
    string Show() const;					// ��ʾ�쳣��Ϣ
};
