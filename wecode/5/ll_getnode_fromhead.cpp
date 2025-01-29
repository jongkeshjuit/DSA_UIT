
#include <iostream>
#include <string.h>

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

int get_nth_node_from_head(NODE* p, int k) {

	int count = 1;
    while( p!= nullptr && count != k)
    {
    	count ++;
    	p = p->pNext;
    }  
    if(p == nullptr)
        return -1; 
    else
    	return p->info;
    
}

int main() {
    LIST L;
	int k;
	CreateEmptyList(L);
	CreateList(L);

	std::cin >> k;
	cout << get_nth_node_from_head(L.pHead, k);

    return 0;
}
