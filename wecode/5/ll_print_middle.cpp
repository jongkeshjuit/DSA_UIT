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

int midlength(LIST L) {
    int count = 0;
    NODE *p = L.pHead;
    while(p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

void Print_Middle(LIST L)
{
	if( L.pHead == nullptr)
	{
		cout << "Empty List.";
		return;
	}
	NODE* p = L.pHead;
	int mid = ( midlength(L) + 1 ) / 2;
    for (int i = 1; i < mid; ++i)
    {
        p = p->pNext;
    }
    cout << p->info;
    
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    Print_Middle(L);

    return 0;
}

/*
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

void CreateList(LIST &L)
{
    int n;
    cin >> n;
    while (n != -1) {
        if (n < 1000) {  // chỉ thêm các số < 1000
            NODE *p = CreateNode(n);
            // Thêm phần tử vào cuối danh sách
            if (L.pHead == NULL) {
                L.pHead = L.pTail = p;
            } else {
                L.pTail->pNext = p;
                L.pTail = p;
            }
        }
        cin >> n;
    }
}

void Print_Middle(LIST L)
{
    if (L.pHead == nullptr) {
        cout << "Empty List." << endl;
        return;
    }

    NODE* slow = L.pHead;
    NODE* fast = L.pHead;

    while (fast != nullptr && fast->pNext != nullptr) {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
    }
    cout << slow->info << endl;
}

int main() {
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    Print_Middle(L);
    return 0;
}

*/

/*
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

void CreateList(LIST &L)
{
    int n;
    cin >> n;
    while (n != -1) {
        if (n < 1000) {  // chỉ thêm các số < 1000
            NODE *p = CreateNode(n);
            // Thêm phần tử vào cuối danh sách
            if (L.pHead == nullptr) {
                L.pHead = L.pTail = p;
            } else {
                L.pTail->pNext = p;
                L.pTail = p;
            }
        }
        cin >> n;
    }
}

void Print_Middle(LIST L)
{
    if (L.pHead == nullptr) {
        cout << "Empty List." << endl;
        return;
    }

    NODE* slow = L.pHead;
    NODE* fast = L.pHead;

    // Sử dụng hai con trỏ để tìm phần tử giữa
    while (fast != nullptr && fast->pNext != nullptr) {
        slow = slow->pNext;        // Di chuyển con trỏ chậm
        fast = fast->pNext->pNext; // Di chuyển con trỏ nhanh
    }

    cout << slow->info << endl; // In ra phần tử giữa
}

int main() {
    LIST L;
    CreateEmptyList(L);
    CreateList(L);
    Print_Middle(L);
    return 0;
}

*/