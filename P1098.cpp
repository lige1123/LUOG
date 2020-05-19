/*************************************************************************
	> File Name: P1098.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月14日 星期四 08时53分50秒
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

#define MAX_N 1000

char c[MAX_N + 5];
int p[5];

int main() {
    int i = 0;
    cin >> p[0] >> p[1] >> p[2];
    cin >> c;
    while (i < strlen(c)) {
        if (i > 0 && c[i] == '-' && c[i + 1] > c[i - 1] && ( c[i - 1] >= '0' && c[i + 1] <= '9' || c[i - 1] >= 'a' && c[i + 1] <= 'z')) {
            int a = c[i - 1], b = (int)c[i + 1];
            if (p[2] == 1) {
                for (int j = a + 1; j <= b - 1; j++) { 
                    if (p[0] == 1) {
                        for (int i = 0; i < p[1]; i++) {
                            if ((j >= '0' && j <= '9') || (j >= 'a' && j <= 'z')) {
                                printf("%c", j);
                            } else if (j >= 'A' && j <= 'Z') {
                                printf("%c", j - 'A' + 'a');
                            }
                        }
                    } else if (p[0] == 2) {
                        for (int i = 0; i < p[1]; i++) {
                            if ((j >= '0' && j <= '9') || (j >= 'A' && j <= 'Z')) {
                                printf("%c", j);
                            } else if (j >= 'a' && j <= 'z') {
                                printf("%c", j - 'a' + 'A');
                            }
                        }
                    } else if (p[0] == 3) {
                        for (int i = 0; i < p[1]; i++) {
                            cout << '*';
                        }
                    }
                }
            } else if(p[2] == 2) {
                for (int j = b - 1; j >= a + 1; j--) { 
                    if (p[0] == 1) {
                        for (int i = 0; i < p[1]; i++) {
                            if ((j >= '0' && j <= '9') || (j >= 'a' && j <= 'z')) {
                                printf("%c", j);
                            } else if (j >= 'A' && j <= 'Z') {
                                printf("%c", j - 'A' + 'a');
                            }
                        }
                    } else if (p[0] == 2) {
                        for (int i = 0; i < p[1]; i++) {
                            if ((j >= '0' && j <= '9') || (j >= 'A' && j <= 'Z')) {
                                printf("%c", j);
                            } else if (j >= 'a' && j <= 'z') {
                                printf("%c", j - 'a' + 'A');
                            }
                        }
                    } else if (p[0] == 3) {
                        for (int i = 0; i < p[1]; i++) {
                            cout << '*';
                        }
                    }
                }
                
            }
        } else {
            cout << c[i];
        }
        i++;
    }
    cout << endl;
    return 0;
}



