#include "MinStack.h"
#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main()
{
	string all_command;
	getline(cin, all_command);
	string number;
	getline(cin, number);
	int countnum = 0;
	int start = 0;
	int noofcommand = 0;
	MinStack minstack;
	for (int i = 0; all_command[i] != ']'; i++)
	{
		if (all_command[i] == 'M')
		{
			start = 1;
			noofcommand++;
		}
		if (start == 1)
		{
			if (all_command[i] == 'p')
			{
				i++;
				if (all_command[i] == 'u')
				{
					noofcommand++;
					for (int j = 2, int k = 0; k == 2; j++)
					{
						if (number[j] == '[')
						{
							k--;
							noofcommand++;
						}

						if (number[j] == ']')
							k++;
					}
				}
			}
		}
		countnum++;
	}
}