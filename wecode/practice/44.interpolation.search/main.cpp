#include <iostream>
#include <math.h>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int &N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int interpolation_search(int* a, int n, int x) {
    // insert code here
    int low = 0, high = n -1;
    while(low <= high && a[low] <= x && x <= a[high])
    {
        if(low == high)
        {
            if(a[low] == x)
                return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (a[high] -a[low])* (x - a[low]));
        if(a[pos] == x) return pos;
        if(a[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
    // insert code here
}


int main() {
    int x; cin >> x;
    int n; cin >> n;

    int a[MAXN];
    NhapMang(a, n);

    int i = interpolation_search(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";

    return 0;
}
/*Input	Output
12
7
1
12
20
21
56
60
75	true
7
3
12
14
20	false*/
