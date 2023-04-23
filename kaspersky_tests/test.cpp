#include <bits./stdc++.h>
 
using namespace std;
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c;
	string s, s1;
	cin >> s;
	
	vector <long long> a(1000);
	
	for (long long i = 0; i < 1000; ++i){
		a[i] = 97 * i;
	}
	
	for (auto i : a){
		s1 = to_string(i);
		c = s.size() - s1.size();
		if (s.substr(c,s1.size()) == s){
			cout << "YES";
			return 0;
		}
	}
	cout <<  "NO";
}