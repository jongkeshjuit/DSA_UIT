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

int linearsearch(int a[], int n, int x)
{
    for(int i = 0 ; i < n ; i++)
        if(a[i] == x)
            return i;
    return -1;
}

// no recursive
int binarysearch(int a[], int n, int x)
{
    int left = 0 , right  = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(a[mid] == x) return mid;
        if(a[mid] > x) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

// recursive
int dequy(int a[], int x, int left, int right)
{
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(a[mid] == x) return mid;
    if(a[mid] > x) return dequy(a, x, left, mid -1);
    return dequy(a, x, mid + 1, right);
}
int binarysearch_dequy(int a[], int n, int x)
{
    return dequy(a, x, 0, n - 1);
}
// selectionsort
void selectionsort(int a[], int n)
{
    for(int i = 0 ; i < n - 1; ++i)
    {
        int index = i;
        for(int j = i + 1; j <  n ; ++j )
            if(a[j] < a[index])
                index = j;
        swap(a[i], a[index]);
    }
}
// intertionsort
void intertionsort(int a[], int n)
{
    for(int i = 1 ; i < n ; ++i)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int x = 2, n = 6, a[] = { 3, 5, 6, 2 , 7, 8 };
    cout << "Mang a : ";
    Xuat(a, n);
    cout << endl;
    // linearsearch
    cout << "linearsearch: vi tri = ";
    int vitri1 = linearsearch(a, n, x); cout << vitri1 << endl;
    // binarysearch no recursive voi mang da sort
    int b[] = {1, 2 , 3 , 4 , 5 , 6};
    cout << "Mang b: ";
    Xuat(b, n);
    cout << endl;
    cout << "binarysearch no recursive: vitri = ";
    int vitri2 = binarysearch(b, n, 5); cout << vitri2 << endl;
    // binarysearch_dequy
    cout << "binarysearch recursive: vitri = ";
    int vitri3 = binarysearch_dequy(b, n, 6); cout << vitri3 << endl;
    // selectionsort
    cout << "\nSap xep mang: ";
    cout << "\nSap xep theo selectionsort mang a: ";
    selectionsort(a, n);
    Xuat(a, n);
    // intertionsort
    cout << "\nSap xep theo intertionsort mang a: ";
    intertionsort(a, n);
    Xuat(a, n);
    cout << endl;
}
