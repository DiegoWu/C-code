#include<iostream>
#include<vector> 
#include<algorithm>
#define INF 250001
using namespace std;

int main(){
	int n, m; 
	while(cin>>n>>m&&n&&m){
		vector<vector<int> > arr(n+1, vector<int>(n+1));
		for(int i=0; i<n+1; i++)
			for(int j=0; j<n+1; j++) 
				arr[i][j]= INF; 
			
		for(int i=0; i<m; i++){
			int a, b; 
			cin>>a>>b; 
			arr[a][b]= 1; 
		}
		for(int k=1; k<n+1; k++){
			for(int i=1; i<n+1; i++){
				for(int j=1; j<n+1; j++){
					if(arr[i][j]>arr[i][k]+arr[k][j]) {
						arr[i][j]= arr[i][k]+arr[k][j]; 
						//cout<<i<<" "<<j<<" "<<k<<" val: "<<arr[i][j]<<endl;
					}
				}
			}
		}
		vector<int> rec(n+1); 
		for(int i=0; i<n+1; i++) rec[i]= arr[i][i]; 
		sort(rec.begin(), rec.end()); 
		if(rec[0]== INF) cout<<0<<endl;
		else cout<<rec[0]<<endl; 
	}
	return 0; 
}
