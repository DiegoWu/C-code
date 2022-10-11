#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
bool  cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first== b.first) return a.second> b.second; 
	return a.first< b.first;
}; 
bool cc(pair<int, int> a, pair<int, int> b){
	return a.second< b.second; 
}

void solve(){

	int t;
	cin>>t; 
	while(t--){
		int m;
		cin>>m; 
		vector<pair<int, int> > v; 
		vector<pair<int, int> > temp; 
		for(int i=0; i<m; i++){
			int a, b; 
			cin>>a>>b; 
			v.push_back(make_pair(a, b)); 
		}
		sort(v.begin(), v.end(), cmp); 
        temp.push_back(make_pair(v[0].first, v[0].second));
		for(int i=1; i<m; i++){

			if(v[i].second> temp[temp.size()-1].second)
				temp.push_back(make_pair(v[i].first, v[i].second)); 
			
			else if(v[i].second< temp[temp.size()-1].second) {
                int z= lower_bound(temp.begin(), temp.end(), v[i], cc)-temp.begin();
				temp[z]= make_pair(v[i].first, v[i].second); 
			} 
		}
		cout<<temp.size()<<endl;
	}
}

int main(){
	solve();
	return 0;
}
