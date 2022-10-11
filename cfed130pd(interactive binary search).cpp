#include<bits/stdc++.h> 
#define ll long long 
#define maxn 200005
#define mp make_pair 
using namespace std; 

char ask_c(int x){
	cout<<"? 1 "<<x<<endl;
	cout.flush(); 
	string s; 
	cin>>s; 
	return s[0]; 
}

int query(int l, int r){
	cout<<"? 2 "<<l<<" "<<r<<endl;
	cout.flush(); 
	int dif; 
	cin>>dif; 
	return dif; 
}

int main(){
	int n; 
	cin>>n; 
	string ans=""; 
	vector<vector<int> > cnt(n+1, vector<int>(n+1)); 
	for(int i=0; i<n; i++){

		if(i==0){
			ans.push_back(ask_c(i+1)); 
			for(int j=0; j<n+1; j++) cnt[0][j]= 1; 
		}
			
		else{
			int cur= query(1, i+1); 

			if(cur> cnt[i-1][0]){
			 ans.push_back(ask_c(i+1));
			}

			else{
				map<char, int> m; 
				for(int j=0; j<ans.size(); j++) m[ans[j]]= j; 

				vector<int> last;
				for(auto ele: m) last.push_back(ele.second); 
				sort(last.begin(), last.end()); 

				int l= 0, r= last.size(); 

				while(r-l> 1){
                    
					int mid= (l+r)/2; 
					int c= query(last[mid]+1, i+1); 

					if(c== cnt[i-1][last[mid]]) l= mid; 
					else r= mid; 
				}
				ans.push_back(ans[last[l]]);
			}
			set<char> st; 

			for(int j=i; j>=0; j--){
				st.insert(ans[j]); 
				cnt[i][j]= st.size(); 
			}
			
		}

	}
	cout<<"! "<<ans<<endl;
	cout.flush(); 
	return 0; 
}
