#include<iostream>
#include<vector>
#include<cmath> 

using namespace std; 

void solve(){
	char a, b, c, d, e, f; 
	cin>>a>>b>>c>>d>>e>>f; 
	string ans; 
	
	if(a==d&&b==e) 
		ans= "Yes"; 
		
	else if(a==d&&b!= e|| (b==e&&a!=d)|| a!=d&&c==f) ans= "No"; 
	else ans= "Yes";
	cout<<ans<<endl;

	
}

int main(){

	solve();

	 return 0; 
}