#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        stringstream ss(s);
        vector<int> w;
        int tmp,sum=0;
        while(ss>>tmp){
            w.push_back(tmp);
            sum+=tmp;
        }
        if(sum%2){
            cout << "NO\n";
            continue;
        }
        bool dp[sum+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<w.size();i++){
            for(int j=sum;j>=w[i];j--){
                if(dp[j-w[i]]){
                    dp[j]=1;
                }
            }
        }
        if(dp[sum/2]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}