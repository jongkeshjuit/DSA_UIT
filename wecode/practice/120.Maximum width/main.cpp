
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

// insert code here
void makenode(TREE& t, int x)
{
    if( t == nullptr)
    {
        t = new TNODE;
        t->key = x;
        t->pLeft = t->pRight = nullptr;
    }
    else
    {
        if(x < t->key)
            makenode(t->pLeft, x);
        if(x > t->key)
            makenode(t->pRight, x);
    }
}
void CreateTree(TREE& t)
{
    int x;
    while( cin >> x)
    {
        if( x == -1) break;
        makenode(t, x);
    }
}
int getMaximumWidth(TREE t)
{
    if( t == nullptr) return 0;
    queue<TREE> q;
    q.push(t);
    int maxwidth = 0;
    while(!q.empty())
    {
        int count = q.size();
        maxwidth = max(maxwidth, count);
        while(count--)
        {
            TREE temp = q.front();
            q.pop();
            if(temp->pLeft != nullptr) q.push(temp->pLeft);
            if(temp->pRight != nullptr) q.push(temp->pRight);
        }
    }
    return maxwidth;
}
// insert code here

int main() {
	TREE T;
	T = NULL;
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << getMaximumWidth(T);

	return 0;
}
/*
Input	Output	Note
8 -1
1
      8
30 20 60 10 25 35 -1
3
     30
    /  \
  20    60
 /  \   /
10  25 35
30 15 50 40 60 55 70 65 80 35 45 -1
4
     30
  /     \
15        50
        /    \
     40        60
    /  \     /   \
   35   45  55   70
           /  \
         65    80
30 20 10 25 60 35 70 33 5 15 50 -1
3
            30
        /       \
     20          60
   /   \        /
  10    25     35
 /            /  \
5           33    50
-1
Empty Tree.	Cây rỗng.
*/
