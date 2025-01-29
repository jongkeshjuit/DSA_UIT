#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct NODE {
    string username;
    vector<string> passwords;
};

typedef unordered_map<string, NODE> HASHTABLE;

void Insert(HASHTABLE &H, const string &user, const string &pass) {
    if (H.find(user) == H.end()) {
        NODE newNode;
        newNode.username = user;
        H[user] = newNode;
    }
    H[user].passwords.push_back(pass);
}

string FindPasswords(HASHTABLE &H, const string &user) {
    if (H.find(user) != H.end() && !H[user].passwords.empty()) {
        return H[user].passwords.back();
    } else {
        return "Unregistered User.";
    }
}

void CreateHash(HASHTABLE &H, int n) {
    for (int i = 0; i < n; ++i) {
        string user, pass;
        cin >> user >> pass;
        Insert(H, user, pass);
    }
}

void OutPassword(HASHTABLE &H, int m) {
     for (int i = 0; i < m; ++i) {
        string user;
        cin >> user;
        cout << FindPasswords(H, user) << endl;
    }
}

int main() {
    HASHTABLE H;
    int n, m;
    cin >> n >> m;
    CreateHash(H, n);
    OutPassword(H, m);
    return 0;
}
