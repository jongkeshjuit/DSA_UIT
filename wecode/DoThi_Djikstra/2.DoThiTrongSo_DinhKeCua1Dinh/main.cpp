#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

void Input(int v, map<string, int>& v_index, vector<string>& vertices, int e, vector<vector<int>>& G) {
    // Nhập tên các đỉnh và tạo ánh xạ
    for (int i = 0; i < v; i++) {
        cin >> vertices[i];
        v_index[vertices[i]] = i;
    }

    // Nhập các cạnh và trọng số
    for (int i = 0; i < e; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        G[v_index[u]][v_index[v]] = w;
    }
}

void FindAdjacentVertices(int v, map<string, int>& v_index, vector<string>& vertices, vector<vector<int>>& G, string K) {
    // Kiểm tra xem đỉnh K có tồn tại không
    if (v_index.find(K) == v_index.end()) {
        cout << "No find" << endl;
        return;
    }

    // Lấy chỉ số của đỉnh K
    int k_index = v_index[K];

    // Biến để kiểm tra xem có đỉnh kề nào không
    bool foundAdjacent = false;

    // Duyệt qua các đỉnh trong đồ thị
    for (int j = 0; j < v; j++) {
        // Nếu có cạnh từ K đến đỉnh khác (trọng số > 0)
        if (G[k_index][j] > 0) {
            // In ra tên đỉnh kề và trọng số
            cout << vertices[j]; //<< " " << G[k_index][j] << endl;
            cout << " ";
            foundAdjacent = true;
        }
    }

    // Nếu không có đỉnh kề nào
    if (!foundAdjacent) {
        cout << "No find" << endl;
    }
}

int main() {
    int v, e; // v là số đỉnh, e là số cạnh
    cin >> e >> v;

    // Ma trận kề được khởi tạo với giá trị ban đầu là 0
    vector<vector<int>> G(v, vector<int>(v, 0));

    // Danh sách ánh xạ tên đỉnh --> index
    map<string, int> v_index;

    // Danh sách tên các đỉnh
    vector<string> vertices(v);

    // Nhập thông tin đồ thị
    Input(v, v_index, vertices, e, G);

    // Nhập đỉnh cần tìm đỉnh kề
    string K;
    cin >> K;

    // Tìm và in ra các đỉnh kề
    FindAdjacentVertices(v, v_index, vertices, G, K);

    return 0;
}
