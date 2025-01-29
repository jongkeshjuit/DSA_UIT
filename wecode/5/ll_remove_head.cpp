#include <bits/stdc++.h>
 
using namespace std;

struct NODE
{
	int info;
	NODE* pNext;
};

NODE* CreateNode(int x)
{
	NODE* p = new NODE();
	p->info = x;
	p->pNext = nullptr;
	return p;
}

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void CreateEmptyList(LIST& L)
{
	L.pHead = L.pTail = nullptr;
}

void addTail(LIST& L, int value) {
    NODE* p = CreateNode(value);
    if (L.pHead == NULL) {            
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;         
        L.pTail = p;
    }
}


void CreateList(LIST& L)
{
	int value;
    while (true) {
        cin >> value;
        if (value == -1) break;                       
        addTail(L, value); // addHead(L, value);
    }
}

void RemoveHead(LIST& L)
{
	if(L.pHead == nullptr)
		return;
	L.pHead = L.pHead->pNext;
}

void PrintList(LIST L)
{
	NODE* p = L.pHead;
	if( p == nullptr)
	{
		cout << "Empty List.";
		return;
	}
	while( p!= nullptr )
	{
		cout << p->info << " ";
        p = p->pNext;
	}

}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
	RemoveHead(L);
    PrintList(L);

    return 0;
}
