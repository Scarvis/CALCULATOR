#include "CALCUL.h"
namespace calcul {
	string str; //stroka
	vi buf;  //bufer
	bool val;
	bool otr;
	void dfsd(string &st, int &i);  //umnozhenie
	void dfss(string &st, int &i); //clozhenie
	void dfsss(string &st, int &i); //skobki
	void longop(vi &st1, vi st2, char ch);

	bool non(string &st, char ch)
	{
		for (int i = 0; i < st.size(); i++)
		{
			if (st[i] == ch || st[i] == ch)
			{
				return false;
			}
		}
		return true;
	}

	bool non(string &st, int left, int right)
	{
		if (!non(st, '*'))
			return false;
		else
			return true;
	}

	int status(string st)
	{
		int buf = 0;
		for (int i = 0; i < st.size(); i++)
		{
			if (st[i] == '(')
			{
				return 2;
			}
			if (st[i] == '*' || st[i] == '/')
				return 1;
		}
		return 0;
	}

	void dfs(vector<ll>q, ll &sum1)
	{
		int n = 1;
		for (int i = q.size() - 1; i >= 0; i--)
		{
			sum1 += q[i] * n;
			n *= 10;
		}
	}

	string delet(string st)  //probel delet
	{
		string nt;
		for (int i = 0; i < st.size(); i++)
			if (st[i] != ' ')
				nt += st[i];
		return nt;
	}
	void set(string a)
	{
		str = a;
	}
	void setString(char TEXT[], string &a)
	{
		int i = 0;
		while (TEXT[i] != '\0')
		{
			a += TEXT[i];
		}
	}
	bool DO_IT_NOW_CALCULE_PLS_NO_BUGS(string &a, bool &vva)
	{
		val = false;
		otr = false;
		str = delet(str);
		int i = 0;
		while (!non(str, '(') || !non(str, ')')) {
			dfsss(str, i);
		}
		while (!non(str, '*') || !non(str, '/')) {
			dfsd(str, i);
		}
		while (!non(str, '+') || !non(str, '-')) {
			dfss(str, i);
			if (otr)
				break;
		}
		a.clear();
		a = str;
		if (val)
			vva = true;
		return true;

		for (int i = 0; i < str.size(); i++)
			buf.push_back(str[i] - '0');
		//		cout << "OUTPUT = ";
		//	for (int i = 0; i < buf.size(); i++)
		//		cout << buf[i];
		//	cout << endl;

	}
	


	void dfsd(string &st, int &i)
	{
		int k = 0, left = 0, right = 0;
		ll sum1 = 0, sum2 = 0;
		while (st[i] != '*' && st[i] != '/' && i != str.size())
		{
			if (st[i] != '+' && st[i] != '-' && i != st.size() && st[i] != 'N')
			{
				buf.push_back(st[i] - '0');
				i++;
			}
			else
			{
				buf.clear();
				i++;
			}
		}
		right = i;
		left = right - buf.size();
		dfs(buf, sum1);
		char ch = st[i++];
		buf.clear();
		while (st[i] != '*' && st[i] != '/' && i != st.size() && st[i] != '+' && st[i] != '-')
		{
			if (st[i] != '+' && st[i] != '-' && i != st.size() && st[i] != 'N')
			{
				buf.push_back(st[i] - '0');
				i++;
			}
			else
			{
				buf.clear();
				i++;
			}
		}
		right = i;
		st.erase(st.begin() + left, st.begin() + right);
		ll sum3 = 0;
		dfs(buf, sum2);
		buf.clear();
		if (sum2 == 0)
		{
			val = true;
			return;
		}
		switch (ch)
		{
		case '*': dfs(buf, sum2); sum3 = sum1*sum2;	break;
		case '/': dfs(buf, sum2); sum3 = sum1 / sum2;	break;
		default:
			break;
		}


		while (sum3 > 0)
		{
			ll bufer = sum3 % 10;
			buf.push_back(bufer);
			sum3 /= 10;
		}
		for (int j = 0; j < buf.size(); j++)
			st.insert(st.begin() + left, buf[j] + '0');
		buf.clear();
		i = 0;
	}


