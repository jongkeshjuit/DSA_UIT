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
void NLR(TREE &t)
{
    if(t != nullptr)
    {
        cout << t->key << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}
void PrintTreeNLR_nostack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    else
        NLR(t);
}
void PrintTreeNLR_stack(TREE t)
{
    if( t == nullptr)
    {
        cout << "Empty Tree.";
        return;
    }
    stack<TNODE*> s;
    s.push(t);
    while(!s.empty())
    {
        TNODE* current = s.top();
        s.pop();
        cout << current->key << " ";
        if(current->pRight != nullptr) s.push(current->pRight);
        if(current->pLeft != nullptr) s.push(current->pLeft);
    }

}
int main()
{
    TREE T;
    T = NULL;
    CreateTree(T);
    cout << "NLR no stack: \n";
    PrintTreeNLR_nostack(T);
    cout << "\nNLR stack: \n";
    PrintTreeNLR_stack(T);
    return 0;
}

/*Input Output
6 5 7 2 8 1 -1  6 5 2 1 7 8
4 8 1 9 -1      4 1 8 9
-1  Empty Tree.*/
