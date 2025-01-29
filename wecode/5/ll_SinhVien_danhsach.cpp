
#include <iostream>
#include <iomanip>
using namespace std;
#define MAXN 100

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
    for(int i = 0; i < n; i++)
    {
        SinhVien sv;
        Input(sv);
        cin.ignore();
        addtail(L, sv);
    }
}
void OutputSV(SinhVien sv)
{
    cout << sv.MASV << "\t"
         << sv.HoTen << "\t"
         << sv.NgaySinh << "\t"
         << sv.GioiTinh << "\t"
         << sv.DiemToan << "\t"
         << sv.DiemLy << "\t"
         << sv.DiemHoa << "\t";
    if (abs(sv.DTB - int(sv.DTB * 100 + 0.5) / 100.0) < 0.01) 
        cout << setprecision(3) << sv.DTB << endl;
}
void Output(LIST L)
{
    NODE* p = L.pHead;
    while( p != NULL)
    {
        OutputSV(p->info);
        p = p->pNext;
    }
}
//insert my code

int main() {
    LIST L;
    L.pHead=L.pTail=NULL;
    Input(L);
    Output(L);
    return 0;
}
