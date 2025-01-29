
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
// insert code here
void CreateTree(TREE& t)
{
    int x;
    while(cin >> x)
    {
        if(x == -1)
            break;
        TNODE* p = CreateTNode(x);
        if(Insert(t, p) == 0)
            delete p;
    }
}
bool searchnode(TREE t, int x)
{
    if(t!= nullptr)
    {
        if(x == t->key)
            return true;
        if(x < t->key)
            return searchnode(t->pLeft, x);
        else
            return searchnode(t->pRight, x);
    }
    return false;
}
void FindParent(TREE t, int& x)
{
    if(t != nullptr)
    {
        if(!searchnode(t,x))
        {
            cout << "Not found " << x << ".";
            return;
        }
        if(x == t->key)
        {
            cout << x << " has no parent.";
            return;
        }
        TNODE* pre = nullptr;
        TNODE* p = t;
        while( p != nullptr)
        {
            if(x == p->key && pre!= nullptr)
            {
                cout << pre->key << " is parent of " << x << ".";
                return;
            }
            pre = p;
            if(x < p->key)
                p = p->pLeft;
            else if (x > p->key)
                p = p->pRight;
        }
    }
    else
    {
        cout << "Empty Tree.";
        return;
    }
}
// insert code here




int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindParent(T, x);

	return 0;
}

/*
Input	Output
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

50 is parent of 60.
*/
