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
void LNR(TREE &t)
{
    if(t != nullptr)
    {
        LNR(t->pLeft);
        cout << t->key << " ";
        LNR(t->pRight);
    }
}
void PrintTreeLNR_nostack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    else
        LNR(t);
}
void PrintTreeLNR_stack(TREE t)
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
            current = current->pLeft;
        }
        current = s.top();
        s.pop();
        cout << current->key << " ";
        current = current->pRight;
    }
}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    cout << "LNR no stack: \n";
    PrintTreeLNR_nostack(T);
    cout << "\nLNR stack: \n";
    PrintTreeLNR_stack(T);
    return 0;
}

/*Input	Output
6 5 7 2 8 1 -1	1 2 5 6 7 8
4 8 1 9 -1	    1 4 8 9
-1	Empty Tree.*/
