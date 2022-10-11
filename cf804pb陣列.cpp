#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n, m;
		cin>>n>>m; 
		int arr[n][m]; 
		arr[0][0]= 1; 

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(i==0&& j==0) continue; 
				else if(j==0){
					if((i+1)%2==0) arr[i][j]= (arr[i-1][j]+1)%2; 
					else arr[i][j]= arr[i-1][j];
				}
				else {
					if((j+1)%2==0) arr[i][j]= (arr[i][j-1]+1)%2; 
					else  arr[i][j]= arr[i][j-1]; 
				}
			}
		} 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout<<arr[i][j]<<" "; 
			} 
			cout<<endl;
		}	
	}
}
