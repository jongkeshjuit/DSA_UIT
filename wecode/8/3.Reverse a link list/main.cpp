
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

// insert code here
typedef struct NODE* node;
void CreateEmptyList(LIST &L)
{
    L.pHead = L.pTail = nullptr;
}
node makenode(int x)
{
    node p = new NODE;
    p->info = x;
    p->pNext = nullptr;
    return p;
}
void addtail(LIST& L, int x)
{
    node p = makenode(x);
    if(L.pHead == nullptr)
        L.pHead = L.pTail = p;
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void CreateList(LIST& L)
{
    int x;
    while( cin >> x && x != -1)
        addtail(L, x);
}
void Reverse_LinkedList(LIST& L)
{
    node truoc = nullptr;
    node hientai = L.pHead;
    node ketiep = nullptr;
    while(hientai != nullptr)
    {
        ketiep = hientai->pNext;
        hientai->pNext = truoc;
        truoc = hientai;
        hientai = ketiep;
    }
    L.pHead = truoc;
}
// insert code here
void PrintList(const LIST &L)  {
	NODE* p;

	if (L.pHead == NULL)
		cout << "Empty List.";
	else {
		p = L.pHead;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

int main() {
    LIST L;

	CreateEmptyList(L);
	CreateList(L);

	Reverse_LinkedList(L);

	PrintList(L);

    return 0;
}
