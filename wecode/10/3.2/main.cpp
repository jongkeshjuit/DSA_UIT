#include <iostream>
#include <string>
using namespace std;

#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct PASSWORD_NODE {
    string pass;
    PASSWORD_NODE *pNext;
};

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, 1:OCCUPIED
    string user;
    PASSWORD_NODE* passHead;
};

struct HASHTABLE {
    int M; // Kích thước bảng băm
    int n; // Số phần tử hiện tại trong bảng băm
    NODE *table;
};

int HF(HASHTABLE ht, string user) {
    int s = 0;
    for (int i = 0; i < user.length(); i++)
        s += int(user[i]) * i;
    return s % ht.M;
}

int HF_LinearProbing(HASHTABLE ht, string user, int i) {
    int h = HF(ht, user);
    return (h + i) % ht.M;
}

void InitHashTable(HASHTABLE &ht, int size) {
    ht.M = size;
    ht.n = 0;
    ht.table = new NODE[size];
    for (int i = 0; i < size; i++) {
        ht.table[i].flag = EMPTY;
        ht.table[i].passHead = nullptr;
    }
}

void Insert(HASHTABLE &ht, string user, string pass) {
    int i = 0;
    int index;
    do {
        index = HF_LinearProbing(ht, user, i);
        if (ht.table[index].flag == EMPTY || ht.table[index].flag == DELETED) {
            ht.table[index].user = user;
            ht.table[index].flag = OCCUPIED;
            ht.table[index].passHead = new PASSWORD_NODE;
            ht.table[index].passHead->pass = pass;
            ht.table[index].passHead->pNext = nullptr;
            ht.n++;
            return;
        } else if (ht.table[index].user == user) {
            PASSWORD_NODE* newPass = new PASSWORD_NODE;
            newPass->pass = pass;
            newPass->pNext = ht.table[index].passHead;
            ht.table[index].passHead = newPass;
            return;
        }
        i++;
    } while (i < ht.M);
}

string GetPassword(HASHTABLE &ht, string user) {
    int i = 0;
    int index;
    do {
        index = HF_LinearProbing(ht, user, i);
        if (ht.table[index].flag == EMPTY) {
            return "Unregistered User.";
        } else if (ht.table[index].user == user) {
            return ht.table[index].passHead->pass;
        }
        i++;
    } while (i < ht.M);
    return "Unregistered User.";
}

int main() {
    int N, M;
    cin >> N >> M;
    HASHTABLE ht;
    InitHashTable(ht, 2 * N); // Khởi tạo bảng băm với kích thước gấp đôi số lượng tài khoản

    for (int i = 0; i < N; i++) {
        string user, pass;
        cin >> user >> pass;
        Insert(ht, user, pass);
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        cout << GetPassword(ht, str) << endl;
    }

    delete[] ht.table;
    return 0;
}
