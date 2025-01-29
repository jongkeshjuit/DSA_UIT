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
int Search(Hashtable, int, int &);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
int main()
{
    Hashtable hashtable;

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Search(hashtable, k, nprob) >- 1) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG TIM THAY" << endl;
        }
    }
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

int Search(Hashtable ht, int maso, int &nprob) {
    // insert code here
    nprob = 0; // Số lần dò tìm ban đầu là 0
    int M = ht.M; // Kích thước bảng băm

    for (int i = 0; i < M; i++) { // Thăm dò tối đa M lần
        nprob++; // Tăng số lần dò tìm
        int index = ((maso % M) + i * i) % M; // Hàm băm thăm dò bậc hai

        // Trường hợp 1: Vị trí OCCUPIED và tìm thấy x
        if (ht.table[index].Maso == maso) {
            return index; // Trả về chỉ số tìm được
        }

        // Trường hợp 2: Vị trí OCCUPIED nhưng không phải x, hoặc vị trí DELETED
        if (ht.table[index].Maso != EMPTY) {
            // Tiếp tục thăm dò
            continue;
        }

        // Trường hợp 3: Vị trí EMPTY (không tìm thấy x)
        return -1; // Trả về -1 để biểu thị không tìm được
    }

    return -1; // Nếu vượt qua tối đa M lần dò mà không tìm thấy
    // insert code here
}

/*
// insert code here
    nprob = 0;
    int M = ht.M;
    for(int i = 0; i < M; i++) {
        int index;
        if(nprob == 0) index = maso % M;
        else index = ((maso % M) + nprob * nprob) % M;
        if (ht.table[index].Maso == maso)
            return index;
        else if (ht.table[index].Maso == EMPTY)
            return -1;
        nprob++;
    }
    return -1;
    // insert code here
*/
