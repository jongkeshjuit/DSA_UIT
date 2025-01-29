
#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}
// insert code here
void Insert(HASHTABLE& ht, int key)
{
    if((float)(ht.n + 1) / ht.M > LOAD) return;
    int i = 0;
    while(1)
    {
        int index = HF_LinearProbing(ht, key, i);
        if(ht.table[index].key == key) break;
        if(ht.table[index].flag == EMPTY || ht.table[index].flag == DELETED)
        {
            ht.table[index].key = key;
            ht.table[index].flag = OCCUPIED;
            ht.n++;
            break;
        }
        else i++;
    }
}

void Delete(HASHTABLE& ht, int key)
{
    int i = 0;
    while(1)
    {
        int index = HF_LinearProbing(ht, key, i);
        if(ht.table[index].flag == EMPTY) return;
        if(ht.table[index].flag == OCCUPIED && ht.table[index].key == key)
        {
            ht.table[index].flag = DELETED;
            ht.n--;
            return;
        }
        i++;
    }
}

void CreateHashTable(HASHTABLE& ht)
{
    cin >> ht.M;
    ht.n = 0;
    ht.table = new NODE[ht.M];
    for(int i = 0 ; i < ht.M; i++)
        ht.table[i].flag = EMPTY;
    int x;
    cin >> x;
    for(int i = 0; i < x; i++)
    {
        int check, key;
        cin >> check;
        cin >> key;
        if(check == 1)  Insert(ht, key);
        if(check == 0)  Delete(ht, key);
    }
}

void Traverse(HASHTABLE& ht)
{
    for(int i = 0; i < ht.M; i++)
    {
        cout << i << " --> ";
        if(ht.table[i].flag == EMPTY) cout << "EMPTY";
        else if(ht.table[i].flag == DELETED) cout << "DELETED";
        else cout << ht.table[i].key;
        cout << endl;
    }
}
// insert code here


void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}


