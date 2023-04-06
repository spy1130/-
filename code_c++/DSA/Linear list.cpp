#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#define ElemType int
#define MAXSIZE 20
using namespace std;

typedef struct SqList
{
    ElemType *elem; // ˳�����Ա�ı�ͷ
    int length;     // ˳�����Ա�ĳ���
} SQL;
bool InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE]; // �ڶ��������ڴ�
    if (!L.elem)
    {
        cerr << "error" << endl;
        return false;
    }
    L.length = 0; // �趨���Ա���Ϊ0
    return 1;
}
bool InsertList(SqList &L, const ElemType &e, const int &i)
{
    // �ж����Ա����Ƿ�С����󳤶�MAXSIZE
    if (L.length == MAXSIZE)
    {
        cerr << "can not insert!" << endl;
        return false;
    }
    if (i < 0 || i > L.length)
    {
        cerr << "wrong insert position!" << endl;
        return false;
    }
    if (L.length > 0)
    {
        // ��λ�ڲ���λ��֮���Ԫ���������Ų��һλ
        for (int p = L.length - 1; p >= i; --p)
        {
            L.elem[p + 1] = L.elem[p];
        }
    }
    // ����Ԫ��
    L.elem[i] = e;
    // ���Ա���+1
    L.length += 1;
    return true;
    // �㷨ʱ�临�Ӷȣ�O(n)
}
void PrintList(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}
bool EraseList(SqList &L, const int &i)
{
    // �쳣�ж�
    if (i < 0 || i > L.length)
    {
        cerr << "wrong erase position!" << endl;
        return false;
    }
    if (L.length == 0)
    {
        cerr << "List has no length" << endl;
        return false;
    }
    // ��λ��ɾ��λ��֮���Ԫ��������ǰŲ��һλ
    for (int p = i + 1; p < L.length; ++p)
    {
        L.elem[p - 1] = L.elem[p];
    }
    // ���Ա���-1
    L.length -= 1;
    return true;
    // �㷨ʱ�临�Ӷȣ�O(n)
}
bool GetELem(const SqList &L, const size_t i, ElemType &e)
{
    if (i < 1 || i > MAXSIZE)
    {
        cerr << "out of range" << endl;
        return false;
    }
    e = L.elem[i - 1];
    return true;
}
int LocateList(const SqList &L, const ElemType &e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.elem[i] == e)
        {
            return i + 1; // ���ҳɹ������������Ԫ�صĵ�һ���±�ֵ
        }
    }
    return 0; // δ���ҵ���ӦԪ�أ�����0
    // �㷨ʱ�临�Ӷȣ�O(n)
}
void CLearList(SqList &L)
{
    L.length = 0;
}
bool IsEmpty(const SqList &L)
{
    return static_cast<bool>(L.length);
}
void DestroyList(SqList &L)
{
    if (L.elem)
    {
        delete L.elem;
    }
}

int main()
{
    SQL list;
    int e;
    InitList(list);
    srand(time(nullptr)); // �õ�ǰʱ����Ϊ����
    for (int i = 0; i < MAXSIZE; i++)
    {       
        int random = (rand() % (100 - 1)) + 1;
        InsertList(list, random, i);
    }
    GetELem(list, 1, e);
    int loc = LocateList(list, e);
    cout << e << " " << loc << endl;
    PrintList(list);
    EraseList(list, 3);
    PrintList(list);
    CLearList(list);
    IsEmpty(list);
    DestroyList(list);
    system("pause");
    return EXIT_SUCCESS;
}