#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int h, m;

	cin >> h >> m;

	if (m >= 45) m = m - 45;
	else {
		m = 60 + m - 45;
		if (h == 0)
			h = 23;
		else
			h = h - 1;
	}

	cout << h <<" "<< m << "\n";


	
	return 0;
}