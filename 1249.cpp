/*************************************************************************
	> File Name: 1249.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月15日 星期五 17时04分52秒
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


int f[10005];
int m[100005];

void check(int a) {
    m[0] = 1;
    m[1] = 1;
    int flag = 0;
    for (int i = 1; i <= a; i++) {
        if (f[i] == 1) {
            flag == 0 || cout << " ";
            cout << i;
            int bns = 0;
            for (int j = 1; j <= m[0]; j++) {
                m[j] = m[j] * i;
                m[j] += bns;
                if (m[j] > 9) {
                    bns = (m[j] / 10);
                    m[j] %= 10;
                    if (j == m[0]) m[0]++;
                } else {
                    bns = 0;
                }
            }
            flag = 1;
        }
    }
}



int main() {
    int n, i = 2, ans = 0;
    cin >> n;
    while (ans < n && i < n) {
        ans += i;
        f[i] = 1;
        i++;
    }
    if (ans > n) {
        f[ans - n] = 0;
        if ((ans - n) == 1) {
            f[2] = 0;
            f[1] = 1;
        }
    }
    check(ans);
    cout << endl;
    for (int i = m[0]; i >= 1; i--) {
        cout << m[i];
    }
    cout << endl;
    return 0;
}


