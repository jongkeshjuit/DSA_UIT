
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>
#include <string.h>
using namespace std;

#define MAXN 100

struct Ngay {
    int d, m, y;
};
struct SinhVien{
    char MASV[10];
    char HoTen[MAXN];
    Ngay NamSinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
// insert code here
void Nhap(SinhVien* &a, int &n)
{
    cin >> n;
    a = new SinhVien[n];
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> ws;
        cin.getline(a[i].MASV, 10);
        cin.getline(a[i].HoTen, MAXN);
        cin >> a[i].NamSinh.d >> a[i].NamSinh.m >> a[i].NamSinh.y;
        cin >> a[i].GioiTinh;
        cin >> a[i].DiemToan >> a[i].DiemLy >> a[i].DiemHoa;
        a[i].DTB = (a[i].DiemToan + a[i].DiemLy + a[i].DiemHoa) / 3.0;
    }
}

void TimTheoNamSinh(SinhVien* a, int n, int namsinh)
{
    bool found = false;
    for(int i = 0 ; i < n ; ++i)
    {
        if(a[i].NamSinh.y == namsinh)
        {
            found = true;
            cout << a[i].MASV<< "\t"
            << a[i].HoTen << "\t"
            << a[i].NamSinh.d << "/" << a[i].NamSinh.m <<"/" << a[i].NamSinh.y <<"\t"
            << a[i].GioiTinh << "\t"
            << a[i].DiemToan << "\t"
            << a[i].DiemLy << "\t"
            << a[i].DiemHoa << "\t"
            << setprecision(3) << a[i].DTB << endl;
        }
    }
    if(!found)
        cout << "Not found in list." << endl;
}
// insert code here

int main() {
    SinhVien *A;
    int n, namsinh;
    cin >> namsinh;
    Nhap(A, n);
    TimTheoNamSinh(A, n, namsinh);
    return 0;
}

