#include<bits/stdc++.h>

#define ll long long 
#define maxn 92233720368547
#define mod 1000000007
#define mp make_pair

using namespace std; 

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin>>s>>t; 
	if(t.size()< s.size()) cout<<"No"<<endl;
	else {
		string ans= "Yes"; 

		vector<pair<char, int> > news, newt; 
		
		news.push_back(mp(s[0], 1)); 
		newt.push_back(mp(t[0], 1)); 
		
		for(int i=1; i<s.size(); i++){
			if(s[i-1]==s[i]) news[news.size()-1].second++;  
			else news.push_back(mp(s[i], 1)); 
		}
		for(int i=1; i<t.size(); i++){
			if(t[i-1]==t[i]) newt[newt.size()-1].second++;  
			else newt.push_back(mp(t[i], 1)); 
		}
		if(news.size()!= newt.size()) ans= "No"; 
		else{
			for(int i=0; i<news.size(); i++){
				//cout<<i<<endl;
				if(i>=t.size()) {
					ans= "No";
					//cout<<"asdf"<<endl;
					break; 
				}
				if(news[i].first== newt[i].first){
					if(news[i].second< newt[i].second&& news[i].second== 1){
						ans= "No"; 
						break; 
					}
					else if(news[i].second> newt[i].second){
						ans= "No"; 
						break; 
					}
				}
				else{
					ans= "No";
					break; 
				}
			}
		}
		cout<<ans<<endl;
	}
}

