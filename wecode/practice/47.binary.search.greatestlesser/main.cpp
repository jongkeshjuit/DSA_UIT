
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
// insert code here
int binary_search_greatestLesser_last_occurrence(int a[], int n, int x)
{

}
// insert code here

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_greatestLesser_last_occurrence(a, n, x);

    return 0;
}


