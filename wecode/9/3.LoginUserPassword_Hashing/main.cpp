

/* ĐỂ TRÁNH TRƯỜNG HỢP TRÀN BỘ NHỚ DO SỐ LƯỢNG PASSWORD CỦA 1 USER CẦN LƯU TRỮ QUÁ NHIỀU.
CÓ TEST CASE CÓ NHIỀU USER THAY ĐỔI SỐ LƯỢNG PASS RẤT LỚN, LÊN ĐẾN 4000-5000 NGÀN PASS CHO 1 USER.

TRƯỜNG HỢP SINH VIÊN VẪN DÙNG MẢNG 1 CHIỀU LƯU DS PASSWORD THÌ SỐ LƯỢNG PHẦN TỬ MẢNG PASS SẼ RẤT LỚN.
=> CÓ MỘT TEST BỊ "Memory Limit Exceeded": TEST 9, 10 12, 13, ... => TUY NHIÊN GV VẪN CHẤM ĐÚNG CHO TRƯỜNG HỢP NÀY.

=> ĐỀ NGHỊ SINH VIÊN CHUYỂN SANG DÙNG LIST PASSWORD THAY VÌ DÙNG MẢNG 1 CHIỀU PASSWORD.
VD NHƯ BÊN DƯỚI, HOẠC CÓ THỂ DÙNG LIST SẴN CÓ TRONG STD C++.


#include <iostream>
#include <string>
using namespace std;

#define M 100
#define numbucket 100

struct PASSWORD_NODE{
	string pass;
	PASSWORD_NODE *pNext;
};
struct USER_NODE {
    string user;
	PASSWORD_NODE* passHead;
	USER_NODE * pNext;

};

// Khai báo kiểu con trỏ chỉ node
typedef USER_NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

int HF(string user) {
	int s=0;
	for(int i=0; i<user.length(); i++)
		s += int(user[i])*i;
	return s % numbucket;
}
*/

//insert code here
#include <iostream>
#include <string>
#include <list>
using namespace std;

#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct USER {
    string USERNAME;
    list<string> PASS;
};

struct NODE {
    int flag;
    USER key;
};

struct HASHTABLE {
    int M;
    int n;
    NODE *table;
};

int HF(HASHTABLE ht, string username) {
    int s = 0;
    for (int i = 0; i < username.length(); i++)
        s += 37 *username[i] + i;
    return s % ht.M;
}

int HF_LinearProbing(HASHTABLE ht, string username, int i) {
    int h = HF(ht, username);
    return (h + i) % ht.M;
}

void CreateEmptyHashtable(HASHTABLE &ht, int m) {
    ht.M = m;
    ht.table = new NODE[ht.M];
    for (int i = 0; i < ht.M; i++) {
        ht.table[i].flag = EMPTY;
    }
    ht.n = 0;
}

void Insert(HASHTABLE &ht, string username, string password) {
    int i = 0;
    while (i < ht.M) {
        int index = HF_LinearProbing(ht, username, i++);
        if (ht.table[index].flag == EMPTY || ht.table[index].flag == DELETED) {
            ht.table[index].flag = OCCUPIED;
            ht.table[index].key.USERNAME = username;
            ht.table[index].key.PASS.push_back(password);
            ht.n++;
            return;
        } else if (ht.table[index].flag == OCCUPIED && ht.table[index].key.USERNAME == username) {
            ht.table[index].key.PASS.push_back(password);
            return;
        }
    }
}

void Traverse(HASHTABLE &ht, string username) {
    int i = 0;
    while (i < ht.M) {
        int index = HF_LinearProbing(ht, username, i);
        if (ht.table[index].flag == EMPTY) {
            cout << "Unregistered User." << endl;
            return;
        } else if (ht.table[index].flag == OCCUPIED && ht.table[index].key.USERNAME == username) {
            cout<<ht.table[index].key.PASS.back()<<endl;
            return;
        }
        i++;
    }
    cout << "Unregistered User." << endl;
}

void DeleteHashtable(HASHTABLE &ht) {
    delete[] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main() {
    int N, M;
    cin >> N >> M;
    HASHTABLE H;
    CreateEmptyHashtable(H, 2 * N);
    string username, password;
    for (int i = 0; i < N; i++) {
        cin >> username >> password;
        Insert(H, username, password);
    }
    for (int i = 0; i < M; i++) {
        cin >> username;
        Traverse(H, username);
    }
    DeleteHashtable(H);
    return 0;
}
//insert code here
