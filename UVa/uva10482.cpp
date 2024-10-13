#include <bits/stdc++.h>
using namespace std;
#define int long long

int findMax(int i,int j, int k){
    return max(i, max(j,k));
}

int findMin(int i,int j, int k){
    return min(i, min(j,k));
}

bool dp[645][645];

int32_t main(){
    int t;
    cin >> t;
    for(int c=1;c<=t;c++){
        int n;
        cin >> n;
        int w[n+1],sum=0;
        for(int i=0;i<n;i++) cin >> w[i], sum+=w[i];
        
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int k=0;k<n;k++){
            for(int i=sum;i>=0;i--){
                for(int j=sum;j>=0;j--){
                    dp[i][j] = (dp[i][j]) && (i>=w[k] && dp[i-w[k]][j]) &&  (j>=w[k] && dp[i][j-w[k]]);
                }
            }
        }

        int ans=INT32_MAX;
        for(int i=0;i<=sum;i++){
            for(int j=i;j<=sum;j++){
                if(dp[i][j]) ans = min(ans, findMax(i,j,sum-i-j)-findMin(i,j,sum-i-j));
            }
        }
        cout << "Case " << c << ": " << ans << "\n";
    }
    return 0;
}