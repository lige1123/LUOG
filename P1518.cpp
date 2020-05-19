/*************************************************************************
	> File Name: P1518.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月14日 星期四 06时48分56秒
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

char c[15][15];

int f[5] = {-1, 0, 1, 0};

int p1 = 0, q1 = 1, p2 = 0, q2 = 1;

int main() {
    int x1, y1, x2, y2;
    for (int i = 0; i < 10; i++) {
        cin >> c[i];
        for (int j = 0; j < 10; j++) {
            if (c[i][j] == 'F') {
                x1 = i, y1 = j;
            } else if(c[i][j] == 'C') {
                x2 = i, y2 = j;
            }
        }
    }
    //cout << x1 << " " << y1 << endl;
    //cout << x2 << " " << y2 << endl;
    int ans = 0;
    while (1) {
        if (x1 == x2 && y1 == y2) break;
        if (ans > 400005) {
            cout << 0 << endl;
            return 0;
        }
        if (x1 + f[p1] < 0 || x1 + f[p1] > 9 || y1 + f[q1] < 0 || y1 + f[q1] > 9 || c[x1 + f[p1]][y1 + f[q1]] == '*') {
            p1 = (++p1) % 4;
            q1 = (++q1) % 4;
        } else {
            x1 += f[p1];
            y1 += f[q1];
        }
        if (x2 + f[p2] < 0 || x2 + f[p2] > 9 || y2 + f[q2] < 0 || y2 + f[q2] > 9 || c[x2 + f[p2]][y2 + f[q2]] == '*') {
            p2 = (++p2) % 4;
            q2 = (++q2) % 4;
        } else {
            x2 += f[p2];
            y2 += f[q2];
        }
        //cout << c[x1][y1] << c[x2][y2] << " "<< x2 << " "<< y2 << endl;
        ans++;
    }
    cout << ans << endl;
    return 0;
}



