#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int N = 1010;
const int M = 1010;

struct point{
    int x, y;
};

int n, m;
point a[N], b[M];
float res = 50000;

bool check(point corner, point p1, point p2){
    return ((p1.x - corner.x) * (p2.x - corner.x) + (p1.y - corner.y) * (p2.y - corner.y) <= 0)
}

float dis(point p1, point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float dis(point p1, point p2, point p){
    int a = p2.y - p1.y;
    int b =
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].y;
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i].x >> b[i].y;
    }

    for(int i = 0; i < n; ++i){
        point p = a[i];
        for(int j = 0; j < m - 1; ++j){
            point p1 = b[j], p2 = b[j + 1];
            if check(p1, p2, p){
                res = min (res, dis(p1, p));
            } else if check(p2, p1, p){
                res = min(res, dis(p2, p));
            } else{
                res = min(res, dis(p1, p2, p));
            }
        }
    }
    printf("%.3f", res);
    return 0;
}
