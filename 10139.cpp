#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0);

int cnt_primes(int n, int p){
    int cnt=0;
    while(n>1){
        cnt+=n/p;
        n/=p;
    }
    return cnt;
}

void solve(int n, int m){
    map<int, int> primes;
    int tm=m;
    for(int i=2;i<=m/i; ++i){
        while(m%i==0) primes[i]++, m/=i;
    }
    if(m>1) primes[m]++;

    for(auto p : primes){
        if(p.second > cnt_primes(n, p.first)){
            cout << tm << " does not divide " << n << "!\n";
            return;
        }
    }
    cout << tm << " divides " << n << "!\n";
    return;
}

int32_t main(){
    int n,m;
    while(cin >> n >> m){
        solve(n,m);
    }
    return 0;
}