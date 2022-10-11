#include<bits/stdc++.h> 
#define ll long long 
#define ld long double 
#define maxn 200005
#define mp make_pair 
using namespace std; 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(NULL); 
	int t; 
	cin>>t; 
	while(t--){
		int n, m, ans= 0; 
		cin>>n>>m; 
		vector<string> arr(n);
		int v[n][m], x[4]= {1, -1, 1, -1}, y[4]= {-1, 1, 1, -1}; 
		for(int i=0; i<n; i++) cin>>arr[i]; 

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				v[i][j]= arr[i][j]-'0'; 
			}
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++) if(arr[i][j]== '1') ans++; 

		int z= 3; 

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				for(int k= 0; k<4; k++){
					if(i+x[k]>=n|| i+x[k]< 0|| j+ y[k]>= m|| j+y[k]< 0) continue; 
					z= min(z, v[i+x[k]][j]+ v[i][j+y[k]]+ v[i][j]); 
				}
			}
		}
		if(z==1|| z==0) cout<<ans<<endl;
		else if(z==2) cout<<ans-1<<endl;
		else cout<<ans-2<<endl;
	}
}
