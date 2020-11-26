#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int boo = 1;
	vector<char>palin;
	
	for (int i = 0; i < str.size(); i++)
		if (str[i] != '-' && str[i] != '>')
			palin.push_back(str[i]);

	while (palin.size() >= 2 && boo == 1)
	{
		if (palin.front() == palin.back())
		{
			palin.pop_back();
			palin.erase(palin.begin());
		}
		else
			boo = 0;
	}

	if (boo == 0 || palin.size() == 1)
		cout << "false" << endl;
	else
		cout << "true" << endl;

	return 0;
}