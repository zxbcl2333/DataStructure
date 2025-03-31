#pragma once
#include "Error.h"
#include <iostream>
#include <cstring>
#include <climits> 
const int INF = INT_MAX;
using namespace std;


template <class ElemType>
class AdjMatrixDirNet {
protected:
    int vexNum;//������Ŀ
    int vexMaxNum; //��󶥵���Ŀ
    int arcNum;//����
    int** arcs;//�ڽӾ���
    ElemType* vertexes;//��������
    mutable Status* tag;//����״̬

public:
    AdjMatrixDirNet(ElemType es[], int vertexNum, int vertexMaxNum = 100);//��֪��������Ĺ��캯��
    AdjMatrixDirNet(int vertexMaxNum = 100); //Ĭ�Ϲ��캯��
    AdjMatrixDirNet(const AdjMatrixDirNet& g); //�������캯��
    ~AdjMatrixDirNet(); //��������

    void Clear(); //���ͼ
    bool IsEmpty(); //�п�
    AdjMatrixDirNet& operator=(const AdjMatrixDirNet& g); //��ֵ���������
    int GetOrder(const ElemType& d) const; //��ȡ����d������
    Status GetElem(int v, ElemType& d) const; //��ȡ����d��Ԫ��ֵ
    void Display() const; //��ӡͼ����Ϣ
    int GetVexNum() const; //��ȡ��ǰ��������

    int CountOutDegree(int v) const;//ͳ�ƶ���v�ĳ���
    int CountInDegree(int v) const;//ͳ�ƶ���v�����   

    void RemoveVertex(int v);//ɾ������v
    void RemoveArc(int v1, int v2);//ɾ����
    void InsertArc(int v1, int v2, int weight);//���뻡
    void InsertVertex(ElemType& v);//��Ӷ���

    int CertralityOutVex(int v);//��Ȩ����������
    int CertralityInVex(int v);//��Ȩ���������
    int TwoHopNgh(int v);//2-hop���ھ�����
};
