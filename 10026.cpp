//本題解法是將每個工作(Fi/Ti)由大到小排序
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0);

struct job{
    double f_t;
    int order;
};

bool cmp(job a, job b){
    return a.f_t>b.f_t;
}

int main(){
    IOS
    int t;
    string blank;
    cin >> t;
    while(t--){
        getline(cin,blank);
        int n;
        cin >> n;
        job j[n+5];
        //cout << "n= " << n << "\n";
        for(int i=0;i<n;i++){
            double time, fine;
            cin >> time >> fine;
            j[i].f_t=fine*1.0/time;
            j[i].order=i+1;
        }
        
        sort(j,j+n,cmp);
        cout << j[0].order;
        for(int i=1;i<n;i++){
            cout << " " << j[i].order;
        }
        cout << "\n";
        if(t) cout << "\n";
    }

    return 0;
}
