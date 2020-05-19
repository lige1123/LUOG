/*************************************************************************
	> File Name: P1551.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月11日 星期一 23时28分26秒
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
#define MAX_N 5000

int f[MAX_N + 5];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}


int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int j = 0; j < m; j++) {
        int x, y;
        cin >> x >> y;
        f[find(x)] = find(y);
    }
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}



