#include<iostream>
using namespace std;

int BinarySearch(int a[], int left, int right, int x)
{
    while(left<=right)
    {
        int mid = left + (right -left )/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]<x)
            left = mid+1;
        else 
            right=mid -1;
    }
    return -1;
}

int main()
{
    int a[]={12,21,15,31,28};
    int x=15;
    int n = sizeof(a)/sizeof(a[0]);
    int result = BinarySearch(a,0,n-1,x);
    if (result == -1)
        cout << "Khong co trong mang";
    else
        cout << "Tim thay o vi tri thu " << result;
    return 0;
}