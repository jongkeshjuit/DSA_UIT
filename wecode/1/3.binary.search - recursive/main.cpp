
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
// insert code here
int dequy(int a[], int n, int left, int right, int x)
{
    if(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x) return 1;
        else if(a[mid] > x) return dequy(a, n, left, mid - 1, x);
        else return dequy(a, n, mid + 1, right, x);
    }
    return -1;
}

int binary_search(int a[], int n, int x)
{
    return dequy(a,n,0,n-1, x);
}
// insert code here

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i = binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}

