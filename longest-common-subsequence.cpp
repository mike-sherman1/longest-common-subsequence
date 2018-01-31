// lcs.cpp : longest common subsequence
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int c[8][6];
string b[8][6];

void length(string X, string Y) {
	int m = X.length();
	int n = Y.length();
	for (int i = 1; i <= m; i++) {
		c[i][0] = 0;
	}
	for (int j = 0; j <= n; j++) {
		c[0][j] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int stringi = i - 1;
		for (int j = 1; j <= n; j++) {
			int stringj = j - 1;
			if (X[stringi] == Y[stringj]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = "slant";
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = "up";
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = "left";
			}
		}
	}
}

int main()
{
	string X = "CABCDAB"; //length 7
	string Y = "ABDCB"; //length 5
	
	length(X, Y);
	
	for (int i = 0; i < 8; i++)    //This loops on the rows.
	{
		for (int j = 0; j < 6; j++) //This loops on the columns
		{
			cout << b[i][j] << " " << c[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}

