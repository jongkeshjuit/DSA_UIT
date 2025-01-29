#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void Input(int v, map<string, int>& v_index, int e, vector<vector<int>>& G) {
    // Nhập tên các đỉnh và tạo ánh xạ
    vector<string> vertices(v);
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

void Output(int v, map<string, int>& v_index, int e, vector<vector<int>>& G) {
    // In ra ma trận trọng số
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v, e; // v là số đỉnh, e là số cạnh
    cin >> e >> v;

    // Ma trận kề được khởi tạo với giá trị ban đầu là 0
    vector<vector<int>> G(v, vector<int>(v, 0));

    // Danh sách ánh xạ tên đỉnh --> index
    map<string, int> v_index;

    Input(v, v_index, e, G);
    Output(v, v_index, e, G);

    return 0;
}
