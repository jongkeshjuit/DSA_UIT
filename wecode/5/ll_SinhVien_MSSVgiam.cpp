#include <iomanip>
#include <iostream>
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
struct NODE
{
    SinhVien info;
    NODE* pNext;
};
struct LIST
{
    NODE* pHead;
    NODE* pTail;
};
NODE* createnode(SinhVien x)
{
    NODE* p = new NODE();
    if(p == nullptr) exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}
void addtail(LIST &L, SinhVien x)
{
    NODE* p = createnode(x);
    if(L.pHead == NULL)
        L.pHead = L.pTail = p;
    else
        L.pTail->pNext = p,
        L.pTail = p;
}
void Input(LIST &L)
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i)
    {
        cin >> ws;
        SinhVien sv;
        Input(sv);
        addtail(L, sv);
    }
}

void Insert_Decreasing(LIST &L, SinhVien x)
{
    NODE* p = createnode(x);
    if(L.pHead == NULL)
    {                
        L.pHead = L.pTail = p;
        return;
    }

    // Trường hợp thêm vào đầu danh sách
    if(strcmp(x.MASV, L.pHead->info.MASV) >= 0)
    {
        p->pNext = L.pHead;
        L.pHead = p;
        return;
    }

    NODE* current = L.pHead;
    NODE* prev = NULL;
    while(current != NULL && strcmp(current->info.MASV, x.MASV) > 0)
    {
        prev = current;
        current = current->pNext;
    }

    // Thêm vào giữa danh sách
    prev->pNext = p;
    p->pNext = current;

    // Trường hợp thêm vào cuối danh sách
    if(current == NULL)
        L.pTail = p;
}

void OutputSV(SinhVien sv)
{
    cout << sv.MASV << "\t"
         << sv.HoTen << "\t"
         << sv.NgaySinh << "\t"
         << sv.GioiTinh << "\t"
         << sv.DiemToan << "\t"
         << sv.DiemLy << "\t"
         << sv.DiemHoa << "\t"
         << setprecision(3) << sv.DTB << endl;
}
void Output(LIST L)
{
    NODE* p = L.pHead;
    while( p != NULL)
    {
        OutputSV(p->info);
        p = p->pNext;
    }
    return;
}

//insert my code

int main() {
    LIST L;
    L.pHead=L.pTail=NULL;
    Input(L); // DS đầu vào mặc định có thứ tự Giảm dần theo MASV

    cin.ignore();
    SinhVien sv;// Sinh viên cần chèn
    Input(sv);

    Insert_Decreasing(L, sv);

    Output(L);

    return 0;
}
