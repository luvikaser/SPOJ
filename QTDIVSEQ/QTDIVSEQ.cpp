#include<iostream>

using namespace std;
const int N = 1000010;
const int MOD = 1000000007;

int n, k, res = 1;
int a[N];
long long s[N];

int pmod(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = 1LL * r * a % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return r;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if (i > 0){
            s[i] = s[i - 1] + a[i];
        } else{
            s[i] = a[i];
        }
    }
    if (s[n - 1] % k != 0){
        cout << 0;
        return 0;
    }
    long long sumk = s[n - 1] / k;

    if (sumk == 0){
        int d = 0;
        for(int i = 0; i < n; ++i){
            if (s[i] == 0){
                ++d;
            }
        }
        if (d < k){
            res = 0;
        } else{
            int c[N];
            c[0] = 1;
            for(int i = 1; i < d; ++i)
                c[i] = (1LL * c[i - 1] * i) % MOD;
            res = 1LL * c[d - 1] * pmod(1LL * c[d - k] * c[k - 1] % MOD, MOD - 2) % MOD;
        }
    } else{
        int dp[N];
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] % sumk == 0) {
              int id = s[i] / sumk;
              if (id > 0){
              	dp[id] = (dp[id] + dp[id - 1]) % MOD;
              }
            }
        }
        res = dp[k - 1];
    }
    cout << res;
    return 0;
}
