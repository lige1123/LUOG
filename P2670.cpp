/*************************************************************************
	> File Name: P2670.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 02时31分10秒
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
    int a[105][105] = {0};
    int n, m;
    cin >> n >> m;
    char b[105][105];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == '*') {
                cout << b[i][j];
                continue;
            }
            if (j - 1 >= 0 && i - 1 >= 0&& b[i - 1][j - 1] == '*') a[i][j]++;
            if (j - 1 >= 0 && b[i][j - 1] == '*') a[i][j]++;
            if (j - 1 >= 0 && b[i + 1][j - 1] == '*') a[i][j]++;
            if (i - 1 >= 0 && b[i - 1][j] == '*') a[i][j]++;
            if (i - 1 >= 0 && b[i - 1][j + 1] == '*') a[i][j]++;
            if (b[i][j + 1] == '*') a[i][j]++;
            if (b[i + 1][j] == '*') a[i][j]++;
            if (b[i + 1][j + 1] == '*') a[i][j]++;
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}


