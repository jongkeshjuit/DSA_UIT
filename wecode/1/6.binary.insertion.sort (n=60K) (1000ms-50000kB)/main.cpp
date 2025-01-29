
#include <iostream>
#define MAXN 60000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

// Function to sort an array a[] of size 'n'
void binary_insertion_sort(int a[], int n) {
    int i, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];
    // insert code here
    int left = 0 , right = j;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(selected < a[mid])
            left = mid + 1;
        else
             right = mid - 1;
    }
    k = left;
    while(j >= k)
    {
        a[j + 1] = a[j];
        j--;
    }
    // insert code here
        a[j + 1] = selected;
    }
}
bool is_decending(int A[], int N) {
    for (int i = 0; i < N-1; i++)
        if(A[i]<A[i+1]) return false;
    return true;
}
void XuatMang(int A[], const int &N) {
    // std::cout << is_decending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\n";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    binary_insertion_sort(a, n);

    XuatMang(a, n);

    return 0;
}