	void dfss(string &st, int &i)
	{
		int k = 0, left = 0, right = 0;
		ll sum1 = 0, sum2 = 0;
		while (st[i] != '+' && st[i] != '-' && i != str.size())
		{
			if (st[i] != '+' && st[i] != '-' && i != st.size() && st[i] != 'N')
			{
				buf.push_back(st[i] - '0');
				i++;
			}
			else
			{
				buf.clear();
				i++;
			}
		}
		
		right = i;
		left = right - buf.size();
		dfs(buf, sum1);
		char ch = st[i];
		i = 0;
		st.erase(left, right + 1);
		vi n1;
		for (auto k = buf.rbegin(); k != buf.rend(); k++)
			n1.push_back((*k));
		buf.clear();
		while (st[i] != '*' && st[i] != '/' && i != st.size() && st[i] != '+' && st[i] != '-')
		{
			if (st[i] != '+' && st[i] != '-' && i != st.size() && st[i] != 'N')
			{
				buf.push_back(st[i] - '0');
				i++;
			}
			else
			{
				buf.clear();
				i++;
			}
		}
		right = i;
		st.erase(left, right);
		ll sum3 = 0;
		dfs(buf, sum2);
		vi n2;
		for (auto k = buf.rbegin(); k != buf.rend(); k++)
			n2.push_back((*k));
		buf.clear();
		
		if (n1.size() > 18 || n2.size() > 18) {
			longop(n1, n2, ch);
			buf = n1;
		}
		else {
			switch (ch)
			{
			case '+': dfs(buf, sum2); sum3 = sum1 + sum2;	break;
			case '-': dfs(buf, sum2); if (sum1 == 0) {
				otr = true; return;
			}
					  sum3 = sum1 - sum2;	break;
			default:
				break;
			}
			
			if (sum3 < 0)
			{
				otr = true;
				sum3 = abs(sum3);
			}
			while (sum3 > 0)
			{
				ll bufer = sum3 % 10;
				buf.push_back(bufer);
				sum3 /= 10;
			}
		}
		for (int j = 0; j < buf.size(); j++)
			st.insert(st.begin() + left, buf[j] + '0');
		if (otr)
			st.insert(st.begin() + left, '-');
		buf.clear();
		i = 0;
	}


	void dfsss(string &st, int &i)
	{
		string nt;
		int j = st.size();
		while (!non(st.substr(i, j - i),'(')) {
			while (st[i] != '(')
				i++;
			j = i;
			while (st[++j] != ')');
			i++;
		}
		int left = --i;
		if (!non(st, i, j))
		{
			for (int k = i + 1; k < j; k++)
				nt += st[k];
			while (status(nt) == 2)
			{
				nt.clear();
				while (st[++i] != '(');
				left = i;
				j = i;
				while (st[++j] != ')');
				for (int k = i + 1; k < j; k++)
					nt += st[k];
			}
			i = 0;
			if (status(nt) == 0)
			{
				while (!non(nt, '+') || !non(nt, '-')) {
					dfss(nt, i); //cout << st << nt << endl;
				}
			}
			else if (status(nt) == 1)
			{
				while (!non(nt, '*') || !non(nt, '/')) {
					dfsd(nt, i); //cout << st << nt << endl;
				}
				while (!non(nt, '+') || !non(nt, '-')) {
					dfss(nt, i);// cout << st << nt << endl;
				}
			}
			st.erase(st.begin() + left, st.begin() + (j + 1));
			for (int k = nt.size() - 1; k >= 0; k--)
				st.insert(st.begin() + left, nt[k]);
		}

	}

	void longop(vi &st1, vi st2, char ch)
	{
		switch (ch)
		{
		case '+':
		{
			int carry = 0;
			for (size_t i = 0; i<max(st1.size(), st2.size()) || carry; ++i) {
				if (i == st1.size())
					st1.push_back(0);
				st1[i] += carry + (i < st2.size() ? st2[i] : 0);
				if (st1[i] > 9) {
					st1[i] -= 10;
					carry = 1;
				}
				else carry = 0;
			}

			break;
		}
		case '-':
		{
			int carry = 0;
			for (size_t i = 0; i<st2.size() || carry; ++i) {
				st1[i] -= carry + (i < st2.size() ? st2[i] : 0);
				carry = st1[i] < 0;
				if (carry)
				{
					st1[i] += 10;
				}

			}
			while (st1.size() > 1 && st1.back() == 0)
				st1.pop_back();
			break;
		}
		case '*':

		{
			break;
		}
		case '/':
		{

			break;
		}
		default:
			break;
		}
	}
}


