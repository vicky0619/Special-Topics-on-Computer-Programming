#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sum=0;
        int w[105];
        for(int i=0;i<n;i++) cin >> w[i], sum+=w[i];
        int hsum=sum/2, hn=n/2;
        int dp[hsum+1];
        memset(dp, 0, sizeof(dp));
        dp[0]=1;

        for(int i=0;i<n;i++){
            for(int j=hsum;j>=w[i];j--){
                dp[j] |= dp[j-w[i]]<<1LL;
            }
        }
        
        if(n%2)
            while(!(dp[hsum]&(1LL<<hn)) && !(dp[hsum]&(1LL<<(hn+1)))) hsum--;
        else
            while(!(dp[hsum]&1LL<<hn)) hsum--;
        cout << hsum << " " << sum-hsum << "\n";

        if(t) cout << "\n";
    }
    return 0;
}