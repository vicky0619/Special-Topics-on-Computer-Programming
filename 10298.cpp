#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    string s;
    while(cin >> s && s!="."){
        int len=s.size();
        int nxt[len+1];
        nxt[0]=-1;
        int k=-1;
        for(int i=1;i<len;i++){
            while(k!=-1 && s[i]!=s[k+1]) k=nxt[k]; //k=nxt[k] 都是k
            if(s[i]==s[k+1]) k++;
            nxt[i]=k;
        }
        int n=len-1;
        if(!((n+1)%(n-nxt[n]))) cout << (n+1)/(n-nxt[n]) << "\n";
        else cout << "1\n";
    }
}