/*************************************************************************
	> File Name: P1002.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月08日 星期五 11时13分14秒
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


int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    long long dp[25][25] = {0};
    dp[0][1] = 1;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if ((i == x && j == y) ||(((i == x - 1) && (j == y - 2 || j == y + 2)) || ((i == x - 2) && (j == y - 1 || j == y + 1)) || (i == x + 1) && (j == y - 2 || j == y + 2) || (i == x + 2 && (j == y - 1 || j == y + 1)))) {
                dp[i + 1][j + 1] = 0;
                continue;
            }
            dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
        }
    }
    cout << dp[a + 1][b + 1] << endl;
    return 0;
}


