
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

// insert code here
void makenode(TREE& t , int x)
{
    if(t == nullptr)
    {
        t = new TNODE;
        t->key = x;
        t->pLeft = t->pRight = nullptr;
    }
    else
    {
        if(x < t->key) makenode(t->pLeft, x);
        if(x > t->key) makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while( cin >> x)
    {
        if(x == -1) break;
        makenode(t, x);
    }
}
bool IsCompleteBST(TREE t)
{
    if(t == nullptr) return true;
    queue<TREE> q;
    q.push(t);
    bool flag = false;
    while(!q.empty())
    {
        TREE temp = q.front();
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
// insert code here


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << boolalpha << IsCompleteBST(T);

	return 0;
}

/*Input	Output	Note
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
Empty Tree.	Cây rỗng*/
