

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
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    unordered_map<string, string> userPassMap;
    for (int i = 0; i < N; i++) {
        string user, pass;
        cin >> user >> pass;
        userPassMap[user] = pass;
    }
    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        if (userPassMap.find(str) != userPassMap.end()) {
            cout << userPassMap[str] << endl;
        } else {
            cout << "Unregistered User." << endl;
        }
    }
    return 0;
}
