#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <io.h>
#include <fcntl.h>
using namespace std;

// Cấu trúc của một node trong cây nhị phân
struct Node {
    wstring data;
    Node* left;
    Node* right;

    Node(wstring value) : data(value), left(nullptr), right(nullptr) {}
};

// Hàm tạo cây nhị phân từ nhập liệu của người dùng
Node* createTree() {
    wstring value;
    wcout << L"Nhập giá trị của node (nhập '.' nếu node rỗng): ";
    wcin >> value;

    if (value == L".") return nullptr;

    Node* node = new Node(value);
    wcout << L"Nhập con trái của " << value << L":\n";
    node->left = createTree();
    wcout << L"Nhập con phải của " << value << L":\n";
    node->right = createTree();

    return node;
}

// Duyệt cây theo Preorder
void preorder(Node* root) {
    if (root == nullptr) return;
    wcout << root->data << L" ";
    preorder(root->left);
    preorder(root->right);
}

// Duyệt cây theo Inorder
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    wcout << root->data << L" ";
    inorder(root->right);
}

// Duyệt cây theo Postorder
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    wcout << root->data << L" ";
}

int main() {
    // Cấu hình để hỗ trợ Unicode
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    wcout << L"Tạo cây nhị phân:\n";
    Node* root = createTree();

    wcout << L"\nDuyệt cây theo Preorder: ";
    preorder(root);
    wcout << L"\nDuyệt cây theo Inorder: ";
    inorder(root);
    wcout << L"\nDuyệt cây theo Postorder: ";
    postorder(root);

    return 0;
}
