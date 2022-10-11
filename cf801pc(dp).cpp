#include<bits/stdc++.h> 
#define ll long long 
#define maxn 10000000000
#define mp make_pair 
using namespace std; 

int main(){

	int t; 
	cin>>t; 
	while(t--){
		int n, m; 
		cin>>n>>m; 
		int arr[n][m], mx[n][m], mn[n][m];  
		memset(mx, 0, sizeof(mx)), memset(mn, 0, sizeof(mn)); 
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin>>arr[i][j]; 
		if((n+m-2)%2==0) cout<<"NO"<<endl;
		else{
		
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(i==0&&j==0) {
						mx[i][j]= arr[i][j];
						mn[i][j]= arr[i][j];
					}
					else if(i==0){
						mx[i][j]= mx[i][j-1]+arr[i][j]; 
						mn[i][j]= mn[i][j-1]+arr[i][j]; 
					}
					else if(j==0){
						mx[i][j]= mx[i-1][j]+arr[i][j]; 
						mn[i][j]= mn[i-1][j]+arr[i][j]; 
					}
					else{
						mx[i][j]= max(mx[i-1][j], mx[i][j-1])+arr[i][j]; 
						mn[i][j]= min(mn[i-1][j], mn[i][j-1])+arr[i][j]; 
					}
				}
			}
			//cout<<mx[n-1][m-1]<<" "<<mn[n][m]<<endl;
			if(mx[n-1][m-1]<0|| mn[n-1][m-1]> 0) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
			
		}
		
	}
}