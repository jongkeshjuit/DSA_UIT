
#include <iostream>

using namespace std;

// insert code here
#define MAXN 100
void NhapMang(int a[], int n)
{
    for(int i = 0 ; i < n ; ++i)
        cin >> a[i];
}

int binary_search(int a[], int n, int x)
{
    int left = 0, right = n -1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x) return 1;
        if(a[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

// insert code here

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i= binary_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}


