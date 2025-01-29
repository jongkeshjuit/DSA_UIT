#include <iostream>
using namespace std;

void Nhap(int a[], int n)
{
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
}

void Xuat(int a[], int n)
{
    for(int i = 0 ; i < n ; i++)
        cout << a[i] << " ";
}

// merge sort
void merge(int a[], int left, int mid, int right)
{
    // khoi tao
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    // chuyen data
    for(int i = 0 ; i < n1 ; ++i)
        L[i] = a[left + i];
    for(int j = 0 ; j < n2 ; ++j)
        R[j] = a[mid + 1 +j];
    // chi so
    int i = 0 , j = 0 , k = left ;
    // gop
    while( i < n1 && j < n2 )
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    // sao chep con lai
    while(i < n1)
        a[k++] = L[i++];
    while(j < n2)
        a[k++] = R[j++];
}

int main()
{
    int x = 2, n = 6, a[] = { 3, 5, 6, 2 , 7, 8 };
    cout << "Mang a : ";
    Xuat(a, n);
    cout << endl;
    cout << "Sap xep theo merge sort: ";
    merge(a, 0, (n - 1) /2 , n - 1);
    Xuat(a, n);
}
