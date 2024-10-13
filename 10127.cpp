#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);

int32_t main(){
    int n;
    while(cin >> n){
        int tmp=1, cnt=1;
        while(tmp%n){
            tmp = tmp%n*10+1;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}