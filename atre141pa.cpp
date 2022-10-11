#include<iostream> 
#include<vector>
#include<algorithm> 
#include<string> 
#include<cmath> 
#define ll long long 
using namespace std; 

int main(){

	int t; 
	cin>>t; 
	while(t--){
		ll n, cnt= 0; 
		cin>>n; 
		string s= to_string(n); 
		vector<string> ans; 
		vector<ll> use; 
		vector<ll> num; 
		for(int i= s.size(); i>0; i--) if(s[i]=='0') cnt++;

		if(s[0]== '1'&&cnt== s.size()-1)
			cout<<n-1<<endl;
		
		else{
			int mx= 0, cc= 0; 
			for(int i=1; i<=s.size()/2; i++) if(s.size()%i==0) use.push_back(i); 
			for(int i=0; i<s.size()-1; i++) {
				if(s[i]=='1'&& s[i+1]== '0'){
					cc= 1; 
					break; 
				}
			}
			string ann= ""; 
			if(use.size()==1&&s[0]=='1'&& cc){
				for(int i=0; i<s.size()-1; i++) ann+= '9';
				
			} 
		
			for(int i=0; i<use.size(); i++){
    
				string temp= "";
				int ck= 0, ckk= 0, p= 1;
				for(int j=0; j<use[i]; j++) {
					temp+= s[j]; 
				}
			
				while(p< s.size()/use[i]){
					if(ck||ckk) break; 
					for(int k=0; k<use[i]; k++){
						if(s[k]< s[k+p*use[i]]){
							ckk= 1; 
							break; 
						}
						if(s[k]> s[k+p*use[i]]){
							ck= 1; 
						
							break; 
						}
					}
					p++; 
				}
				if(ck){
					ll x= stoll(temp);  
					x-= 1; 
					if(use[i]==1&& s[1]== '0'&& s[0]== '1') x= 9; 
			
					temp= to_string(x); 
				}
				string an= ""; 
				if(use[i]==1&& s[1]== '0'&& s[0]== '1') for(int j=0; j<s.size()/use[i]-1; j++) an+= temp;
				else for(int j=0; j<s.size()/use[i]; j++) an+= temp;
				ans.push_back(an); 
			}

		for(int i=0; i<ans.size(); i++) num.push_back(stoll(ans[i])); 
		if(ann!= "") num.push_back(stoll(ann)); 
		sort(num.begin(), num.end()); 

		cout<<num[num.size()-1]<<endl;
		}

	}
}
