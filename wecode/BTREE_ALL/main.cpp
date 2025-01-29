
#include <iostream>
using namespace std;

// Khai báo các struct
struct BTreeNode {
    int *keys;      // Mảng chứa các khóa
    int t;          // Bậc của cây B-Tree
    BTreeNode **C;  // Mảng con trỏ đến các con
    int n;          // Số lượng khóa hiện tại
    bool leaf;      // True nếu là lá, ngược lại false
};

struct BTree {
    BTreeNode *root; // Con trỏ đến node gốc
    int t;           // Bậc của cây B-Tree
};

// Khai báo các hàm
BTreeNode* createNode(int t, bool leaf);
void traverse(BTreeNode* node);
BTreeNode* search(BTreeNode* node, int k);
void insert(BTree* tree, int k);
void remove(BTree* tree, int k);
void insertNonFull(BTreeNode* node, int k);
void splitChild(BTreeNode* node, int i, BTreeNode* y);
void removeNode(BTreeNode* node, int k);
void removeFromLeaf(BTreeNode* node, int idx);
void removeFromNonLeaf(BTreeNode* node, int idx);
int getPred(BTreeNode* node, int idx);
int getSucc(BTreeNode* node, int idx);
void fill(BTreeNode* node, int idx);
void borrowFromPrev(BTreeNode* node, int idx);
void borrowFromNext(BTreeNode* node, int idx);
void merge(BTreeNode* node, int idx);

// Cài đặt các hàm
BTreeNode* createNode(int t, bool leaf) {
    BTreeNode* node = new BTreeNode;
    node->t = t;
    node->leaf = leaf;
    node->keys = new int[2*t-1];
    node->C = new BTreeNode *[2*t];
    node->n = 0;
    return node;
}

void traverse(BTreeNode* node) {
    if (node == nullptr) return; // Kiểm tra nếu node là nullptr

    int i;
    for (i = 0; i < node->n; i++) {
        if (!node->leaf)
            traverse(node->C[i]);
        cout << node->keys[i] << " ";
    }
    if (!node->leaf)
        traverse(node->C[i]);
}

BTreeNode* search(BTreeNode* node, int k) {
    int i = 0;
    while (i < node->n && k > node->keys[i])
        i++;
    if (node->keys[i] == k)
        return node;
    if (node->leaf)
        return nullptr;
    return search(node->C[i], k);
}

void insert(BTree* tree, int k) {
    if (tree->root == nullptr) {
        tree->root = createNode(tree->t, true);
        tree->root->keys[0] = k;
        tree->root->n = 1;
    } else {
        if (tree->root->n == 2*tree->t-1) {
            BTreeNode* s = createNode(tree->t, false);
            s->C[0] = tree->root;
            splitChild(s, 0, tree->root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(s->C[i], k);
            tree->root = s;
        } else {
            insertNonFull(tree->root, k);
        }
    }
}

void insertNonFull(BTreeNode* node, int k) {
    int i = node->n - 1;
    if (node->leaf) {
        while (i >= 0 && node->keys[i] > k) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = k;
        node->n = node->n + 1;
    } else {
        while (i >= 0 && node->keys[i] > k)
            i--;
        if (node->C[i + 1]->n == 2*node->t - 1) {
            splitChild(node, i + 1, node->C[i + 1]);
            if (node->keys[i + 1] < k)
                i++;
        }
        insertNonFull(node->C[i + 1], k);
    }
}

void splitChild(BTreeNode* node, int i, BTreeNode* y) {
    BTreeNode* z = createNode(y->t, y->leaf);
    z->n = y->t - 1;
    for (int j = 0; j < y->t - 1; j++)
        z->keys[j] = y->keys[j + y->t];
    if (!y->leaf) {
        for (int j = 0; j < y->t; j++)
            z->C[j] = y->C[j + y->t];
    }
    y->n = y->t - 1;
    for (int j = node->n; j >= i + 1; j--)
        node->C[j + 1] = node->C[j];
    node->C[i + 1] = z;
    for (int j = node->n - 1; j >= i; j--)
        node->keys[j + 1] = node->keys[j];
    node->keys[i] = y->keys[y->t - 1];
    node->n = node->n + 1;
}

void remove(BTree* tree, int k) {
    if (!tree->root) {
        cout << "The tree is empty\n";
        return;
    }
    removeNode(tree->root, k);
    if (tree->root->n == 0) {
        BTreeNode* tmp = tree->root;
        if (tree->root->leaf)
            tree->root = nullptr;
        else
            tree->root = tree->root->C[0];
        delete tmp;
    }
}

void removeNode(BTreeNode* node, int k) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < k)
        idx++;
    if (idx < node->n && node->keys[idx] == k) {
        if (node->leaf)
            removeFromLeaf(node, idx);
        else
            removeFromNonLeaf(node, idx);
    } else {
        if (node->leaf) {
            cout << "The key " << k << " is not in the tree\n";
            return;
        }
        bool flag = (idx == node->n);
        if (node->C[idx]->n < node->t)
            fill(node->C[idx], idx);
        if (flag && idx > node->n)
            removeNode(node->C[idx - 1], k);
        else
            removeNode(node->C[idx], k);
    }
}

