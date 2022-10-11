#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int dp[2][1005 + 1];
	for (int i = 0; i < b.size() + 1;i++) {
		dp[0][i] = i;
		dp[1][i] = i;
	}
	//cout<<" "; 
	//for(int i=0; i<b.size(); i++) cout<<b[i]; 
	//cout<<endl;

	for (int i = 1; i <= a.size();i++) {
		dp[1][0] = dp[0][0] + 1;
		//cout<<a[i-1]; 
		for (int j =1; j <= b.size();j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[1][j] = dp[0][j - 1];
			} 
			else {
				dp[1][j] = min(min(dp[0][j], dp[1][j - 1]), dp[0][j - 1]) + 1;
			}
			//cout<<dp[1][j]; 
		}
		//cout<<endl;
		for (int j = 0; j < b.size() + 1; j++) dp[0][j] = dp[1][j];
	}
	cout << dp[1][b.size()] << endl;
}