#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

typedef struct Data
{
    char *name;
    int age;
} Data;
typedef struct Lnode
{
    Data note;   // ����������
    Lnode *next; // ����ָ����
} Lnode, *LinkList;
bool InitList(LinkList &L) // �������⻰��LinkList &L�ȼ��� Lnode *&L��Lnode *&L��һ��ָ��ָ�������
{
    L = new Lnode;     // ��������һ��ͷ��㣬������������ΪLnode
    L->next = nullptr; // �ձ�Ҳ����˵ͷ����ָ��ָ��Ϊ��
    return true;
}
int GetLength(const LinkList &L)
{
    Lnode *p;
    int i = 0;
    p = L->next;
    while (p != nullptr)
    {
        i++;
        p = p->next;
    }
    return i;
}
bool GetElem(const LinkList &L, const int &i, Data &e)
{
    if(i < 0)
    {
        cerr << "out of range" << endl;
        return false;
    }
    Lnode *p = L->next;
    for (int j = 1; j < i + 1; ++j)
    {
        p = p->next;
        if(!p)
        {
            cerr << "out of range" << endl;
            return false;//�����ʱpΪ�գ���ζ���Ѿ���������β�ˣ�ֹͣѭ��
        }
    }
    e = p->note;
    return true;
}
size_t LocateElem(LinkList &L, Data &e)
{
    Lnode *p = L->next;
    size_t cnt = 1;
    while (p)
    {
        if (!strcmp(p->note.name,e.name))
        {
            return cnt;
        }
        ++cnt;
        p = p->next;
    }
    cerr << "not found" << endl;
    return 0;
}
bool clearlist(LinkList &L)
{
    Lnode *p, *q;
    p = L->next;
    while (p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;
    return true;
}
bool IsEmpty(const LinkList &L)
{
    if (L->next) // �ǿ�
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool DestroyList(LinkList &L)
{
    // �ж������Ƿ�Ϊ��
    if (IsEmpty(L))
    {
        cerr << "empty List!" << endl;
        return false;
    }
    while (L) // ����δ����β��
    {
        auto temp = L->next; // ��ͷָ��ָ����һ�����
        delete L;
        L = temp;
    }
    return true;
}
int main()
{

    system("pause");
    return EXIT_SUCCESS;
}