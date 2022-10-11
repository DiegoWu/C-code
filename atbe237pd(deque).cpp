#include<iostream>
#include<vector>
#include<deque> 
#include<map> 
#define mp make_pair 
#define ll long long
#define INF 1000000001
#define mod 998244353
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
   	string s;
    cin>>n>>s; 
    deque<int> dq; 
    dq.push_back(n); 
     
    for(int i=n-1; i>=0; i--){
    	if(s[i]== 'L') dq.push_back(i);
    	else dq.push_front(i); 
    }
    for(auto i= dq.begin(); i!= dq.end(); i++)
    	cout<<*i<<" "; 
    cout<<endl;
}
