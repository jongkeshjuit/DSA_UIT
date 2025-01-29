#include <iostream>
using namespace std;
//Write your code here
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
void CreateEmptyList(LIST &L) {
    L.pHead = L.pTail = NULL;
}
// Hàm tạo node mới
NODE* CreateNode(int value)
{
    NODE *p = new NODE;
    p->info = value;
    p->pNext = NULL;
    return p;
}
// Hàm tạo danh sách từ input
void CreateList(LIST &L) {
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
// Hàm đếm số phần tử của danh sách
int length(LIST L) {
    int count = 0;
    NODE *p = L.pHead;
    while(p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}
//Write your code here
int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);

    cout << length(L);
    return 0;
}
// Kết quả là số phần tử của danh sách
// Input: 1 2 3 4 5 -1
// Output: 5
// Input: 1 2 3 4 5 6 7 8 9 10 -1
// Output: 10
// Input: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1
// Output: 15
// Input: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 -1
// Output: 20
