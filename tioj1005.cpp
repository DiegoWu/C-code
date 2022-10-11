#include<iostream>
#include<vector>
#include<set> 
#include<cmath> 
#include<iomanip>
#include<algorithm> 
using namespace std;
vector<int> v; 
int gcd(int a, int b){
	if(a== 0)
	 	return b; 
	else if (a== 1)
		return 1;
	b= b%a;
	return gcd(b, a); 
}
void solve(){
	int n, a;
	while(cin>>n&& n!= 0){
		double count= 0; 
		v.clear(); 
		for(int i=0; i<n; i++){
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(), v.end()); 
		double base= n*(n-1)/2;
		for(int it= 0; it< v.size(); it++)
			for(int  itt= it+1; itt< v.size(); itt++)
				if(gcd(v[it], v[itt])== 1) count++; 
		//cout<<count<<endl;
		if(count== 0)
			cout<<"No estimate for this data set."<<endl;
		else{
			double ans;
			ans= sqrt(6.0*base/count); 
			cout<<setiosflags(ios::fixed)<<setprecision(6)<<ans<<endl; 
		}
	}
}
int main(){
	solve();
	return 0;
}