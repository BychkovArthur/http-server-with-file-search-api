#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, sm1 = 0, sm2 = 0;
	cin >> n;
	string s1, s2, alph = "qwertyuioplkjhgfdsazxcvbnm";
	sort(alph.begin(), alph.end());
//	cout << alph.size();

	for (int i = 0; i< n; ++i){
		cin >> s1 >> s2;
	}
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++){
		sm1 += (alph.find(s1[i])) + 1;
	}
	for (int i = 0; i < s2.size(); i++){
		sm2 += (alph.find(s2[i]) ) + 1;
	}
	cout << sm2 - sm1;
}