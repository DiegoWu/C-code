#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long 
#define maxn 300005
#define mp make_pair

using namespace std; 
int main(){
    
	int n, m, sz; 
	cin>>n>>m; 
	vector<int> v[10];
	vector<int> op(m);
	sz= pow(2, n); 
	vector<string> combination(sz); 
	for(int i=0; i<m; i++){
		int t; 
		cin>>t; 
		for(int j=0; j<t; j++){
			int a; 
			cin>>a; 
			v[i].push_back(a); 
		}
	}
	for(int i=0; i<m; i++) cin>>op[i]; 

	int t= 1; string a="1", b= "0";  
    // 可改成位元表示法 e.g. (1<<n)
	for(int i=0; i<n; i++){
		if(i!=0)	for(int j=t; j<t*2; j++) combination[j]= combination[j-t]; 
		for(int j=0; j<t; j++)
			combination[j]+= a;
	
		for(int j=t; j<t*2; j++)
			combination[j]+= b; 
		t*= 2; 
	}
    
	ll ans= 0; 
	for(int i=0; i<sz; i++){
		int  pvt= 0; 
		for(int j=0; j<m; j++){
			int cnt= 0; 
			for(auto k: v[j]){
				if(combination[i][k-1]== '1') cnt++; 
			}
			if(cnt%2== op[j]) pvt++; 
		}
		if(pvt== m) ans++; 
	}
	cout<<ans<<endl;
}
