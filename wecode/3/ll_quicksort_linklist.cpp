
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

NODE* CreateNode(int x) {
	NODE* p = new NODE;
	p->info = x;
	p->pNext = NULL;
	return p;
}

void AddTail(LIST &L, NODE* p) {
	if (L.pHead == NULL) {
		L.pHead = L.pTail = p;
	}
	else {
		L.pTail->pNext = p;
		L.pTail = p;
    }
}

void CreateEmptyList(LIST &L) {
	L.pHead = L.pTail = NULL;
}

void CreateList(LIST &L) {
	int n, x;
    cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		AddTail(L, CreateNode(x));
	}
}

int length(NODE *p) {
    int i = 0;
    while (p) {
        i++;
        p = p->pNext;
    }
    return i;
}

void PrintList(NODE* p) {
	if (p == NULL) {
		cout << "Empty List.";
	}
	else {
        cout << length(p) << endl;
		while (p) {
			cout << p->info << " ";
			p = p->pNext;
		}
	}
}

NODE* partition(NODE* low, NODE* high) {
    int pivot = high->info;
    NODE* i = low->pNext;
    NODE* j = low;
    
    while (j != high) {
        if (j->info <= pivot) {
            swap(i->info, j->info);
            i = i->pNext;
        }
        j = j->pNext;
    }
    swap(i->info, high->info);
    return i;
}

void quickSort(NODE* low, NODE* high) {
    if (low != NULL && high != NULL && low != high && low != high->pNext) {
        NODE* pivot = partition(low, high);
        quickSort(low, pivot);
        quickSort(pivot->pNext, high);
    }
}

void quicksort_ascending(LIST &L) {
    if (L.pHead == NULL || L.pHead->pNext == NULL) return;
    
    NODE* tail = L.pHead;
    while (tail->pNext != NULL) {
        tail = tail->pNext;
    }
    
    quickSort(L.pHead, tail);
}

int main() {
    LIST L;
	CreateEmptyList(L);
	CreateList(L);
    quicksort_ascending(L);
    PrintList(L.pHead);
    return 0;
}
