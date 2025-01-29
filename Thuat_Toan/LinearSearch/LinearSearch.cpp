#include <iostream>
using namespace std;

int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int main()
{
    int a[] = {15, 21, 12, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 21;
    int result = LinearSearch(a, n, x);
    if (result == -1)
        cout << "Khong co trong mang";
    else
        cout << "Tim thay o vi tri thu " << result;
    return 0;
}