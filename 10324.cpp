#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);

int main(){
    IOS
    string s;
    int cnt=0;
    while(cin >> s){
        cnt++;
        cout << "Case " << cnt << ":\n";
        int n;
        cin >> n;
        while(n--){
            int i, j;
            cin >> i >> j;
            bool allSame = true;
            
            for (int k = min(i, j) + 1; k <= max(i, j); k++) {
                if (s[k] != s[min(i, j)]) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
