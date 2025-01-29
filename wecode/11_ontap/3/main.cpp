#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    Hocsinh *table;
};

void CreateHashtable(Hashtable &, int);
int Insert(Hashtable &, Hocsinh);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}

void CreateHashtable(Hashtable &ht, int m) {
    ht.table = new Hocsinh[m];
    if (ht.table == NULL)
        exit(1);
    for (int i = 0; i < m; i++) {
        ht.table[i].Maso = EMPTY;
    }
    ht.M = m;
    ht.n = 0;
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i ++) {
        Hocsinh hs = ht.table[i];
        if (hs.Maso > 0)
            cout << '[' << hs.Maso << ",  " << hs.Hoten << "  , " << hs.Gioitinh << ", " << hs.Namsinh << ", " << hs.TBK << "]\n";
        else
            cout << "[" << hs.Maso <<  ",  " << "  , " << ", " << ", " << "]\n";
    }
}
void DeleteHashtable(Hashtable &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int Insert(Hashtable &ht, Hocsinh x) {
// Kiểm tra Load Factor trước khi chèn
    if ((float)(ht.n + 1)/ht.M > LOAD) {
        return 0;
    }
    // Kiểm tra mã số hợp lệ
    if (x.Maso <= 0) {
        return 0;
    }
    int i = 0;
    int M = ht.M;
    int index;

    do {
        // Hàm băm chính + thăm dò tuyến tính: h(key,i) = ((key % M) + i) % M
        index = ((x.Maso % M) + i) % M;
        // TH1: Tìm được vị trí cần chèn (flag = EMPTY hoặc DELETE)
        if (ht.table[index].Maso == EMPTY ||
            ht.table[index].Maso == DELETE) {
            ht.table[index] = x;
            ht.n++;
            return 1;
        }
        // TH2: Giá trị cần chèn đã có trong HashTable
        // (flag = OCCUPIED và Maso = x)
        if (ht.table[index].Maso == x.Maso) {
            return 0;
        }
        // TH3: Băm lại (flag = OCCUPIED và Maso ≠ x)
        // -> Tự động xử lý bằng cách tăng i và quay lại vòng lặp
        i++;

    } while (i < M);
    return 0;
}

