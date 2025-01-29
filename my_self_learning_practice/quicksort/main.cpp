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

// Quicksort
void quicksort(int a[], int left, int right)
{
    int i, j, pivot;
    i = left, j = right;
    pivot = a[(left + right) /2];
    while(i <= j)
    {
        while(a[i] < pivot) i++; // truong hop tang, neu giam thi doi thanh >
        while(a[j] > pivot) j--; // truong hop tang, neu giam thi doi thanh <
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        if(left < j) quicksort(a, left, j);
        if(i < right) quicksort(a, i, right);
    }
}
void quicksort_tang(int a[], int n)
{
    quicksort(a, 0, n - 1);
}

int main()
{
    int x = 2, n = 6, a[] = { 3, 5, 6, 2 , 7, 8 };
    cout << "Mang a : ";
    Xuat(a, n);
    cout << endl;
    // quicksort tang
    cout << "Quicksort mang a: ";
    quicksort_tang(a, n);
    Xuat(a, n);
    cout << endl;
}
