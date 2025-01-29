
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Cấu trúc của một node
struct NODE
{
    int info;
    NODE *pNext;
};
// Cấu trúc của một DSLK
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

NODE *CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    // if (p == NULL)
    //		exit(1);

    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
// Insert code here
void CreateList(LIST &L)
{
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        NODE *p = CreateNode(t);
        if (L.pHead == NULL)
        {
            L.pHead = p;
            L.pTail = p;
        }
        else
        {
            L.pTail->pNext = p;
            L.pTail = p;
        }
    }
}

NODE *SeparateHead(LIST &L)
{
    if (L.pHead == NULL)
        return NULL;
    NODE *p = L.pHead;
    L.pHead = L.pHead->pNext;
    p->pNext = NULL;
    return p;
}

void PrintList(NODE *pHead)
{
    NODE *p = pHead;
    if (p == NULL)
        cout << "Empty List.";
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}
// Insert code here
int main()
{
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    NODE *p = SeparateHead(L);
    if (p != NULL)
        cout << p->info << endl;
    PrintList(L.pHead);

    return 0;
}

// Input: 5 1 2 3 4 5
// Output: 1 2 3 4 5
// Input: 0
// Output: Empty List.
// Input: 1 1
// Output: 1 Empty List.
// Input: 2 1 2
// Output: 1 2 Empty List.