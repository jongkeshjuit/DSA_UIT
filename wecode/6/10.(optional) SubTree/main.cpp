
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
void CreateEmptyTree(TREE &T) {
    T = NULL;
}

TNODE* CreateTNode(int x) {
    TNODE *p = new TNODE;
    p->key = x;
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

void CreateTree(TREE &T) {
    int x;
    do {
        cin >> x;
        if(x == -1) break;
        Insert(T, CreateTNode(x));
    } while(true);
}

// identical - giong nhau
bool isidentical(TREE s, TREE t) {
    if(s == nullptr && t == nullptr) return true;
    if(s == nullptr || t == nullptr) return false;
    return (s->key == t->key &&
            isidentical(s->pLeft, t->pLeft) &&
            isidentical(s->pRight, t->pRight));
}

// subtree - cay con
bool isSubtree(TREE s, TREE t) {
    if(s == nullptr) return true;
    if(t == nullptr) return false;
    if(isidentical(s, t)) return true;
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

/*
Input	Output	Note
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
              20

*/
