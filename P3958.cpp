/*************************************************************************
	> File Name: P3958.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 00时07分17秒
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

#define MAX_N 1000

int f[MAX_N + 5];
long long x[MAX_N + 5], y[MAX_N + 5], z[MAX_N + 5];
int f1[MAX_N + 5], f2[MAX_N + 5];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}


long long dis(int a, int b) {
    return ((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]) + (z[a] - z[b]) * (z[a] - z[b]));
}


int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        long long h, r;
        cin >> n >> h >> r;
        long long Dis = 4 * r * r;
        int tot1 = 0, tot2 = 0;
        for (int j = 0; j <= n; j++) {
            f[j] = j;
        }
        for (int j = 0; j < n; j++) {
            cin >> x[j] >> y[j] >> z[j];
            if (z[j] + r >= h) {
                f1[tot1++] = j;
            }
            if (z[j] - r <= 0) {
                f2[tot2++] = j;
            }
            for (int k = 0; k < j; k++) {
                if (dis(j, k) <= Dis) {
                    f[find(j)] = find(k);
                }
            }
        }
        int flag = 0;
        for (int j = 0; j < tot1; j++) {
            for (int k = 0; k < tot2; k++) {
                if (find(f1[j]) == find(f2[k])) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}


