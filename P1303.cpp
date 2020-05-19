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
    if (str1 == "0" || str2 == "0") {
        cout << 0 << endl;
        return 0;
    }
    int a[50010] = {0}, b[50010] = {0};
    a[0] = str1.size();
   // cout << "a[0] = " << a[0] << " b[0] = " << str2.size() << endl;
    b[0] = str2.size();
    int cnt = 1;
    for (int i = str1.size() - 1; i >= 0; i--) {
        a[cnt++] = str1[i] - '0';
    }
    cnt = 1;
    for (int i = str2.size() - 1; i >= 0; i--) {
        b[cnt++] = str2[i] - '0';
    }
    int c[50005] = {0};
    for (int i = 1; i <= a[0]; i++) {
      //  cout << "a[i] = " << a[i] << endl;
        cnt = i - 1;
        for (int j = 1; j <= b[0]; j++) {
            if (c[cnt] >= 10) {
                c[cnt + 1] += (c[cnt] / 10);
                c[cnt] %= 10;
            }
        //    cout << "b[j] = " << b[j];
            c[++cnt] += (a[i] * b[j]);
        }
    }
    for (int i = cnt; i >= 1; i--) cout << c[i];
    cout << endl;
    return 0;
}



