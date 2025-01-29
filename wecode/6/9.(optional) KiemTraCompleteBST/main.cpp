
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//insert code here

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
bool IsCompleteBST(TREE t)
{
    if( t == nullptr)
        return true;
    queue<TNODE*> q;
    q.push(t);
    bool flag = false;
    while(!q.empty())
    {
        TNODE* temp = q.front();
        q.pop();
        if(temp->pLeft)
        {
            if(flag) return false;
            q.push(temp->pLeft);
        }
        else flag = true;
        if(temp->pRight)
        {
            if(flag) return false;
            q.push(temp->pRight);
        }
        else flag = true;
    }
    return true;
}
//insert code here



int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << boolalpha << IsCompleteBST(T);

	return 0;
}

/*
Input	Output	Note
30 20 60 10 25 35 -1
True
     30
    /  \
  20    60
 /  \   /
10  25 35
30 15 50 40 60 55 70 65 80 -1
False
     30
  /     \
15      50
        /  \
      40   60
           /  \
         55     70
               /  \
             65   80
30 20 10 25 60 35 70 33 5 -1
False
           30
        /      \
     20          60
   /   \        /  \
  10    25     35   70
 /            /
5            33
-1
Empty Tree.	Cây rỗng

*/
