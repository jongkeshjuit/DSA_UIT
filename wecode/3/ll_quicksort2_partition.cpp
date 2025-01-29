
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

// Hàm tạo node mới
NODE* CreateNode(int x) {
    NODE* p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

// Hàm tạo danh sách rỗng
void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}

// Hàm thêm node vào cuối danh sách
void AddTail(LIST &L, int x) {
    NODE* p = CreateNode(x);
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

// Hàm nối danh sách L1, pivot và L2 thành L
void Join(LIST &L, LIST &L1, NODE* pivot, LIST &L2) {
    L.pHead = L1.pHead;
    if (L1.pHead == NULL) {
        L.pHead = pivot;
    } else {
        L1.pTail->pNext = pivot;
    }
    pivot->pNext = L2.pHead;
    if (L2.pHead == NULL) {
        L.pTail = pivot;
    } else {
        L.pTail = L2.pTail;
    }
    L1.pHead = L1.pTail = NULL;
    L2.pHead = L2.pTail = NULL;
}

// Hàm in danh sách
void PrintList(LIST L) {
    NODE* p = L.pHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pNext;
    }
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
