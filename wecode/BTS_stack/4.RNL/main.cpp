#include <iostream>
#include <stack>
using namespace std;
struct TNODE{
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;

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
        if(x < t->key) makenode(t->pLeft, x);
        if(x > t->key) makenode(t->pRight, x);
    }
}
void CreateTree(TREE &t)
{
    int x;
    while( cin >> x)
    {
        if( x == -1) break;
        makenode(t, x);
    }
}
void RNL(TREE &t)
{
    if(t != nullptr)
    {
        RNL(t->pRight);
        cout << t->key << " ";
        RNL(t->pLeft);
    }
}
void PrintTreeRNL_nostack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    else
        RNL(t);
}
void PrintTreeRNL_stack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    stack<TNODE*> s;
    TNODE* current = t;
    while(current != nullptr || !s.empty())
    {
        while(current != nullptr)
        {
            s.push(current);
            current = current->pRight;
        }
        current = s.top();
        s.pop();
        cout << current->key << " ";
        current = current->pLeft;
    }


}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    cout << "RNL no stack: \n";
    PrintTreeRNL_nostack(T);
    cout << "\nRNL stack: \n";
    PrintTreeRNL_stack(T);
    return 0;
}

/*Input Output
6 5 7 2 8 1 -1  8 7 6 5 2 1
4 8 1 9 -1      9 8 4 1
-1  Empty Tree.*/
