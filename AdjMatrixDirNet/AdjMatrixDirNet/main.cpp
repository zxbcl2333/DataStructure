#include <iostream>
#include "AdjMatrixDirNet.h"
#include "Error.h"

using namespace std;

int main() {
    try {
        // 1. ���Թ��캯��
        cout << "===== 1. ���Թ��캯�� =====" << endl;
        string cities[] = { "����", "�Ϻ�", "����", "����" };
        AdjMatrixDirNet<string> net(cities, 4, 10);
        net.Display();
        cout << endl;


        // 2. ���Բ����
        cout << "===== 2. ���Բ���� =====" << endl;
        net.InsertArc(0, 1, 300);   // ���� -> �Ϻ� 300km
        net.InsertArc(0, 2, 1200);  // ���� -> ���� 1200km
        net.InsertArc(1, 2, 800);   // �Ϻ� -> ���� 800km
        net.InsertArc(2, 3, 100);   // ���� -> ���� 100km
        net.InsertArc(3, 1, 500);   // ���� -> �Ϻ� 500km
        net.Display();
        cout << endl;

        // 3. ���Զȼ���
        cout << "===== 3. ���Զȼ��� =====" << endl;
        for (int i = 0; i < 4; i++) {
            cout << cities[i] << " - ����: " << net.CountOutDegree(i)
                << ", ���: " << net.CountInDegree(i) << endl;
        }
        cout << endl;

        // 4. ���Զ������
        cout << "===== 4. ���Զ������ =====" << endl;
        string city;
        for (int i = 0; i < 4; i++) {
            if (net.GetElem(i, city)) {  // ��������ȫ������
                cout << "����" << i << ": " << city << endl;
            }
        }
        cout << "���ݵ�����: " << net.GetOrder("����") << endl;

        // �����¶��� (��������ȫ�����)
        string newCity = "�ɶ�";
        net.InsertVertex(newCity);
        cout << "�����¶���: " << newCity << endl;
        net.InsertArc(4, 0, 500);  // �ɶ� -> ���� 500km
        net.Display();
        cout << endl;

        // 5. ����ɾ������
        cout << "===== 5. ����ɾ������ =====" << endl;
        cout << "ɾ���Ϻ�->���ݵı�" << endl;
        net.RemoveArc(1, 2);
        net.Display();

        cout << "ɾ�����ڶ���" << endl;
        net.RemoveVertex(3);
        net.Display();
        cout << endl;

        // 6. ���������Լ���
        cout << "===== 6. ���������Լ��� =====" << endl;
        for (int i = 0; i < net.GetVexNum(); i++) {
            string cityName;
            net.GetElem(i, cityName);
            cout << cityName << " - ����������: " << net.CertralityOutVex(i)
                << ", ���������: " << net.CertralityInVex(i) << endl;
        }
        cout << endl;

        // 7. ���������ھ�
        cout << "===== 7. ���������ھ� =====" << endl;
        for (int i = 0; i < net.GetVexNum(); i++) {
            string cityName;
            net.GetElem(i, cityName);
            cout << cityName << " �������ھ�����: " << net.TwoHopNgh(i) << endl;
        }
        cout << endl;

        // 8. ���Կ������캯���͸�ֵ�����
        cout << "===== 8. ���Կ����͸�ֵ =====" << endl;
        AdjMatrixDirNet<string> netCopy(net);
        cout << "�������������:" << endl;
        netCopy.Display();

        AdjMatrixDirNet<string> netAssign;
        netAssign = net;
        cout << "��ֵ�������:" << endl;
        netAssign.Display();
        cout << endl;

        // 9. �����������
        cout << "===== 9. ����������� =====" << endl;
        net.Clear();
        cout << "��պ������Ƿ�Ϊ��? " << (net.IsEmpty() ? "��" : "��") << endl;
        net.Display();

        //10.���Խ�׳��
        cout << "====10.��׳�Բ���====" << endl;
        cout << "ͳ�Ƶ�1��������" << endl;
        net.CountInDegree(1);
       

    }
    catch (Error& s) {
        cerr << s.Show() << endl;
    }

    return 0;
    
}