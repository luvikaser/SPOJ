#include<iostream>
using namespace std;
struct Node{
    int value, idxA, idxB;
};
Node heap[50000];
int nHeap = 0;

int m, n, k;
int a[50000], b[50000];

void upHeap(int i){
    if (i == 0 || heap[i].value >= heap[i / 2].value) return;
    swap(heap[i], heap[i / 2]);
    upHeap(i / 2);
}

void downHeap(int i){
    int j = i * 2;
    if (j >= nHeap) return;
    if (heap[j].value > heap[j + 1].value) ++j;
    if (heap[i].value > heap[j].value){
        swap(heap[i], heap[j]);
        downHeap(j);
    }
}

void push(int idxA, int idxB){
    heap[nHeap].value = a[idxA] + b[idxB];
    heap[nHeap].idxA = idxA;
    heap[nHeap].idxB = idxB;
    upHeap(nHeap++);
}

Node pop(){
    Node res = heap[0];
    heap[0] = heap[--nHeap];
    downHeap(0);
    return res;
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
    cin >> m >> n >> k;
    for( int i = 0; i < m; ++i){
        cin >> a[i];
    }

    for( int i = 0; i < n; ++i){
        cin >> b[i];
    }

    qsort(a, 0, m - 1);
    qsort(b, 0, n - 1);

    for(int i = 0; i < n; ++i){
        push(0, i);
    }

    for(int i = 0; i < k; ++i){
        Node node = pop();
        cout << node.value << endl;
        push(node.idxA + 1, node.idxB);
    }

    return 0;
}
