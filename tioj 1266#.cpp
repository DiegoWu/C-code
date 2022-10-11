#include<iostream> 
#include<vector> 
#include<algorithm>
#include<cmath> 
#include<queue> 

using namespace std;

void solve(){
	int n; 
	int arr[1002][1002];  
	int zzz[2][500][500]; 
	 
	vector<int> lis[2]; 
	vector<int> lis1[1002]; 
	
	cin>>n; 
	
	memset(arr, 0, 1002*1002*sizeof(int)); 

	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++)
			cin>>arr[i][j]; 

	lis[0].push_back(arr[1][1]);
	lis1[0].push_back(arr[1][1]); 
	int ans= 0; 
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			for(int z=0; z<lis[j-1].size(); z++)
				lis[j].push_back(lis[j-1][z]); 

			for(int z=0; z<lis1[i-1].size(); z++)
				lis1[i].push_back(lis1[i-1][z]); 
			if(arr[i][j]> lis[j-1][lis[j].size()-1]) lis[j-1].push_back(arr[i][j]); 
			else{
				int x= lower_bound(lis[j].begin(), lis[j].end(), arr[i][j])- lis[j].begin(); 
				lis[j][x]= arr[i][j]; 
			}
			if(arr[i][j]> lis1[i-1][lis1[i].size()-1]) lis1[i-1].push_back(arr[i][j]); 
			else{
				int x= lower_bound(lis1[i].begin(), lis1[i].end(), arr[i][j])- lis1[i].begin(); 
				lis1[i][x]= arr[i][j]; 
			}
			//ans= max(ans, lis1[i].size())
		}
	}
	int op= 0;
	
	
}

int main(){

	solve(); 
	return 0; 
}