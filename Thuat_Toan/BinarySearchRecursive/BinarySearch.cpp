#include<iostream>
using namespace std;

void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap a[" << i << "] = ";
        cin >> a[i];
    }
}

int binarySearch(int a[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] > x) {
            return binarySearch(a, l, mid - 1, x);
        }
        return binarySearch(a, mid + 1, r, x);
    }
    return -1;
}

int binarySearch(int a[], int n, int x) {
    return binarySearch(a, 0, n - 1, x);
}

int main() {
    int n, x;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int a[n];
    NhapMang(a, n);
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int result = binarySearch(a, n, x);
    if (result == -1) {
        cout << "Khong tim thay " << x << " trong mang" << endl;
    } else {
        cout << x << " duoc tim thay tai vi tri " << result << endl;
    }
    return 0;
}