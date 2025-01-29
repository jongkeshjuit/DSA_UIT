#include <iostream>
#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

void NhapMang(int *a, int &n){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void XuatMang(int A[], const int &N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}
// insert code here
void Merge(int a[], int l,int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(int i = 0 ; i < n1 ; i++)
        L[i] = a[l +  i];
    for(int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0 , j = 0 , k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
        k++;
    }

    while(i < n1)
        a[k++] = L[i++];
    while(j < n2)
        a[k++] = R[j++];
}

void MergeSort(int a[], int l, int r)
{
    if(l >= r) return;

    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m , r);
}

void MergeSort(int a[], int n)
{
    MergeSort(a, 0, n - 1);
}
// insert code here

int main() {
    int n, a[MAXN];
    NhapMang(a, n);

    MergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
/*Input	Output
7
8 5 3 9 0 1 2

7
0 1 2 3 5 8 9
0	0*/
