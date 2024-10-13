#include <bits/stdc++.h>
using namespace std;
#define long long int

int sol(int n){
    int N=n, sum=0, left=1, mid, right=1;
    while(N>=10){
        mid = N%10;
        N /= 10;
        if(mid) sum += N*left;
        else sum += ((N-1)*left + n%right+1);
        left *= 10;
        right *= 10;
    }
    return sum;
}

int32_t main(){
    int m,n;
    while(cin >> m >> n){
        if(m<0) break;
        int ans = sol(n) - sol(m-1);
        if(m==0) ans++;
        cout << ans << "\n";
    }
    return 0;
}