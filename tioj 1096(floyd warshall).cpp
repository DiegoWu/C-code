#include<iostream>
#include<vector> 
#include<algorithm>
#define INF 10000001
using namespace std; 

void solve(){

	int n;
	while(cin>>n&&n){
		int arr[n][n];
		vector<int> rec(n); 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>arr[i][j]; 
				if(arr[i][j]== 0) arr[i][j]= INF; 
				if(i==j) arr[i][j]= INF; 
			}
		}
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(arr[i][j]> arr[i][k]+arr[k][j]) arr[i][j]= arr[i][k]+arr[k][j];
				}
			}
		}
		for(int i=0; i<n; i++) rec[i]= arr[i][i]; 
		sort(rec.begin(), rec.end()); 	
		if(rec[0]== INF) cout<<-1<<endl; 
		else cout<<rec[0]<<endl;
	}	

}

int main(){
	solve(); 
	return 0; 
}
