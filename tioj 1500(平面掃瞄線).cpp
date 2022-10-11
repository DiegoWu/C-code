#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<iomanip>
#define ll long long 
#define ld long double
using namespace std; 
bool cmp(pair<ld, ld> x, pair<ld, ld> y) {return x.first< y.first;} 
void solve(){
	int n; 
	while(cin>>n){
		vector<pair<ld, ld> > v(n); 
		for(int i=0; i<n; i++){
			ld a, b; 
			cin>>a>>b; 
			v[i]= make_pair(a, b); 
		}
		ld dis= 5000000000000000000; 
		sort(v.begin(), v.end(), cmp); 
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(v[j].first-v[i].first> dis) break; 
				if(sqrt(pow(v[i].first-v[j].first, 2)+pow(v[i].second-v[j].second, 2))< dis)
				
					dis= sqrt(pow(v[i].first-v[j].first, 2)+pow(v[i].second-v[j].second, 2)); 
			}
		}
		cout<<fixed<<setprecision(6)<<dis<<endl;
	}
}

int main(){
	solve(); 
	return 0; 
}
