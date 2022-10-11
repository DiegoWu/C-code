#include<iostream>
#include<vector>
#include<algorithm> 

using namespace std; 

void solve(){

	int n, m; 
	cin>>m>>n; 
	vector<vector<int> > v(m+1, vector<int>(n+1)); 
	vector<vector<int> > dp(m+1, vector<int>(n+1)); 
	vector<vector<int> > ans(m+1, vector<int>(n+1)); 
	for(int i=1; i<=m; i++) 
		for(int j=1; j<=n; j++)
			cin>>v[i][j]; 

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){

			if(v[i][j]){
				dp[i][j]= dp[i-1][j]+v[i][j]; 
				int temp= dp[i][j], c= 1; 
				ans[i][j]= dp[i][j];
				for(int z= j-1; z>= 0; z--){
					if(!dp[i][z]){
						c= 1; 
						break; 
					}
					c++; 
					if(dp[i][z]< temp) temp= dp[i][z]; 
					if(temp*c>ans[i][j]) ans[i][j]= temp*c; 
				}
			}
		}
	}
	int nn= 0; 
	
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			if(ans[i][j]>nn) nn= ans[i][j]; 
	cout<<nn<<endl;
}
int main(){
	solve(); 
	return 0; 
}