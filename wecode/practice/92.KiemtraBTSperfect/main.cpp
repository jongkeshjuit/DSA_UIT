
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
// insert code here
int finđepth(TREE node)
{
    int depth = 0;
    while(node != nullptr)
    {
        depth++;
        node = node->pLeft;
    }
    return depth;
}
bool isPerfectBinaryTreeUtil(TREE root, int depth, int level = 0)
{
    if (root == NULL) return true;

    if (root->pLeft == NULL && root->pRight == NULL) return (depth == level + 1);

    if (root->pLeft == NULL || root->pRight == NULL) return false;

    return isPerfectBinaryTreeUtil(root->pLeft, depth, level + 1) && isPerfectBinaryTreeUtil(root->pRight, depth, level + 1);
}
bool IsPerfectBinaryTree(TREE root)
{
    int depth = finđepth(root);
    return isPerfectBinaryTreeUtil(root, depth, 0);
}
// insert code here

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << boolalpha << IsPerfectBinaryTree(T);

	return 0;
}

/*

Input	Output
30 15 50 40 60 55 70 65 80 -1
// Minh họa:
     30
  /     \
15       50
       /    \
     40      60
           /   \
         55     70
               / \
            65     80

False
30 15 5 20 50 40 60 -1
// Minh họa:
       30
    /     \
   15      50
 /   \    /  \
5     20 40   60

True
30 15 50 -1
// Minh họa:
    30
 /     \
15      50
True
-1	Empty Tree.
*/
