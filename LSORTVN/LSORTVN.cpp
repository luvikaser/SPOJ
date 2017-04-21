#include <iostream>

using namespace std;
const int N = 1010;

int n;
int p[N], pos[N], k[N][N], dp[N][N];

int process(int l, int r){
    if (l == r) return pos[l];
    if (dp[l][r] > 0) return dp[l][r];
    int len = r - l + 1;
    int x1 = process(l + 1, r) + k[l][r] * len;
    int x2 = process(l, r - 1) + k[r][l] * len;
    dp[l][r] = min(x1, x2);
    return dp[l][r];
}

int main(){

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
        pos[p[i]] = i;
    }

    for(int i = 1; i <= n; ++i){
        int posI = pos[i];
        for(int j = i + 1; j <= n; ++j){
            if (pos[j] < pos[i]) --posI;
            k[i][j] = posI;
        }
        posI = pos[i];
        for(int j = i - 1; j >= 1; --j){
            if (pos[j] < pos[i]) --posI;
            k[i][j] = posI;
        }
    }
    cout << process(1, n);
    return 0;
}
