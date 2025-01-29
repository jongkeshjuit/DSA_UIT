
#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE {
	int info;
	NODE* pNext;
};
// Cấu trúc của một DSLK
struct LIST {
	NODE* pHead;
	NODE* pTail;
};

NODE* CreateNode(int x)
{
	NODE* p = new NODE();
	p->info = x;
	p->pNext = nullptr;
	return p;
}

void CreateEmptyList(LIST& L)
{
	L.pHead = L.pTail = nullptr;
}

void CreateList(LIST &L)
{
	int n;
    cin >> n;
    while(n != -1) {
        NODE *p = CreateNode(n);
        // Add last
        if(L.pHead == NULL) {
            L.pHead = L.pTail = p;
        }
        else {
            L.pTail->pNext = p;
            L.pTail = p;
        }
        cin >> n;
    }
}

void Join(LIST &L, LIST &L1, NODE*p, LIST &L2)
{
	if(L1.pHead == nullptr)
	{
		L.pHead = p;
		p->pNext = L2.pHead;
		if(L2.pHead != nullptr)
			L.pTail = L2.pHead;
		else
			L.pTail = p;
	}
	else
	{
		L.pHead = L1.pHead;
		L1.pTail->pNext = p;
		p->pNext = L2.pHead;
		if(L2.pHead != nullptr) 
            L.pTail = L2.pTail;
        else
            L.pTail = p;
	}

}

void PrintList(LIST L)
{
	NODE* p = L.pHead;
	while( p!= nullptr)
		cout<<p->info<<" ",
		p = p->pNext;
}

int main() {
    LIST L, L1, L2;

	int x;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	cin >> x;
	pivot=CreateNode(x);
	CreateList(L2);


	Join(L, L1, pivot, L2);
	PrintList(L);

    return 0;
}
