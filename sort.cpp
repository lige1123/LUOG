/*************************************************************************
	> File Name: sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 01时12分25秒
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
    int num[5] = {3, 5, 1, 2, 2};
    sort(num + 3, num + 5);
    for (int i = 0; i < 5; i++) cout << num[i] << " ";
    cout << endl;
    return 0;
}


