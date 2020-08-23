#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

long long solution(int w, int h)
{
	long long answer = 0;
	
	for (int x = 1; x < w; x++) {
		int y;
		y = -((double)h / w)*x + h;
		answer += y;
	}


	return answer;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << solution(3,5) << "\n";
	return 0;
}