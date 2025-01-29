
//insert code here
#include <iostream>
using namespace std;

// Cấu trúc node cho stack
struct Node {
    int data;
    Node* next;
};

// Cấu trúc stack
struct Stack {
    Node* top;
};

// Khởi tạo stack rỗng
void InitStack(Stack &s) {
    s.top = NULL;
}

// Kiểm tra stack rỗng
bool isEmpty(Stack s) {
    return s.top == NULL;
}

// Thêm phần tử vào đỉnh stack
void push(Stack &s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

// Lấy phần tử ở đỉnh và xóa khỏi stack
int pop(Stack &s) {
    if (isEmpty(s)) {
        return -1;  // Stack rỗng
    }
    Node* temp = s.top;
    int value = temp->data;
    s.top = s.top->next;
    delete temp;
    return value;
}

// Giải phóng bộ nhớ stack
void freeStack(Stack &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

// Hàm chuyển đổi từ thập phân sang nhị phân
void decimal_to_binary(int n) {
    Stack s;
    InitStack(s);

    // Trường hợp đặc biệt khi n = 0
    if (n == 0) {
        cout << "0";
        return;
    }

    // Chuyển đổi sang nhị phân và đưa vào stack
    while (n > 0) {
        push(s, n % 2);
        n = n / 2;
    }

    // In kết quả từ stack
    while (!isEmpty(s)) {
        cout << pop(s);
    }

    // Giải phóng bộ nhớ
    freeStack(s);
}
//insert code here
int main() {
    int n;
    cin >> n;
    decimal_to_binary(n);
    return 0;
}
