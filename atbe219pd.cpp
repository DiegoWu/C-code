#include<bits/stdc++.h> 
#define ll long long 
#define maxn 92233720368
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int n, x, y; 
	cin>>n>>x>>y; 
	int a[n], b[n];
	for(int i=0; i<n; i++) cin>>a[i], cin>>b[i];
	vector<vector<int> > dp(x+1, vector<int>(y+1, 1000)); 
	dp[0][0]= 0; 
	for(int i=0; i<n; i++){
		for(int j=x; j>=0; j--){ // in case rebuy the item
			for(int z= y; z>=0; z--){
				int g= min(j+a[i], x), g1= min(z+b[i], y); 
				dp[g][g1]= min(dp[g][g1], dp[j][z]+1); 
			}
		}
	} 
	int ans= dp[x][y]; 
	cout<<(ans== 1000? -1:ans)<<endl;

	
}
