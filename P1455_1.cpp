/*************************************************************************
	> File Name: P1455_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 02时40分15秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<deque>
#include<functional>
#include<list>
#include<map>
#include<iomanip>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
#define MAX_N 10000
#define REP(i, n) for (int i = 0, I = n; i < I; i++)

int dp[MAX_N + 5];

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) { REP(i, n + 1) { fa[i] = i; } }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) { fa[get(a)] = get(b); }
    bool isroot(int x) { return x == fa[x]; }
} u;

int c[MAX_N + 5], d[MAX_N + 5];

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    u.init(n);
    for (int i = 1; i <= n; i++) cin >> c[i] >> d[i];
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        u.merge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (u.isroot(i)) continue;
        c[u.get(i)] += c[i];
        d[u.get(i)] += d[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!u.isroot(i)) continue;
        for (int j = w; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
        }
    }
    cout << dp[w] << endl;
    return 0;
}



