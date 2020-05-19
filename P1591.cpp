/*************************************************************************
	> File Name: P1591.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 16时38分30秒
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

int f[1005][3005];

void init() {
    f[1][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= f[i][0]; j++) {
            f[i][j] += f[i - 1][j] * i;
            if (f[i][j] > 9) {
                f[i][j + 1] += (f[i][j] / 10);
                f[i][j] %= 10;
                if (j == f[i][0]) f[i][0]++;
            }
        }
    }
    return ;
}



int main() {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, ans = 0;
        cin >> a >> b;
        for (int j = 1; j <= f[a][0]; j++) {
            f[a][j] == b && ans++;
        }
        cout << ans << endl;
    }
    return 0;
}


