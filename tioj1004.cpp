#include<iostream> 
#include<vector>
#define ll long long 
using namespace std;
vector<pair<int, int> > v; 

int f(int r){
	vector<pair<int, int> > temp; 
	if(v.size()== 1)
		return v[0].second;
	else if(v.size()%2== 0){
		for(int i=0; i<v.size(); i+=2)
			temp.push_back(make_pair(v[i].first, v[i].second));
		v.clear();
	}
	else {
		for(int i=2; i<v.size(); i+=2)
			temp.push_back(make_pair(v[i].first, v[i].second));
		v.clear(); 
	}
	for(int i=0; i<temp.size(); i++)
		v.push_back(make_pair(temp[i].first, temp[i].second));

	return f(v.size());
}

void solve(){
	int n; 
	cin>>n; 

	for(int i=1; i<n+1; i++)
		v.push_back(make_pair(i, i));

	if(n== 1) cout<<v[0].second<<endl;

	else cout<<f(n)<<"\n";

}
int main(){
solve(); 
return 0; 
}