void removeFromLeaf(BTreeNode* node, int idx) {
    for (int i = idx + 1; i < node->n; ++i)
        node->keys[i - 1] = node->keys[i];
    node->n--;
}

void removeFromNonLeaf(BTreeNode* node, int idx) {
    int k = node->keys[idx];
    if (node->C[idx]->n >= node->t) {
        int pred = getPred(node, idx);
        node->keys[idx] = pred;
        removeNode(node->C[idx], pred);
    } else if (node->C[idx + 1]->n >= node->t) {
        int succ = getSucc(node, idx);
        node->keys[idx] = succ;
        removeNode(node->C[idx + 1], succ);
    } else {
        merge(node, idx);
        removeNode(node->C[idx], k);
    }
}

int getPred(BTreeNode* node, int idx) {
    BTreeNode* cur = node->C[idx];
    while (!cur->leaf)
        cur = cur->C[cur->n];
    return cur->keys[cur->n - 1];
}

int getSucc(BTreeNode* node, int idx) {
    BTreeNode* cur = node->C[idx + 1];
    while (!cur->leaf)
        cur = cur->C[0];
    return cur->keys[0];
}

void fill(BTreeNode* node, int idx) {
    if (idx != 0 && node->C[idx - 1]->n >= node->t)
        borrowFromPrev(node, idx);
    else if (idx != node->n && node->C[idx + 1]->n >= node->t)
        borrowFromNext(node, idx);
    else {
        if (idx != node->n)
            merge(node, idx);
        else
            merge(node, idx - 1);
    }
}

void borrowFromPrev(BTreeNode* node, int idx) {
    BTreeNode* child = node->C[idx];
    BTreeNode* sibling = node->C[idx - 1];

    // Dịch chuyển tất cả các khóa của child sang phải
    for (int i = child->n - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    // Nếu child không phải là lá, dịch chuyển tất cả các con trỏ con của child sang phải
    if (!child->leaf) {
        for (int i = child->n; i >= 0; --i)
            child->C[i + 1] = child->C[i];
    }

    // Đặt khóa từ node vào child
    child->keys[0] = node->keys[idx - 1];

    // Di chuyển con trỏ con cuối cùng của sibling sang child
    if (!child->leaf)
        child->C[0] = sibling->C[sibling->n];

    // Di chuyển khóa từ sibling lên node
    node->keys[idx - 1] = sibling->keys[sibling->n - 1];

    // Cập nhật số lượng khóa trong child và sibling
    child->n += 1;
    sibling->n -= 1;
}

void borrowFromNext(BTreeNode* node, int idx) {
    BTreeNode* child = node->C[idx];
    BTreeNode* sibling = node->C[idx + 1];
    child->keys[(child->n)] = node->keys[idx];
    if (!(child->leaf))
        child->C[(child->n) + 1] = sibling->C[0];
    node->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->n; ++i)
            sibling->C[i - 1] = sibling->C[i];
    }
    child->n += 1;
    sibling->n -= 1;
}

void merge(BTreeNode* node, int idx) {
    BTreeNode* child = node->C[idx];
    BTreeNode* sibling = node->C[idx + 1];
    child->keys[node->t - 1] = node->keys[idx];
    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + node->t] = sibling->keys[i];
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->C[i + node->t] = sibling->C[i];
    }
    for (int i = idx + 1; i < node->n; ++i)
        node->keys[i - 1] = node->keys[i];
    for (int i = idx + 2; i <= node->n; ++i)
        node->C[i - 1] = node->C[i];
    child->n += sibling->n + 1;
    node->n--;
    delete(sibling);
}

int main() {
    BTree tree;
    cout << "Enter the degree of B-Tree: ";
    cin >> tree.t;
    tree.root = nullptr;
    int choice, key;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the key to insert: ";
                cin >> key;
                insert(&tree, key);
                break;
            case 2:
                cout << "Enter the key to delete: ";
                cin >> key;
                remove(&tree, key);
                break;
            case 3:
                cout << "Enter the key to search: ";
                cin >> key;
                if (search(tree.root, key) != nullptr)
                    cout << "Key found\n";
                else
                    cout << "Key not found\n";
                break;
           case 4:
                if (tree.root != nullptr) {
                    cout << "Traversal of the tree: ";
                    traverse(tree.root);
                    cout << endl;
                } else {
                    cout << "The tree is empty\n";
                }
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}

