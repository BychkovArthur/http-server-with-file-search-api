#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s, lg, ps;

	
	map<string, pair<string, int>> mp;
	
	while (cin >> s){

		if (s == "register"){
			cin >> lg >> ps;
			if (mp.count(lg) == 1){
				cout << "login already in use" << "\n";
			}else{
				mp[lg] = {ps, 0};
				cout << "account created" << "\n";
			}
		}
		
		
		if (s == "login"){
			cin >> lg >> ps;
			if (mp.count(lg) == 1 and mp[lg].first == ps and mp[lg].second == 0){
				cout << "logged in" << "\n";
				mp[lg] = {ps, 1};
			}else{
				if (mp.count(lg) == 1 and mp[lg].first == ps and mp[lg].second == 1){
				cout << "already logged in" << "\n";
				
			}else{
				cout << "wrong account info" << "\n";
			}
			}
			
			
		}
		
		if (s == "logout"){
			cin >> lg;
			if (mp.count(lg) == 1 and mp[lg].second == 1){
				cout << "logged out" << "\n";
				mp[lg].second = 0;
			}
			else{
				cout << "incorrect operation" << "\n";
			}
		}
	}
}