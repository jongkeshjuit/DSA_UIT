
#include <iostream>
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

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}

/*
struct Node {
    int data;           
    Node* next;       
};

struct LIST {
    Node* pHead;     
    Node* pTail;       
};


void CreateEmptyList(LIST& L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

Node* createNode(int value) {
    Node* p = new Node;
    p->data = value;
    p->next = NULL;
    return p;
}


void addTail(LIST& L, int value) {
    Node* p = createNode(value);
    if (L.pHead == NULL) {            
        L.pHead = L.pTail = p;
    } else {
        L.pTail->next = p;         
        L.pTail = p;
    }
}


void CreateList(LIST& L) {
    int value;
    while (true) {
        cin >> value;
        if (value == -1) break;                       
        addTail(L, value); // addHead(L, value);
    }
}

int count_even(Node* head) {
    int count = 0;
    Node* temp = head;
    ...
    return count;
}

*/