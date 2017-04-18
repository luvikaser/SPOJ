#include<iostream>
#include<climits>

using namespace std;
int a[200001], b[200001];
int na = 0, nb;
int res = 0;

int findPosition(int i){
    int l = 1, r = nb;
    while (l < r){
        int mid = (l + r) / 2;
        if (a[i] >= a[b[mid]]){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (a[i] < a[b[l]]) --l;
    return l;
}
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
    int n, m;
    cin >> n >> m;

    int l[200001], l1[200001];
    a[na] = INT_MIN;
    //Read data
    for(int i = 0; i < n; ++i){
        int t1, k;
        cin >> t1 >> k;
        int n1 = 0;
        int a1[200001];
        for(int j = 0; j < k; ++j){
            int x;
            cin >> x;
            if (x - res >= 0){
                a1[n1++] = x - res;
            }
        }
        qsort(a1, 0, n1 - 1);
        for(int j = 0; j < n1; ++j){
            a[++na] = a1[j];
        }
        res += t1;
    }

    //Init
    l[0] = 1;
    l1[0] = 0;
    b[1] = 0;
    nb = 1;

    int res1 = 0, h = 1;
    for(int i = 1; i <= na; ++i){
        int j = findPosition(i);
        int k = l[b[j]] + 1;
        if (k > nb){
            nb = k;
            b[k] = i;
        } else if (a[b[k]] >= a[i]){
            b[k] = i;
        }
        l[i] = k;
        l1[i] = l1[b[j]] + a[i] - a[b[j]];

        if (k >= h && k <= m + 1){
            if ((k > h) || (k == h && l1[i] < res1)){
                h = k;
                res1 = l1[i];
            }
        }
    }
    cout << res + res1 - INT_MIN;
    return 0;
}

