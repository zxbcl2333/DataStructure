#include "Error.h"
#include "AdjMatrixDirNet.h"


template <class ElemType>
AdjMatrixDirNet<ElemType>::AdjMatrixDirNet(ElemType es[], int vertexNum, int vertexMaxNum) {
    if (vertexMaxNum < 0) {
        throw Error("����Ķ��������Ŀ����Ϊ��!");
    }
    if (vertexMaxNum < vertexNum) {
        throw Error("������Ŀ���ܴ�������Ķ��������Ŀ!");
    }

    vexNum = vertexNum;
    vexMaxNum = vertexMaxNum;
    arcNum = 0;

    vertexes = new ElemType[vexMaxNum];
    tag = new Status[vexMaxNum];
    arcs = new int* [vexMaxNum];
    for (int i = 0; i < vexMaxNum; ++i) {
        arcs[i] = new int[vexMaxNum];
        for (int j = 0; j < vexMaxNum; ++j) {
            arcs[i][j] = INF;//Ĭ�ϸ�ֵ���
        }
    }

    for (int i = 0; i < vexNum; ++i) {
        vertexes[i] = es[i];
        tag[i] = UNVISITED;
    }
}

template <class ElemType>
AdjMatrixDirNet<ElemType>::AdjMatrixDirNet(int vertexMaxNum) {
    if (vertexMaxNum < 0) {
        throw Error("����Ķ��������Ŀ����Ϊ��!");
    }
    vexNum = 0;
    vexMaxNum = vertexMaxNum;
    arcNum = 0;

    vertexes = new ElemType[vexMaxNum];
    tag = new Status[vexMaxNum];
    arcs = new int* [vexMaxNum];
    for (int i = 0; i < vexMaxNum; ++i) {
        arcs[i] = new int[vexMaxNum];
        for (int j = 0; j < vexMaxNum; ++j) {
            arcs[i][j] = INF;
        }
    }
}


template <class ElemType>
AdjMatrixDirNet<ElemType>::AdjMatrixDirNet(const AdjMatrixDirNet& g) {
    vexNum = g.vexNum;
    vexMaxNum = g.vexMaxNum;
    arcNum = g.arcNum;

    vertexes = new ElemType[vexMaxNum];
    tag = new Status[vexMaxNum];
    arcs = new int* [vexMaxNum];
    for (int i = 0; i < vexMaxNum; ++i) {
        arcs[i] = new int[vexMaxNum];
        for (int j = 0; j < vexMaxNum; ++j) {
            arcs[i][j] = g.arcs[i][j];
        }
    }

    for (int i = 0; i < vexNum; ++i) {
        vertexes[i] = g.vertexes[i];
        tag[i] = g.tag[i];
    }
}

template <class ElemType>
AdjMatrixDirNet<ElemType>::~AdjMatrixDirNet() {
    delete[] vertexes;
    delete[] tag;
    for (int i = 0; i < vexMaxNum; ++i) {
        delete[] arcs[i];
    }
    delete[] arcs;
}

template<class ElemType>
inline void AdjMatrixDirNet<ElemType>::Clear()
{
    vexNum = 0;
    arcNum = 0;
}

template<class ElemType>
inline bool AdjMatrixDirNet<ElemType>::IsEmpty()
{
    return vexNum == 0;
}
template <class ElemType>
AdjMatrixDirNet<ElemType>& AdjMatrixDirNet<ElemType>::operator=(const AdjMatrixDirNet& g) {
    if (this != &g) {
        delete[] vertexes;
        delete[] tag;
        for (int i = 0; i < vexMaxNum; ++i) {
            delete[] arcs[i];
        }
        delete[] arcs;

        vexNum = g.vexNum;
        vexMaxNum = g.vexMaxNum;
        arcNum = g.arcNum;

        vertexes = new ElemType[vexMaxNum];
        tag = new Status[vexMaxNum];
        arcs = new int* [vexMaxNum];
        for (int i = 0; i < vexMaxNum; ++i) {
            arcs[i] = new int[vexMaxNum];
            for (int j = 0; j < vexMaxNum; ++j) {
                arcs[i][j] = g.arcs[i][j];
            }
        }

        for (int i = 0; i < vexNum; ++i) {
            vertexes[i] = g.vertexes[i];
            tag[i] = g.tag[i];
        }
    }
    return *this;
}

template <class ElemType>
int AdjMatrixDirNet<ElemType>::GetOrder(const ElemType& d) const {
    for (int i = 0; i < vexNum; ++i) {
        if (vertexes[i] == d) {
            return i;
        }
    }
    return -1;
}

template <class ElemType>
Status AdjMatrixDirNet<ElemType>::GetElem(int v, ElemType& d) const {
    if (v < 0 || v >= vexNum) {
        return NOT_PRESENT;
    }
    d = vertexes[v];
    return ENTRY_FOUND;
}

