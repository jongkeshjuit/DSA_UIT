/*
#include <iostream>
#include <string>

#define LOAD 0.7
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node *next;
};

struct List {
    Node * head, *tail;
};

Node * CreateNode(Hocsinh);
void CreateEmptyList(List &);
void AddTail(List&, Hocsinh);
int RemoveHead(List &);
int RemoveAfter(List &, Node *);
void DeleteList(List &);

struct Hashtable {
    int M; // Kich thuoc bang bam
    int n; // so phan tu trong bang bam
    List *table;
};

void CreateEmptyHashtable(Hashtable &, int);
int Hash(Hashtable, int); // Ham bam ma so hoc sinh thanh chi so
int Delete(Hashtable &, int);
void PrintHashtable(Hashtable);
void DeleteHashtable(Hashtable &);

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin>>ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}
*/
#include <iostream>
#include <string>
using namespace std;

#define LOAD 0.7

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Node {
    Hocsinh data;
    Node *next;
};

struct List {
    Node *head, *tail;
};

Node* CreateNode(Hocsinh x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void CreateEmptyList(List &l) {
    l.head = l.tail = nullptr;
}

void AddTail(List &l, Hocsinh x) {
    Node* p = CreateNode(x);
    if (l.head == nullptr) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

int RemoveHead(List &l) {
    if (l.head == nullptr) return 0;
    Node* p = l.head;
    l.head = l.head->next;
    delete p;
    if (l.head == nullptr) l.tail = nullptr;
    return 1;
}

int RemoveAfter(List &l, Node *q) {
    if (q == nullptr || q->next == nullptr) return 0;
    Node* p = q->next;
    q->next = p->next;
    if (p == l.tail) l.tail = q;
    delete p;
    return 1;
}

void DeleteList(List &l) {
    while (l.head != nullptr) {
        RemoveHead(l);
    }
}

struct Hashtable {
    int M; // Kích thước bảng băm
    int n; // Số phần tử trong bảng băm
    List *table;
};

void CreateEmptyHashtable(Hashtable &ht, int size) {
    ht.M = size;
    ht.n = 0;
    ht.table = new List[size];
    for (int i = 0; i < size; i++) {
        CreateEmptyList(ht.table[i]);
    }
}

int Hash(Hashtable ht, int key) {
    return key % ht.M;
}

int Delete(Hashtable &ht, int maso) {
    int index = Hash(ht, maso);
    Node *current = ht.table[index].head;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->data.Maso == maso) {
            if (prev == nullptr) {
                // Xóa phần tử đầu tiên trong danh sách liên kết
                ht.table[index].head = current->next;
                if (ht.table[index].head == nullptr) {
                    ht.table[index].tail = nullptr;
                }
            } else {
                // Xóa phần tử không phải đầu tiên
                prev->next = current->next;
                if (current == ht.table[index].tail) {
                    ht.table[index].tail = prev;
                }
            }
            delete current;
            ht.n--;
            return 1; // Xóa thành công
        }
        prev = current;
        current = current->next;
    }
    return 0; // Không tìm thấy phần tử cần xóa
}

void PrintHashtable(Hashtable ht) {
    for (int i = 0; i < ht.M; i++) {
        cout << "Bucket " << i << ": ";
        Node* current = ht.table[i].head;
        while (current != nullptr) {
            cout << current->data.Maso << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void DeleteHashtable(Hashtable &ht) {
    for (int i = 0; i < ht.M; i++) {
        DeleteList(ht.table[i]);
    }
    delete[] ht.table;
}

void Input(Hocsinh &x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
    cin >> x.TBK;
}

int main() {
    int N, M;
    cin >> N >> M;
    Hashtable ht;
    CreateEmptyHashtable(ht, int(N / LOAD));

    for (int i = 0; i < N; i++) {
        Hocsinh hs;
        Input(hs);
        int index = Hash(ht, hs.Maso);
        AddTail(ht.table[index], hs);
        ht.n++;
    }

    for (int i = 0; i < M; i++) {
        int maso;
        cin >> maso;
        cout << (Delete(ht, maso) ? "Deleted" : "Not found") << endl;
    }

    PrintHashtable(ht);
    DeleteHashtable(ht);

    return 0;
}



