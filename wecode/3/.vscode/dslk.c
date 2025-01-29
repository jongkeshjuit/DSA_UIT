#include<iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

struct List
{
    NODE *pHead;
    NODE *pTail;
}

void CreateEmptyList(List &l)
{
    l.pHead = l.pTail = NULL;
}

NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->next = NULL;
    return p;
}

void AddHead(List &l, NODE *p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->next = l.pHead;
        l.pHead = p;
    }
}

void AddTail(List &l, NODE *p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->next = p;
        l.pTail = p;
    }
}

void AddAfterQ(List &l, NODE *p, NODE *q)
{
    if(q == NULL)
        AddHead(l, p);
    else if(q == l.pTail)
        AddTail(l, p);
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

void AddBeforeQ(List &l, NODE *p, NODE *q)
{
    if(q == NULL)
        AddHead(l, p);
    else if(q == l.pHead)
    {
        p->next = l.pHead;
        l.pHead = p;
    }
    else
    {
        NODE *g = l.pHead;
        while(g->next != q)
            g = g->next;
        g->next = p;
        p->next = q;
    }
}

void RemoveHead(List &l)
{
    if(l.pHead == NULL)
        return;
    NODE *p = l.pHead;
    l.pHead = l.pHead->next;
    delete p;
    if(l.pHead == NULL)
        l.pTail = NULL;
}

void RemoveTail(List &l)
{
    if(l.pHead == NULL)
        return;
    if(l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = l.pTail = NULL;
        return;
    }
    NODE *p = l.pHead;
    while(p->next != l.pTail)
        p = p->next;
    delete l.pTail;
    l.pTail = p;
    l.pTail->next = NULL;
}

void RemoveAfterQ(List &l, NODE *q)
{
    if(q == NULL)
        RemoveHead(l);
    else if(q == l.pTail)
        return;
    else
    {
        NODE *p = q->next;
        q->next = p->next;
        delete p;
        if(q->next == NULL)
            l.pTail = q;
    }
}

void RemoveBeforeQ(List &l, NODE *q)
{
    if(q == NULL)
        return;
    if(q == l.pHead)
        return;
    if(q == l.pHead->next)
    {
        RemoveHead(l);
        return;
    }
    NODE *g = l.pHead;
    while(g->next->next != q)
        g = g->next;
    NODE *p = g->next;
    g->next = q;
    delete p;
}

void RemoveQ(List &l, NODE *q)
{
    if(q == NULL)
        return;
    if(q == l.pHead)
    {
        RemoveHead(l);
        return;
    }
    if(q == l.pTail)
    {
        RemoveTail(l);
        return;
    }
    NODE *g = l.pHead;
    while(g->next != q)
        g = g->next;
    g->next = q->next;
    delete q;
}

void RemoveX(List &l, int x)
{
    NODE *p = l.pHead;
    while(p != NULL && p->data != x)
        p = p->next;
    if(p == NULL)
        return;
    RemoveQ(l, p);
}

void RemoveAllX(List &l, int x)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        if(p->data == x)
        {
            NODE *q = p;
            p = p->next;
            RemoveQ(l, q);
        }
        else
            p = p->next;
    }
}

void RemoveAllNegative(List &l)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        if(p->data < 0)
        {
            NODE *q = p;
            p = p->next;
            RemoveQ(l, q);
        }
        else
            p = p->next;
    }
}

void RemoveAllPositive(List &l)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        if(p->data > 0)
        {
            NODE *q = p;
            p = p->next;
            RemoveQ(l, q);
        }
        else
            p = p->next;
    }
}

void RemoveAllOdd(List &l)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        if(p->data % 2 != 0)
        {
            NODE *q = p;
            p = p->next;
            RemoveQ(l, q);
        }
        else
            p = p->next;
    }
}

void RemoveAllEven(List &l)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        if(p->data % 2 == 0)
        {
            NODE *q = p;
            p = p->next;
            RemoveQ(l, q);
        }
        else
            p = p->next;
    }
}

void RemoveAllDuplicate(List &l)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        NODE *q = p->next;
        while(q != NULL)
        {
            if(q->data == p->data)
            {
                NODE *g = q;
                q = q->next;
                RemoveQ(l, g);
            }
            else
                q = q->next;
        }
        p = p->next;
    }
}

void CreateList(List &l)
{
    int n;
    cin >> n;
    CreateEmptyList(l);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        NODE *p = CreateNode(x);
        AddTail(l, p);
    }
}

void PrintList(List l)
{
    NODE *p = l.pHead;
    while(p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    List l;
    CreateList(l);
    PrintList(l);
    RemoveAllDuplicate(l);
    PrintList(l);
    return 0;
}