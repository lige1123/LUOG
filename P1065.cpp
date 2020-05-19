/*************************************************************************
	> File Name: P1065.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月14日 星期四 23时19分53秒
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

int Num[405];
int f[25][25];
int g[25][25];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> num[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    } 
    cout << fmax(ans11, ans21) << endl;;
    return 0;
}

