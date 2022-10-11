 #include<iostream>
#include<vector>
#include<cmath> 
#include<string> 
#include<algorithm> 
#include<map>
#include<set> 
#define ll long long 
#define INF 1000000001
#define mod 998244353
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, cnt= 0;
        cin>>n;
        vector<int> v(n);
        vector<int> an;
        for(int i=0; i<n; i++) cin>>v[i];
        if(n%2) cout<<"NO"<<endl;
        else{
            string ans= "YES";
            sort(v.begin(), v.end());
            for(int i=0; i<n/2; i++){

                an.push_back(v[i]);
                an.push_back(v[i+n/2]);
            }
            for(int i=1; i<n; i+= 2){
                if(i== n-1){
                    if( an[i]<= an[i-1]){
                        ans= "NO";
                        break;
                    }
                }
                else if(an[i]<= an[i-1]|| an[i+1]>= an[i]){
                    ans= "NO";
                    break;
                }
            }
            if(ans=="NO") cout<<ans<<endl;
            else{
                cout<<ans<<endl;
                for(int i=0; i<n; i++) cout<<an[i]<<" ";
                cout<<endl;
            }
        }
    }
}
