/*************************************************************************
	> File Name: P1045.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 01时48分55秒
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

int m[505] = {1, 2};

int n[505] = {1, 1};

int p;

void check1() {
    int a[505] = {0};
    int cnt = 0;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            a[i + j - 1] += m[j] * n[i];
            if (i + j - 1 > 502) break;
        }
    }
    memset(n, 0, sizeof(n));
    for (int i = 0; i <= 500; i++) {
        n[i] += a[i];
        if (n[i] > 9) {
            n[i + 1] += n[i] / 10;
            n[i] %= 10;
        }
    }
}


void check2() {
    int a[505] = {0};
    int cnt = 0;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            a[i + j - 1] += m[j] * m[i];
            if (i + j - 1 > 502) break;
        }
    }
    memset(m, 0, sizeof(m));
    for (int i = 0; i <= 500; i++) {
        m[i] += a[i];
        if (m[i] > 9) {
            m[i + 1] += m[i] / 10;
            m[i] %= 10;
        }
    }
} 

int base = 2;
int ans = 1;

void init() {
    while (p > 0) {
        if (p & 1) {
            p -= 1;
            check1();
        } 
        p /= 2;
        check2();
    }
}

int main() {
    cin >> p;
    cout << ceil(p * log10(2)) << endl;
    init();
    for (int i = 500; i > 2; i--) {
        cout << n[i];
        if (i % 50 == 1) cout << endl;
    }
    if (n[1] == 0) cout << n[2] - 1 << 9 << endl;
    else cout << n[2] << n[1] - 1 << endl;
    return 0;
}


