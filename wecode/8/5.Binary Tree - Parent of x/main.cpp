
#include <iostream>

using namespace std;
struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}
//insert code here
void PrintParent(TREE t, int x)
{
    if(t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    if(t->key == x)
    {
        cout << t->key << " has no parent.";
        return;
    }
    TREE parent = nullptr;
    TREE current = t;
    while(current != nullptr)
    {
        if(current->key == x)
        {
            if(parent == nullptr)
                cout << t->key << " has no parent.";
            else
                cout << parent->key << " is parent of " << x << ".";
            return;
        }
        parent = current;
        if(x < current->key)
            current = current->pLeft;
        else
            current = current->pRight;
    }
    cout << "Not found " << x << ".";
}
//insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	PrintParent(T, x);

	return 0;
}
/*Input	Output
-1
7	Empty Tree.
30 15 50 -1
30
// Minh họa:
    30
 /     \
15      50

30 has no parent.
30 15 50 -1
40
// Minh họa:
    30
 /     \
15      50

Not found 40.
30 15 50 60 55 70 65 80 -1
60
 // Hình vẽ minh họa:
    30
 /     \
15      50
          \
          60
          /  \
        55     70
              /  \
            65    80
50 is parent of 60.*/
