/*************************************************************************
	> File Name: 1009.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 17时42分57秒
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

int f[55][100005] = {0};


void init() {
    f[1][0] = 1;
    f[1][1] = 1;
    for (int i = 2; i <= 50; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= f[i][0]; j++) {
            f[i][j] += (f[i - 1][j] * i);
            if (f[i][j] >= 10) {
                f[i][j + 1] += (f[i][j] / 10);
                f[i][j] %= 10;
                if(j == f[i][0]) f[i][0]++;
            }
        }
    }
    for (int i = 2; i <= 50; i++) {
  //      f[i][0] = f[i - 1][0];
        for (int j = 1; j <= f[i][0]; j++) {
            f[i][j] += f[i - 1][j];
            if (f[i][j] >= 10) {
                f[i][j + 1] += (f[i][j] / 10);
                f[i][j] %= 10;
                if(j == f[i][0]) f[i][0]++;
            }
        }
    }
    return ;
}



int main() {
    init();
    int n;
    cin >> n;
    for (int i = f[n][0]; i >= 1; i--) {
        cout << f[n][i];
    }
    cout << endl;
    return 0;
}



