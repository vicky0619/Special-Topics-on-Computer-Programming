/*
dp[i][j]表示a串前i個字元和b串前j個字元的最短編輯距離
1.dp[i][j]=dp[i-1][j]+1 即先刪除a串的第i個字符，然後使其前i-1個字符與b串的前j個字符相同
2.dp[i][j]=dp[i][j-1]+1 即先讓a串的前i個字元和b串的前j-1個字元相同，然後再在a串後面插入b[j]這個字符
3.dp[i][j]=dp[i-1][j-1]+(a[i]==b[j]?0:1)
  即先讓a串前i-1個字元和b串前j-1個字元相同，看a[i]是否等於b[j]，等於的話不需要操作，不等讓a[i]變成b [j]
dp[i][j]=min{1,2,3}
最後來解決如何保存路徑的問題,p[i][j]=1,2,3，表示得到dp[i][j]的時候是用了第幾個策略
p[i][j]=1，說明用了策略1，是刪除了a[i]，所以輸出刪除對應的語句，注意此時對應的位置是j+1，並接著去p[i- 1][j]
p[i][j]=2，說明用了策略2，是插入了b[j]，所以輸出插入對應的語句，注意此時對應的位置是j，並接著去到p[i][j -1]
p[i][j]=0，表示用了策略3，但沒有更換，不用輸出，並接著去到p[i-1][j-1]
p[i][j]=3，說明用了策略3，是更換了a[i]，所以輸出更換對應的語句，注意此時對應的位置是j，並接著去p[i-1] [j-1]
p數組初始化為-1，p[i][j]=-1，則表示路徑到達了盡頭，或者(i==0 && j==0)也是盡頭標誌，表示a串和b串都已經遞歸處理完
*/ 
#include <cstdio> 
#include <cstring>
 #define N 25
 #define INF 0x3f3f3f3f

char a[N],b[N];
 int dp[N][N],p[N][N];

int min( int i , int j , int * s)
{
    int f,k;
     for (k= 1 ; k<= 3 ; k++ )
         if (s[k]< dp[i][j])
        { dp[i][j] =s[k]; f= k; }
     if (f== 3 && a[i]==b[j]) f= 0 ;
     return f;
}

void print( int i , int j)
{
    
    if (!i && !j) return ;
     else  if (p[i][j]== 1 ) //刪除a串第i個字元
    {
        print(i - 1 ,j);
        printf( " D%c%02d " ,a[i],j+ 1 );
         return ;
    }
    else  if (p[i][j]== 2 ) //在a串最後（第i個字元後）插入字元b[j] 
    {
        print(i,j - 1 );
        printf( " I%c%02d " ,b[j],j);
         return ;
    }
    else  if (p[i][j]== 0 ) //什麼都不做
    {
        print(i - 1 ,j- 1 );
         return ;
    }
    else  //把a[i]變成b[j] 
    {
        print(i - 1 ,j- 1 );
        printf( " C%c%02d " ,b[j],j);
         return ;
    }
}

int main()
{
    int lena,lenb;
     while ( 1 )
    {
        scanf( " %s " ,a+ 1 ); 
         if (a[ 1 ]== ' # ' ) break ;
        scanf( " %s " ,b+ 1 );
        lena =strlen(a+ 1 ); lenb=strlen(b+ 1 );
        memset(dp, 0x3f , sizeof (dp));
        memset(p, - 1 , sizeof (p));
         for ( int i= 0 ; i<=lena; i++) { dp[i][ 0 ]=i; p[i][ 0 ]= 1 ; }
         for ( int i= 0 ; i<=lenb; i++) { dp[ 0 ][i]=i; p[ 0 ][i]= 2 ; }
         // dp[1][1]=(a[1] ==b[1]?0:1);

        for ( int i= 1 ; i<=lena; i++ )
             for ( int j= 1 ; j<=lenb; j++ )
            {
                int s[ 4 ];
                s[ 1 ]=dp[i- 1 ][j]+ 1 ;
                s[ 2 ]=dp[i][j- 1 ]+ 1 ;
                s[ 3 ]=dp[i- 1 ][j- 1 ]+(a[i]==b[j]? 0 : 1 );
                p[i][j] = min(i,j,s);
            }
        // printf("最短編輯距離:%d\n",dp[lena][lenb]); 
        print(lena ,lenb);
        printf( " E\n " );
    }
    return  0 ;
}