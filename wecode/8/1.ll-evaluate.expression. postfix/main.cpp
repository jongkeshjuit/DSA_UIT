
#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 100

struct NODE{
    float info;
    NODE *pNext;
};

NODE *CreateNode(float x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}
struct stack{
    NODE *top;
};
bool empty(const stack &s){
    return (s.top==NULL);
}
void CreateEmptyStack(stack &s){
    s.top=NULL;
}
void push(stack &s, float x){
    NODE *p=CreateNode(x);
    if(s.top==NULL) s.top= p;
    else {
        p->pNext=s.top;
        s.top=p;
    }
}
void pop (stack &s) {
    if(s.top==NULL) return;
    NODE *p= s.top;
    s.top=s.top->pNext;
    delete p;
}
float& top(stack s) {
    return s.top->info;
}
bool isOperator(char x){
    return ( (x=='-') || (x=='+')|| (x=='*') || (x=='/') || (x=='^') );
}
bool isBracket(char x){
    return ( (x=='(') || (x==')') );
}
void InputPostFix(char postix[], int &n){
    char k;
    cin >> k;
    n=0;
    while (k!='#'){
        postix[n++] = k;
        cin >> k;
    }
}

// insert code here
float evaluate_expression(char postix[], int n)
{
    stack s;
    CreateEmptyStack(s);
    for (int i = 0; i < n; ++i)
    {
        char c = postix[i];
        if(isdigit(c))
            push(s, c - 0x30); // ky tu '0' 48 0x30
        else if(isOperator(c))
        {
            float b = top(s); pop(s);
            float a = top(s); pop(s);
            float result;
            if(c == '+') result = a + b;
            if(c == '-') result = a - b;
            if(c == '*') result = a * b;
            if(c == '/') result = a / b;
            if(c == '^') result = pow(a, b);
            push(s, result);
        }
    }
    return top(s);
}
// insert code here


int main() {
    char postfix[MAXN];
    int np;

    InputPostFix(postfix, np);
    // Output(postfix, np);

    cout.precision(3);
    cout << evaluate_expression(postfix, np);

    return 0;
}
/*Input	Output
2 3 - 4 5 + * #	-9
5 4 + 5 * 2 / 3 - #	19.5
7 8 3 * / #	0.292
7 8 3 * / #	0.292
3 2 ^ 2 4 ^ + #	25*/
