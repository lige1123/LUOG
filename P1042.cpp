/*************************************************************************
	> File Name: P1042.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 01时33分43秒
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

int main() {
    char str[28];
    int a[MAX_N + 5] = {0}, b[MAX_N + 5] = {0}, c[MAX_N + 5] = {0}, d[MAX_N + 5] = {0};
    int s = 0, cnt1 = 0, cnt2 = 0;
    while (cin >> str) {
        s = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'W') {
                a[cnt1]++, b[cnt2]++;
            } else if (str[i] == 'L') {
                c[cnt1]++;
                d[cnt2]++;
            } else {
                s = 1;
                break;
            }
            if ((a[cnt1] >= 11 || c[cnt1] >= 11) && (fabs(a[cnt1] - c[cnt1]) >= 2)) {
                cnt1++;
            }
            if ((b[cnt2] >= 21 || d[cnt2] >= 21) && (fabs(b[cnt2] - d[cnt2]) >= 2)) {
            //if ((b[cnt2] >= 21 || d[cnt2] >= 21) && (fabs(b[cnt2] - d[cnt2]) >= 2)) {
                cnt2++;
            }
        }
        if (s) break;
    }
    for (int i = 0; i <= cnt1; i++) {
        cout << a[i] << ":" << c[i] << endl;
    }
    cout << endl;
    for (int i = 0; i <= cnt2; i++) {
        cout << b[i] << ":" << d[i] << endl;
    }
    return 0;
}



