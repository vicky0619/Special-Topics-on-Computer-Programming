#include <bits/stdc++.h>
using namespace std;
int c,tmp;
bool dp[201][10001];
bool route[201][10001];
vector <int> cars;
vector <int> sum;
int totalCarLen = 0;
int maxCar,maxLen,len;
int main(){
  cin >> c;
  while(c--){
    cin >> len;
    len *= 100;
    //cars = {0};
    //sum = {0};
    memset(dp,0,sizeof(dp));
    totalCarLen = maxCar = maxLen = 0;
    while(cin >> tmp && tmp != 0){
      cars.push_back(tmp);
      totalCarLen += tmp;
      sum.push_back(totalCarLen);
    }
    dp[0][0] = 1;
    for(int i=1;i<cars.size();i++){
      for(int j=0;j<=len;j++){
        if(j>=cars[i]&&dp[i-1][j-cars[i]]){ //put left
          maxCar = i;
          maxLen = j;
          dp[i][j] = 1;
          route[i][j] = 0; // put left
        }
        if(sum[i]-j<=len && dp[i-1][j]){ //put right
          maxCar = i;
          maxLen = j;
          dp[i][j] = 1;
          route[i][j] = 1; // put right
        }
      }
      if(maxCar != i) break; //can't put left nor right
    }

    cout << maxCar << endl;

    int i = maxCar,j = maxLen;
    stack <bool> pos;
    while(i){ // track the route
      pos.push(route[i][j]);
      if(!route[i][j]) // put left
        j -= cars[i];
      i --;
    }
    while(!pos.empty()){
      bool p = pos.top(); pos.pop();
      if(!p) // left
        cout << "starboard" << endl;
      else  //right
        cout << "port" << endl;
    }

    if(c)
      cout << endl;
  }
  return 0;
}