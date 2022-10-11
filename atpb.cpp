#include<iostream> 
#include<vector>
#include<unordered_map>
#include<cmath> 
#include<algorithm> 

#define ll long long 
using namespace std; 
void solve(){
	int n, a;
	vector<int>v(360);  
	vector<int> prx; 
	cin>>n; 
	cin>>a; 
	prx.push_back(a); 
	for(int i=1; i<n; i++){
		cin>>a; 
		prx.push_back((a+prx[i-1])%360);
	}
	int maxx= 0; 
	sort(prx.begin(), prx.end()); 
	int z= max(prx[0], 360-prx[0]);
	if(n== 1) cout<<z<<endl;
	else{
		for(int i=0; i<n-1; i++){
			if(prx[i+1]- prx[i]> maxx) 
				maxx= prx[i+1]- prx[i]; 
		}
		if(360-prx[n-1]> maxx) maxx= 360-prx[n-1];
		else if(prx[0]> maxx) maxx= prx[0]; 
		cout<<maxx<<endl;
	}	
}
int main(){
	solve(); 
	return 0; 
}