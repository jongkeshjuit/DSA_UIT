
#include <iostream>
using namespace std;

// insert code here
struct NODE
{
	int info;
	NODE* pNext;
};

NODE* CreateNode(int x)
{
	NODE* p = new NODE;
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

void addtail(LIST& L, int x)
{
    NODE* p = CreateNode(x);
    if(L.pHead == nullptr) L.pHead = L.pTail = p;
    else
        L.pTail->pNext = p,
        L.pTail = p;
}

void CreateList(LIST &L)
{
    int x;
    while(cin >> x && x != -1)
        addtail(L, x);
}

int count_even(NODE* pHead)
{
	int count = 0 ;
	NODE* p = pHead;
	while(p != NULL){
		if(p->info % 2 == 0)
			count++;
		p = p->pNext;
	}
	return count;
}
// insert code here


int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}

/*Input	Output
6 4 -8 2 -5 8 1 4 2 0 -1	8
-9 -3 17 1 -1	0
-1	0*/
