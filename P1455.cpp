/*************************************************************************
	> File Name: P1455.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月12日 星期二 00时56分22秒
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


int Pri[MAX_N + 5], Val[MAX_N + 5];
int f[MAX_N + 5];
int NPri[MAX_N + 5], NVal[MAX_N + 5];
int s[MAX_N + 5];

int find(int x) {
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}



int main() {
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++) {
        f[i] = i;
        cin >> Pri[i] >> Val[i];
    }
    int ans = 0, num = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int p = find(u), q = find(v);
        if (p == q) continue;
      //  cout << "p ^ ans = " << (p ^ ans) << endl;
      //  cout << "ans = " << ans << endl;
        if (((ans ^ p) >= ans) && ((ans ^ q) >= ans)) {
           // cout << "1p ^ ans = " << (p ^ ans) << endl;
           // cout << "1ans = " << ans << endl;
            ans ^= q;
            s[q] = num;
            f[p] = q;
            NPri[num] = Pri[u] + Pri[v];
            NVal[num++] = Val[u] + Val[v];
        } else {
            if ((ans ^ p != ans)) {
                f[q] = find(u);
                NPri[s[p]] += Pri[v];
                NVal[s[p]] += Val[v];
            } else {
                f[p] = q;
                NPri[s[q]] += Pri[p];
                NVal[s[q]] += Val[p];
            }
        }
        Pri[u] = Pri[v] = 0;
        Val[u] = Val[u] = 0;
    }
    int a = 0;
    cout << num << endl;
    for (int i = num - 1; i >= 0; i--) {
        if (NPri[i] <= w && NVal[i] > a) {
            a = NVal[i];
        }
    }
    cout <<"a = " << NVal[0] << endl;
    for (int i = 0; i < n; i++) {
        if (Val[i] == 0) continue;
        if (Pri[i] <= w && Val[i] > a) a = Val[i];
    }
    cout << a << endl;
    return 0;
}


