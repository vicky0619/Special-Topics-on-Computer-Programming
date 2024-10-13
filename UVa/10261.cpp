#include <bits/stdc++.h>
using namespace std;
#define int long long

bool dp[205][10005];
bool route[205][10005];

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int len;
        cin >> len;
        len*=100;

        int tmp, sum=0;
        vector<int> cars(1,0);
        vector<int> sumw(1,0);
        while(cin >> tmp && tmp){
            cars.push_back(tmp);
            sum+=tmp;
            sumw.push_back(sum);
        }

        memset(dp, 0, sizeof(dp));
        //memset(route, 0, sizeof(route));
        dp[0][0]=1;
        int maxCar=0, maxLen=0;

        for(int i=1;i<cars.size();i++){
            for(int j=0;j<=len;j++){
                if(j-cars[i]>=0 && dp[i-1][j-cars[i]]){
                    dp[i][j]=1;
                    route[i][j]=0;
                }
                if(sumw[i]-j<=len && dp[i-1][j]){
                    dp[i][j]=1;
                    route[i][j]=1;
                }
                if(dp[i][j]) maxCar=i, maxLen=j;
            }
            if(maxCar!=i) break;
        }
        cout << maxCar << "\n";

        int i=maxCar, j=maxLen;
        stack<bool> pos;
        while(i){
            pos.push(route[i][j]);
            if(route[i][j]==0) j-=cars[i];
            i--;
        }
        while(!pos.empty()){
            bool p=pos.top();
            pos.pop();
            if(!p) cout << "starboard\n";
            else cout << "port\n";
        }

        if(t) cout << "\n";
    }

    return 0;
}