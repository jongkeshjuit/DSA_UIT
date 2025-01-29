
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
// insert code here
int binary_search_last_occurrence(int a[], int n, int x)
{
    int left = 0, right = n -1, result = -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x)
        {
            result = mid;
            left = mid + 1; // tiep tuc
        }
        if(a[mid] > x)
            right = mid -1;
        else
            left = mid + 1;
    }
    return result;
}
// insert code here

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


