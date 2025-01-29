
#include <iostream>
#include <queue>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

//insert code here
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
    while(cin >> x && x != -1)
        makenode(t,x);
}
bool sosanh(TREE s, TREE t)
{
    if(s == nullptr && t== nullptr) return true;
    if(s == nullptr || t == nullptr) return false;
    return (s->key == t->key && sosanh(s->pLeft, t->pLeft) && sosanh(s->pRight, t->pRight));
}
bool isSubtree(TREE s, TREE t)
{
    if(s == nullptr) return true;
    if(t == nullptr) return false;
    if(sosanh(s, t)) return true;
    return isSubtree(s, t->pLeft) || isSubtree(s, t->pRight);
}
//insert code here

int main() {
	TNODE* S, *T;
	S=NULL; T=NULL;

	CreateTree(S);
	CreateTree(T);

	cout <<  boolalpha << isSubtree(S, T);

	return 0;
}

/*Input	Output	Note
-1
-1	true
  Cây S:      Cây T:
  Rỗng         Rỗng

-1
30 20 60 10 -1	true
  Cây S:      Cây T:
   Rỗng          30
                /  \
              20   60
             /
           10



30 20 60 10 -1
30 20 60 10 -1	true
    Cây S:      Cây T:
      30           30
     /  \         /  \
   20    60      20   60
  /             /
10             10


15 10 25 20 -1
30 15 10 60 25 20 -1	true
Cây S:      Cây T:
   15           30
  /  \         /  \
 10   25     15   60
      /     /  \
     20    10   25
               /
              20

30 -1
30 20 60 10 -1	false
Cây S:      Cây T:
  30         30
            /  \
          20   60
         /
       10


30 20 60 10 -1
40 20 60 10 -1	false
    Cây S:      Cây T:
      30           40
     /  \         /  \
   20    60      20   60
  /             /
10             10


15 10 25 -1
30 15 60 10 25 20 -1	false
Cây S:      Cây T:
  15             30
 /  \          /   \
10  25       15     60
            /  \
          10    25
               /
              20*/
