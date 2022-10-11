#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	 
	int n, s; 
	cin>>n>>s; 
	int v[2][n]; 
	for(int i=0; i<n; i++) cin>>v[0][i]>>v[1][i]; 
	int dp[102][10005]; 
	vector<vector<string> > rec(102, vector<string>(10005)); 
	dp[0][v[0][0]]= 1, rec[0][v[0][0]]= "H", rec[0][v[1][0]]= "T",  dp[0][v[1][0]]= 1; 
	for(int i=1; i<n; i++){
		for(int j=0; j<=s; j++){
			for(int k=0; k<2; k++){
				if(j<v[k][i]) continue; 
				if(dp[i-1][j-v[k][i]]!= 0){
				 dp[i][j]=dp[i-1][j-v[k][i]]+1 , rec[i][j]= rec[i-1][j-v[k][i]]; 
				 if(k==0) rec[i][j]+= "H"; 
				 else rec[i][j]+= "T"; 
				}
			}
		}
	}

	if(dp[n-1][s]== n) {
		cout<<"Yes"<<endl; 
		cout<<rec[n-1][s]<<endl;
	}
	else cout<<"No"<<endl;
}
