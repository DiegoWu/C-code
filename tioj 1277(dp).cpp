#include<iostream>
#include<vector> 
#include<cmath> 
#include<algorithm>
#define ll long long 
using namespace std ;


int main(){

	int n;
	ll com= 0, ans= 0; 
	cin>>n; 
	ll rec[2][n+1][n+1]; 
	for(int i=0; i<2; i++)
		for(int j=0; j<n+1; j++)
			for(int z=0; z<n+1; z++) rec[i][j][z]= 0; 
	vector<vector<ll> > v(n+1, vector<ll>(n+1)); 
	
	vector<ll> temp(n+2);

	for(int i=1; i<n+1; i++)
		for(int j=1; j<n+1; j++) cin>>v[i][j]; 

	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			for(int z=j; z>0; z--){

				temp[z]+= temp[z+1]+v[i][z]; 
				
				rec[i%2][j][z]= temp[z]+rec[(i+1)%2][j][z];
				 
 				if(rec[i%2][j][z]<temp[z]) rec[i%2][j][z]= temp[z];
				
				com= max(com, rec[i%2][j][z]); 

			}
			
			for(int z=j+1; z> 0; z--) temp[z]= 0; 

			ans= max(ans, com); 
			com= 0; 
		}
	}

	cout<<ans<<endl;
}