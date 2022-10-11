#include<iostream>
#include<vector>
#include<algorithm> 
#include<cmath>  
#define ll long long 
#define maxn 4005
#define mp make_pair 
using namespace std; 

template<typename T>

pair<T, T>  operator-(pair<T, T>  a, pair<T, T> b){
	return mp(a.first-b.first, a.second-b.second); 
}
template<typename T> 

T cross(pair<T, T> a, pair<T, T> b){
	return a.first*b.second-a.second*b.first; 
}

vector<pair<ll, ll> > v; 

template<typename T> 

vector<pair<T, T> > getConvexHull(vector<pair<T, T> > &v){
	vector<pair<T, T> >hull; 

	sort(v.begin(), v.end()); 

	for(int i=0; i<2; i++){
		int t= hull.size(); v
		for(pair<T, T>  pnt: v){
			while(hull.size()-t>= 2&& cross(hull.back()- hull[hull.size()-2], pnt- hull[hull.size()-2])<= 0)
				hull.pop_back(); 
			hull.push_back(pnt); 
		}
		hull.pop_back(); 
		reverse(v.begin(), v.end()); 
	}

	return hull; 
} 

int main(){
	int n; 
	cin>>n; 

	while(n--){
		ll a, b; 
		cin>>a>>b; 
		v.push_back(mp(a, b)); 
	}

	cout<<getConvexHull(v).size()<<endl;;
}
