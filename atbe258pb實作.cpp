#include<bits/stdc++.h>

#define ll long long 
#define maxn  9223372036854775807
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; 
	cin>>n;
	vector<string> arr(n); 
	 
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int dx[8]= {0, 0, 1, -1, 1, 1, -1, -1}, dy[8]= {1, -1, 0, 0, 1, -1, -1, 1}; 
	ll c= 0; 
	for(int i=0; i<n; i++){	
		for(int j=0; j<n; j++){
			 
			for(int k=0; k<8; k++){
				string s= ""; 
				s+= arr[i][j]; 
				int x= i, y= j; 
				for(int z=0; z<n-1; z++){
					x= (x+dx[k])%n; 
					y= (y+dy[k])%n; 
					if(x<0) x+= n; 
					if(y<0) y+= n; 
					s+= arr[x][y]; 
				}
				//cout<<s<<endl;
				c= max(stoll(s), c); 
			}
		}
	} 
	cout<<c<<endl;
}