template <class ElemType>
void AdjMatrixDirNet<ElemType>::Display() const {
    cout << "������: " << vexNum << ", ����: " << arcNum << endl;
    cout << "�����б�: ";
    for (int i = 0; i < vexNum; ++i) {
        cout << vertexes[i] << " ";
    }
    cout << "\n�ڽӾ���:" << endl;

    cout << "   ";
    for (int j = 0; j < vexNum; ++j) {
        cout << vertexes[j] << "  ";
    }
    cout << " ����" << endl;

    for (int i = 0; i < vexNum; ++i) {
        cout << vertexes[i] << " ";
        for (int j = 0; j < vexNum; ++j) {
            if (arcs[i][j] == INF) {
                cout << "��  ";
            }
            else {
                cout << arcs[i][j] << "  ";
            }
        }
        cout << " " << CountOutDegree(i);
        cout << endl;
    }

    cout << "���";
    for (int j = 0; j < vexNum; ++j) {
        cout << "  " << CountInDegree(j);
    }
    cout << endl;
}

template <class ElemType>
int AdjMatrixDirNet<ElemType>::GetVexNum() const {
    return vexNum;
}

template <class ElemType>
int AdjMatrixDirNet<ElemType>::CountOutDegree(int v) const {
    if (v < 0 || v >= vexNum) {
        throw Error("��������Խ��!");
    }
    int count = 0;
    for (int j = 0; j < vexNum; ++j) {
        if (arcs[v][j] != INF) {
            count++;
        }
    }
    return count;
}

template <class ElemType>
int AdjMatrixDirNet<ElemType>::CountInDegree(int v) const {
    if (v < 0 || v >= vexNum) {
        throw Error("��������Խ��!");
    }
    int count = 0;
    for (int i = 0; i < vexNum; ++i) {
        if (arcs[i][v] != INF) {
            count++;
        }
    }
    return count;
}

//ɾ������
template <class ElemType>
void AdjMatrixDirNet<ElemType>::RemoveVertex(int v) {
    if (v < 0 || v >= vexNum) {
        throw Error("��������Խ��!");
    }

    vexNum--;
    for (int j = v; j < vexNum; j++) {
        vertexes[j] = vertexes[j + 1];
        tag[j] = tag[j + 1];
    }

    arcNum -= (CountOutDegree(v) + CountInDegree(v));
    for (int i = 0; i < v; i++) {
        for (int j = v; j < vexNum; j++) {
            arcs[i][j] = arcs[i][j + 1];
        }
    }
    for (int i = 0; i < v; i++) {
        for (int j = v; j < vexNum; j++) {
            arcs[j][i] = arcs[j + 1][i];
        }
    }
    for (int i = v; i <= vexNum; i++) {
        for (int j = v; j <= vexNum; j++) {
            arcs[i][j] = arcs[i + 1][j + 1];
        }
    }
}

//ɾ����
template<class ElemType>
void AdjMatrixDirNet<ElemType>::RemoveArc
(int v1, int v2)
{
    if (v1<0 || v1>= vexNum) {
        throw Error("v1��������Խ��");
    }
    if (v2<0 || v2>= vexNum) {
        throw Error("v2��������Խ��");
    }
    if (arcs[v1][v2] != INF) arcNum--;
    else arcs[v1][v2] = INF;
}

//���뻡
template<class ElemType>
void AdjMatrixDirNet<ElemType>::InsertArc(int v1, int v2, int weight)
{
    if (v1<0 || v1>= vexNum) {
        throw Error("v1��������Խ��");
    }
    if (v2<0 || v2>= vexNum) {
            throw Error("v2��������Խ��");
    }
    if (arcs[v1][v2] == INF) arcNum++;
    arcs[v1][v2] = weight;
}

//���붥��
template<class ElemType>
void AdjMatrixDirNet<ElemType>::InsertVertex(ElemType& v)
{
    if (vexNum == vexMaxNum) {
        throw Error("������󶥵�����");
    }
    vertexes[vexNum] = v;
    tag[vexNum] = UNVISITED;
    vexNum++;
}

template<class ElemType>
int AdjMatrixDirNet<ElemType>::CertralityOutVex(int v)
{
    if (v < 0 || v >= vexNum) {
        throw Error("��������Խ��!");
    }
    int ans = 0;
    for (int i = 0; i < vexNum; i++) {
        if (arcs[v][i] != INF)
        ans += arcs[v][i];
    }
    return ans;
}

template<class ElemType>
int AdjMatrixDirNet<ElemType>::CertralityInVex(int v)
{
    if (v < 0 || v >= vexNum) {
        throw Error("��������Խ��!");
    }
    int ans = 0;
    for (int i = 0; i < vexNum; i++) {
        if (arcs[i][v] != INF)
        ans += arcs[i][v];
    }
    return ans;
}

template<class ElemType>
int AdjMatrixDirNet<ElemType>::TwoHopNgh(int v)
{
    if (v < 0 || v >= vexNum) {
        throw Error("��������Խ��!");
    }
    int ans = 0;
    for (int i = 0; i < vexNum; i++) {
        if (arcs[v][i] != INF) {
            for (int j = 0; j < vexNum; j++) {
                    if (arcs[i][j] != INF && tag[j]==UNVISITED) {
                    ans++;
                    tag[j] = VISITED;
                }
            }
        }
    }
    return ans;
}
// ��ʽʵ����ģ��
template class AdjMatrixDirNet<std::string>;