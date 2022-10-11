#include<bits/stdc++.h>
 
#define ll long long 
#define maxn 1000006
#define mod 1000000007
#define mp make_pair
 
using namespace std;
 
int main(){
 
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	int n, x; 
	cin>>n>>x; 
	int dp[x+1][n]; 
	vector<pair<int, int> > v(n); 
	map<int, int> m; 
	set<int> st; 
	memset(dp, 0, sizeof(dp)); 
	for(int i=0; i<n; i++) cin>>v[i].first; 
	for(int i=0; i<n; i++) cin>>v[i].second;  
	sort(v.begin(), v.end()); 
 
	for(int i=1; i<=x; i++){
		for(int j=0; j<n; j++){
			if(i-v[j].first< 0) continue; 
			if(j==0) dp[i][j]= v[j].second; 
			else dp[i][j]= max(dp[i][j-1], dp[i-v[j].first][j-1]+ v[j].second); 
		}
	}

	cout<<dp[x][n-1]<<endl;
 
}