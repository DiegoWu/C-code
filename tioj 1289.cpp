#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<string> 
#include<set> 
#define ll long long 
using namespace std; 

int main(){
	int n; 
	while(cin>>n){
		map<string, bool> v; 	
		vector<long> rec; 
		int ans= 0; 
		string s; 
		
		for(int i=0; i<n; i++){

			long a; 
			cin>>a; 
			rec.push_back(a); 
			s= to_string(a); 
			v[s]= 1; 
		}
		for(int i=0; i<rec.size(); i++){
			for(int j=i; j<rec.size(); j++){
				if(rec[j]== 0) continue; 
				s= to_string((ll)sqrt(rec[i]*rec[i]+rec[j]*rec[j]));
				if(sqrt(rec[i]*rec[i]+rec[j]*rec[j])== (ll)sqrt(rec[i]*rec[i]+rec[j]*rec[j])&& v[s]) ans++; 
			}
		}
		cout<<ans<<endl; 
	}
}