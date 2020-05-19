/*************************************************************************
	> File Name: P3367.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月11日 星期一 23时05分23秒
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

int f[MAX_N + 5];

int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            f[find(x)] = find(y);
        } else {
            if (find(x) == find(y)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }
    return 0;
}


