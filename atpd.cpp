#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long 

using namespace std; 

void solve(){
	int n; 
	cin>>n; 
	ll x; 
	cin>>x; 
	string operate; 
	string need=""; 
	cin>>operate; 
	 
	int rl= 0; 
	for(int i=0; i<n; i++){
		int temp; 
		if(operate[i]=='L'|| operate[i]== 'R'){
			rl++; 
			need.push_back(operate[i]);
			
		}
		else if(operate[i]=='U'){
	
			
			if(need!= ""&&rl> 0) {
				need.pop_back(); 
				rl--; 
			}
			else need.push_back(operate[i]);
		}
	
	}
	
	for(int i=0; i<need.size(); i++){
		if(need[i]=='L') {
			x= x*2; 
		}
		else if(need[i]=='R') x= x*2+1; 
		else x= x/2; 
	}
	
	cout<<x<<endl;

}

int main(){
	solve(); 
	return 0; 
}