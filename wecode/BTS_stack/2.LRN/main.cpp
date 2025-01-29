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
void LRN(TREE &t)
{
    if(t != nullptr)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->key << " ";
    }
}
void PrintTreeLRN_nostack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    else
        LRN(t);
}
void PrintTreeLRN_stack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    stack<TNODE*> s, out;
    s.push(t);

    while(!s.empty())
    {
        TNODE* current = s.top();
        s.pop();
        out.push(current);
        if(current->pLeft != nullptr) s.push(current->pLeft);
        if(current->pRight != nullptr) s.push(current->pRight);
    }
    while(!out.empty())
    {
        cout << out.top()->key << " ";
        out.pop();
    }

}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    cout << "LRN no stack: \n";
    PrintTreeLRN_nostack(T);
    cout << "\nLRN stack: \n";
    PrintTreeLRN_stack(T);
    return 0;
}

/*Input	Output
6 5 7 2 8 1 -1	1 2 5 8 7 6
4 8 1 9 -1	    1 9 8 4
-1	Empty Tree.*/
