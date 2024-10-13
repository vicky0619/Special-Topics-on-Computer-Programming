#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
struct bign
{
	int len,s[maxn];
	bign(){memset(s,0,sizeof(s));len=1;}
	bign operator = (const char *num)
	{
		len=strlen(num);
		for(int i=0;i<len;i++)
		s[i]=num[len-i-1]-'0';
		return *this;
	}
	bign operator = (int num)
	{
		char s[maxn];
		sprintf(s,"%d",num);
		*this=s;
		return *this;
	}
	bign(int num)
	{
		*this =num;
	}
	bign(const char *num)
	{
		*this=num;
	}
	string str() const
	{
		string res="";
		for(int i=0;i<len;i++)
		res=(char)(s[i]+'0')+res;
		if(res=="")
		res="0";
		return res;
	}
	bign operator + (const bign& b) const
	{
		bign c;c.len=0;
		for(int i=0,g=0;g||i<max(len,b.len);i++)
		{
			int x=g;
			if(i<len) x+=s[i];
			if(i<b.len) x+= b.s[i];
			c.s[c.len++]=x%10;
			g=x/10;
		}
		return c;
	}
	bool operator < (const bign& b) const
	{
		if(len!=b.len)
		return len<b.len;
		for(int i=len-1;i>=0;i--)
		if(s[i]!=b.s[i])
		return s[i]<b.s[i];
		return false;
	}
};
istream& operator >>(istream &in,bign& x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}
ostream& operator <<(ostream &out,const bign &x)
{
	out << x.str();
	return out;
}
char s1[10011],s2[101];
bign dp[10011][101];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		cin>>s1>>s2;
		int len1=strlen(s1);
		int len2=strlen(s2);
		for(int i=1;i<=len1;i++)
		{
			if(s1[i-1]==s2[0])
			dp[i][1]=dp[i-1][1]+1;
			else
			{
				if(dp[i][1]<dp[i-1][1])
				dp[i][1]=dp[i-1][1];
			}
		}
		for(int j=2;j<=len2;j++)
		{
			for(int i=1;i<=len1;i++)
			{
				if(s2[j-1]==s1[i-1])
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
				else
				{
					if(dp[i][j]<dp[i-1][j])
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
	return 0;
}





