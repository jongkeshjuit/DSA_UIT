/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#define MAXN 100000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

//###INSERT CODE HERE -
void insertion_sort_decending(int A[], int N) {
    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] < key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
//###INSERT CODE HERE -

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    insertion_sort_decending(a, n);

    XuatMang(a, n);

    return 0;
}

/*
Input	Output
7
8 5 3 9 0 1 2	7
9 8 5 3 2 1 0
0	0*/
