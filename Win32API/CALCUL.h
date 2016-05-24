#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility> 

namespace calcul {
	using namespace std;
	typedef long long ll;
	typedef vector <ll> vi;
	void dfsd(string &st, int &i);  //umnozhenie
	void dfss(string &st, int &i); //clozhenie
	void dfsss(string &st, int &i); //skobki
	void longop(vi &st1, vi st2, char ch);

	bool non(string &st, char ch);

	bool non(string &st, int left, int right);

	int status(string st);
	void set(string a);
	void dfs(vector<ll>q, ll &sum1);

	string delet(string st);
	void setString(char TEXT[], string &a);
	bool DO_IT_NOW_CALCULE_PLS_NO_BUGS(string &a,bool &vva);


}