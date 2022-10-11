#include<bits/stdc++.h>

#define ll long long 
#define maxn 200005
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int n; 
		cin>>n; 
		vector<int> v(n);
		for(int i=0; i<n; i++)  cin>>v[i]; 
		vector<string> z(n); 
		for(int i=0; i<n; i++){
			int k;
			cin>>k; 
			
			string s; 
			cin>>s; 
			z[i]= s; 
			
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<z[i].size(); j++){
				if(z[i][j]== 'U'){
					if(v[i]== 0) v[i]= 9; 
					else v[i]-= 1; 
				}
				else{
					if(v[i]== 9) v[i]= 0; 
					else v[i]+= 1;
				}
			}
		}
		for(int i=0; i<n; i++) cout<<v[i]<<" ";
		cout<<endl;
	}
}
