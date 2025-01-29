
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

// Hàm tạo danh sách rỗng
void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}

// Hàm thêm node vào cuối danh sách
void AddTail(LIST &L, int x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

// Hàm tạo danh sách
void CreateList(LIST &L) {
    int x;
    while (true) {
        cin >> x;
        if (x == -1) break;
        AddTail(L, x);
    }
}

// Hàm phân vùng danh sách
void Partition(LIST &L, LIST &L1, NODE* &pivot, LIST &L2) {
    if (L.pHead == NULL) return;
    
    pivot = L.pHead;
    L.pHead = L.pHead->pNext;
    pivot->pNext = NULL;
    
    NODE* p = L.pHead;
    while (p != NULL) {
        NODE* next = p->pNext;
        if (p->info <= pivot->info) {
            AddTail(L1, p->info);
        } else {
            AddTail(L2, p->info);
        }
        p = next;
    }
    
    L.pHead = L.pTail = NULL;
}

// Hàm in danh sách
void PrintList(LIST L) {
    if (L.pHead == NULL) {
        cout << "Empty List.";
    } else {
        NODE* p = L.pHead;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
    cout << endl;
}

int main() {
    LIST L, L1, L2;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);
	CreateList(L);

	if(L.pHead==NULL) {
		cout << "Empty List.";
		return 0;
	}

	Partition(L, L1, pivot, L2);

	cout << pivot->info << endl;
	PrintList(L1);
	PrintList(L2);
	PrintList(L);

    return 0;
}
