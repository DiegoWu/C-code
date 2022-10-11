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

		vector<string> v(n); 
		map<string, bool> m; 
		for(int i=0; i<n; i++){
			string s; 
			cin>>s; 
			v[i]= s; 
			m[s]= 1; 
		}
		string ans= ""; 
		for(int i=0; i<n; i++){
			char z= '0'; 
			for(int j=1; j<v[i].size(); j++){
				string temp= "", temp1= ""; 
				for(int k=0; k<j; k++) temp+= v[i][k]; 
				
				for(int k=j; k<v[i].size(); k++) temp1+= v[i][k]; 

				if(m[temp1]&& m[temp]) z= '1'; 
				 
			//	cout<<temp<<" "<<temp1<<endl;
			}
			ans+= z; 
		}
		cout<<ans<<endl;
	}
}
