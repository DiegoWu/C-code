#include<iostream>
#include<vector> 
#include<algorithm>

using namespace std; 

int main(){

	int n, m, var; 
	cin>>n>>m; 
	vector<int> v(n+1); 
	vector<int> v1(n+m+1); 
	vector<int> remain; 
	vector<int> ans; 
	for(int i=0; i<n+1; i++){
		cin>>v[i]; 
	}
	for(int i=0; i<n+m+1; i++)
		cin>>v1[i]; 
	reverse(v1.begin(), v1.end()); 
	reverse(v.begin(), v.end()); 
	
	for(int i=0; i<=n; i++) remain.push_back(v1[i]); 
	
	for(int i=0; i<=m; i++){
		var= remain[0]/v[0];
		ans.push_back(var);  
		int c= 1; 
		for(int j=0; j<n; j++){
			remain[j]= remain[j+1]-v[j+1]*var;
			c++; 
		}
		remain[n]= v1[i+c]; 
	}
	reverse(ans.begin(), ans.end()); 
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<" "; 
	cout<<endl;
}