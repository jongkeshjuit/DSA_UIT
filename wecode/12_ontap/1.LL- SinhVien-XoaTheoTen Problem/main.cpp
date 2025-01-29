
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void Input(SinhVien &a){
    cin.getline(a.MASV, 10);
    cin.getline(a.HoTen, 100);
    cin.getline(a.NgaySinh, 12);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
//insert my code

struct node
{
    SinhVien info;
    node* pnext;
};
struct LIST
{
    node* pHead;
    node* pTail;
};
node* createnode(SinhVien x)
{
    node *p = new node();
    p->info = x;
    p->pnext = nullptr;
    return p;
}
void addtail(LIST &l, node* p )
{
    if(l.pHead == nullptr)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pnext = p;
        l.pTail = p;
    }
    return;
}
void Input(LIST &L)
{
    int n;
    cin >> n ;
    for(int i=0; i<n;i++)
    {
        cin >> ws;
        SinhVien x;
        Input(x);
        addtail(L, createnode(x));
    }
    return;
}
void Output(LIST L)
{
    node* p = L.pHead;
    while(p!=nullptr)
    {
        cout << p->info.MASV<<"\t"
             << p->info.HoTen<<"\t"
             << p->info.NgaySinh<<"\t"
             << p->info.GioiTinh<<"\t"
             << p->info.DiemToan<<"\t"
             << p->info.DiemLy<<"\t"
             << p->info.DiemHoa<<"\t"
             << setprecision(3) << p->info.DTB << endl;
        p = p->pnext;
    }
    return;
}
void DeleteX(LIST &L, string hoTenCanXoa) {
    node* p = L.pHead;
    node* prev = NULL;
    while (p != NULL) {
        if (p->info.HoTen == hoTenCanXoa) {
            if (prev == NULL) {
                L.pHead = p->pnext;
            } else {
                prev->pnext = p->pnext;
            }
            if (p == L.pTail) {
                L.pTail = prev;
            }
            node* temp = p;
            p = p->pnext;
            delete temp;
        } else {
            prev = p;
            p = p->pnext;
        }
    }
}
//insert my code

int main() {
    char hoTenCanXoa[100];
    cin.getline(hoTenCanXoa, 100);

    LIST L;
    L.pHead=L.pTail=NULL;
    Input(L);

    DeleteX(L, hoTenCanXoa);

    Output(L);

    return 0;
}
