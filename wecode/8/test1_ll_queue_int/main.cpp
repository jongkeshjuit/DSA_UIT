#include <iostream>
using namespace std;

struct NODE{
    int info;
    NODE *pNext;
};
struct queue{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
// insert code here
}
typedef struct NODE* node;
node makenode(int x)
{
    node p = new NODE;
    if(p)
    {
        p->info = x;
        p->pNext = nullptr;
        return p;
    }
    else
        return nullptr;
}
bool isempty(queue q)
{
    return (q.front == nullptr);
}
void enqueue(queue& q, int x)
{
    if(x > 1000) return;
    node p = makenode(x);
    if(isempty(q))
    {
        q.front = p;
        q.back = p;
    }
    else
    {
        q.back->pNext = p;
        q.back = p;
    }
}
int dequeue(queue& q)
{
    if(isempty(q)) return -1;
    node p = q.front;
    int x = p->info;
    q.front = q.front->pNext;
    delete p;
    if(q.front == nullptr)
        q.back = nullptr;
    return x;
}
int getfront(queue q)
{
    if(isempty(q)) return -1;
    return q.front->info;
}
int getback(queue q)
{
    if(isempty(q)) return -1;
    return q.back->info;
}
void createQueue(queue &q)
{
    q.front = nullptr;
    q.back = nullptr;

    int x;
    string output = "output: ";
    while( cin >> x && x!= -1)
    {
        if(x != 0) enqueue(q,x);
        if(x == 0)
        {
            int deq = dequeue(q);
            if(deq != -1)
                output += to_string(deq) + " ";
        }
    }
    cout << output << "\n";
    cout << "front: ";
    if(!isempty(q)) cout << getfront(q);
    cout << "\n";
    cout << "back: ";
    if(!isempty(q)) cout << getback(q);
    cout << "\n";
}
// insert code here
int main() {
    queue q;
	createQueue(q);
    return 0;
}

/*Input	Output
1 2 0 0 3 0 4 5 0 6 7 -1	output: 1 2 3 4
front: 5
back: 7
1 2 3 0 0 4 0 0 0 -1	output: 1 2 3 4
front:
back:
-1	output:
front:
back:*/
