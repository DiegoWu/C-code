#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n, a; 
	cin>>n>>a; 
	vector<int>v(n+5); 
	vector<int>z(n+5); 
	for(int i=0; i<n; i++){
		v[i+1]= i+1; 
		z[i+1]= i+1; 
	}
	for(int i=0; i<a; i++){
		int q; 
		cin>>q;
		if(z[q]==n){
			int pos= v[z[q]], pos1= v[z[q]-1];
			swap(v[z[q]], v[z[q]-1]); 
			swap(z[pos], z[pos1]); 
		}
		else{
			int pos= v[z[q]], pos1= v[z[q]+1];
			swap(v[z[q]], v[z[q]+1]);  
			swap(z[pos], z[pos1]); 
		}
	}
	for(int j=1; j<n+1; j++)
			cout<<v[j]<<" "; 
		cout<<endl;

}