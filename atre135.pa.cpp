#include<iostream>
#include<vector>
#include<string> 
#include<algorithm> 
#include<queue> 
#include<cmath> 
#define ll long long
#define mod 998244353 
#define INF 400005
using namespace std; 
ll cnt= 1, ans= 1, odd= 0, g= 1, ff= 0; 
ll f(ll x){
	ll z= x, zz= x;  
	while(true){
		ll temp= z, temp1= zz; 
		cnt*= 2;
		if(z==zz&&z%2== 0){
		 z/= 2, zz= z; 
		}
		else{
			ff= 1; 
			if(ff&&g){
				odd= cnt/2; 
				g= 0;
			}
			z/= 2;
			if(temp> temp1) zz/= 2;
			else zz= zz/2+1;  
		}
		//cout<<z<<" "<<zz<<" "<<odd<<endl;
		if(z%2) {
			odd= cnt-odd; 
			swap(z, zz); 
		} 
		if((z==2&&zz==3)|| (z==zz&&zz==2)||(z==3&&zz==3)||(z==4&&zz==3)) {
			ll o= odd, aa= zz, oo= (cnt-odd);  

			while(o){
				if(o& 1) ans= (ans%mod)*(aa%mod); 
				ans%= mod; 
				aa=(aa%mod)*(aa%mod); 
				o>>= 1; 
			}
			aa= z; 
			while(oo){
				if(oo& 1) ans= (ans%mod)*(aa%mod); 
				ans%= mod; 
				aa= (aa%mod)*(aa%mod); 
				oo>>= 1; 
			} 
			break; 
		}
	}

	 return ans; 
}
int main(){

	ll x; 
	cin>>x; 
	
	if(x== 3||x== 4||x==2||x==1) cout<<x<<endl;
	
	else{
		cout<<f(x)<<endl;
	}
}
