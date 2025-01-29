#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Cấu trúc để lưu thông tin đỉnh kề và trọng số
struct VertexInfo {
    string vertex;
    int weight;
};

void Input(int v, map<string, int>& v_index, vector<string>& vertices,
           int e, map<string, vector<VertexInfo>>& adjacencyList) {
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

        // Thêm cạnh vào danh sách kề
        adjacencyList[u].push_back({v, w});
    }
}

void FindVerticesWithDegreeK(int v, vector<string>& vertices,
                              map<string, vector<VertexInfo>>& adjacencyList, int K) {
    bool foundVertex = false;

    // Duyệt qua tất cả các đỉnh
    for (const string& vertex : vertices) {
        // Lấy số bậc của đỉnh
        int degree = adjacencyList[vertex].size();

        // Nếu bậc của đỉnh bằng K
        if (degree == K) {
            cout << vertex << endl;
            foundVertex = true;
        }
    }

    // Nếu không tìm thấy đỉnh nào có bậc K
    if (!foundVertex) {
        cout << "No find" << endl;
    }
}

int main() {
    int v, e; // v là số đỉnh, e là số cạnh
    cin >> e >> v;

    // Danh sách ánh xạ tên đỉnh --> index
    map<string, int> v_index;

    // Danh sách tên các đỉnh
    vector<string> vertices(v);

    // Danh sách kề
    map<string, vector<VertexInfo>> adjacencyList;

    // Nhập thông tin đồ thị
    Input(v, v_index, vertices, e, adjacencyList);

    // Nhập bậc K cần tìm
    int K;
    cin >> K;

    // Tìm và in ra các đỉnh có bậc K
    FindVerticesWithDegreeK(v, vertices, adjacencyList, K);

    return 0;
}
