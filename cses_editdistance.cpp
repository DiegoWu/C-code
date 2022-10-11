#include<bits/stdc++.h>

#define ll long long 
#define maxn 1000006
#define mod 1000000007
#define mp make_pair


using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b; 
	cin>>a>>b; 
	a= ' '+a, b= ' '+b; 
	int dp[a.size()+1][b.size()+1]; 
	//memset(dp, 0, sizeof(dp));

	for(int i=0; i<=a.size(); i++)
		dp[i][0]= i; 
	for(int i=0; i<=b.size(); i++)
		dp[0][i]= i; 

	for(int i=1; i<=a.size(); i++){
		for(int j=1; j<=b.size(); j++){
			if(a[i]== b[j]) dp[i][j]= dp[i-1][j-1]; 
			else dp[i][j]= min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1; 

		}
	}
	cout<<dp[a.size()][b.size()]<<endl;
	
}
