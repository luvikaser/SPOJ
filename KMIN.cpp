#include<iostream>
using namespace std;

void qsort(int x[], int l, int r){
    if (l >= r) return;
    int i = l, j = r, key = x[(l + r) / 2];
    while (i <= j){
        while (x[i] < key) ++i;
        while (x[j] > key) --j;
        if (i <= j){
            swap(x[i], x[j]);
            ++i;
            --j;
        }
    }
    qsort(x, i, r);
    qsort(x, l, j);
}

int main(){
    int m, n, k;
    int a[50000], b[50000];
    cin >> m >> n >> k;
    for( int i = 0; i < m; ++i){
        cin >> a[i];
    }

    for( int i = 0; i < n; ++i){
        cin >> b[i];
    }

    qsort(a, 0, m - 1);
    qsort(b, 0, n - 1);


    return 0;
}
