#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>
#include<cmath>
#include<stack>
#include<map>

using namespace std;


class p {
public:
	int idx;
	int standard;
	int outlinknum;
	double myscore;
	double linkscore;
	double matchscore;
	string url;
	vector<int> inlink;
	vector<int> outlink;
	int inlinkbit = 0;
	int bitmask;

	p(int i) : idx(i){
		standard = 0;
		url = "";
		myscore = 0;
		outlinknum = 0;
		linkscore = 0;
		matchscore = 0;
		inlinkbit = 0;
		bitmask = 0;
	}
};

vector<p> page_v;
map<string, int> mymap;

bool cmp(p p1, p p2) {
	if (p1.matchscore > p2.matchscore)
		return true;
	else if (p1.matchscore == p2.matchscore)
		return p1.idx < p2.idx;
	else
		return false;
}
string makelower(string page) {
	string ret = "";
	for (int i = 0; i < page.size(); i++) {
		if (page.at(i) >= 'A' && page.at(i) <= 'Z') {
			ret += (page.at(i) - 'A' + 'a');
		}
		else {
			ret += page.at(i);
		}
	}
	return ret;
}

void getinfo(string page, int page_idx, string w) {

	int start_idx = 0;

	while (1) {
		int meta_start = page.find("<meta", start_idx);
		int meta_end = page.find(">", meta_start + 4);
		int content_idx = page.find("content", meta_start + 4);
		if (content_idx != -1 && content_idx < meta_end) {
			int url_start = page.find("https://", content_idx + 9);
			int url_end = page.find('"', url_start + 8);
			page_v.at(page_idx).url = page.substr(url_start, url_end - url_start);
			mymap.insert(pair<string, int>(page_v.at(page_idx).url, page_idx));
			start_idx = meta_end;
			break;
		}
		start_idx = meta_end + 1;
	}

	int body_start = page.find("<body>", start_idx);
	int body_end = page.find("body>", body_start + 6);

	start_idx = body_start + 6;
	bool a = false;
	int cnt = 0;
	for (int i = start_idx; i < body_end; i++) {
		if (!a) {
			if (page.at(i) < 'a' || page.at(i) > 'z') {
				if (page.at(i) == '<') {
					a = true;
				}

				if (w.size() == cnt && page.substr(i - cnt, cnt) == w) {
					page_v.at(page_idx).standard++;
				}
				cnt = 0;
			}
			else
				cnt++;
		}
		if (page.at(i) == '>') {
			a = false;
		}
	}
}
void setscore(string page, int page_idx) {
	int start_idx = 0;

	while (1) {
		int a_start = page.find("<a", start_idx);
		if (a_start == -1) {
			break;
		}
		else {
			int a_end = page.find('>', a_start + 2);
			int url_start = page.find("https://", a_start + 2);
			if (url_start != -1) {
				int url_end = page.find('"', url_start);
				string url = page.substr(url_start, url_end - url_start);
				map<string, int>::iterator iter;
				iter = mymap.find(url);
				if (iter != mymap.end()) {
					page_v.at(page_idx).outlink.push_back(iter->second);
					page_v.at(iter->second).inlink.push_back(page_idx);
					page_v.at(iter->second).inlinkbit |= (1 << page_idx);
				}
				page_v.at(page_idx).outlinknum++;
				start_idx = url_end + 2;
			}
			else
				start_idx = a_end + 1;
		}
	}
	
}
int solution(string word, vector<string> pages) {
	int answer = 0;
	
	vector<string> lowerpages;
	string lowerword = makelower(word);

	for (int i = 0; i < pages.size(); i++) {
		string newpage = makelower(pages.at(i));
		lowerpages.push_back(newpage);
		page_v.push_back(p(i));
	}
	for (int i = 0; i < pages.size(); i++) {
		getinfo(lowerpages.at(i), i, lowerword);
	}
	for (int i = 0; i < pages.size(); i++) {
		setscore(lowerpages.at(i), i);
	}
	for (int i = 0; i < page_v.size(); i++) {
		page_v.at(i).myscore = (double) page_v.at(i).standard / page_v.at(i).outlinknum;
	}
	for (int i = 0; i < page_v.size(); i++) {
		for (int j = 0; j < page_v.at(i).inlink.size(); j++) {
			int idx = page_v.at(i).inlink.at(j);
			page_v.at(i).linkscore += page_v.at(idx).myscore;
		}
		page_v.at(i).matchscore = page_v.at(i).standard + page_v.at(i).linkscore;
	}
	sort(page_v.begin(), page_v.end(), cmp);

	answer = page_v.front().idx;
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1 = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>";
	string s2 = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>";
	string s3 = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>";
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	int ans = solution("Blind", v);
	return 0;
}