/*************************************************************************
	> File Name: P1601.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 03时04分32秒
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
    string str1, str2;
    cin >> str1 >> str2;
    int a[510] = {0}, b[510] = {0};
    a[0] = str1.size();
    b[0] = str2.size();
    int cnt = 1;
    for (int i = str1.size() - 1; i >= 0; i--) {
        a[cnt++] = str1[i] - '0';
    }
    cnt = 1;
    for (int i = str2.size() - 1; i >= 0; i--) {
        b[cnt++] = str2[i] - '0';
    }
    int c[505] = {0};
    for (int i = 1; i <= 505; i++) {
        c[i] += (a[i] + b[i]);
        if (c[i] >= 10) {
            c[i + 1]++;
            c[i] %= 10;
        }
    }
    int sum = 504;
    while(!c[sum] && sum > 0) sum--;
    if (sum == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = sum; i >= 1; i--) cout << c[i];
    cout << endl;
    return 0;
}



