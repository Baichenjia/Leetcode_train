#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		if(s.size() == 0 || words.size() == 0)  return res;

		map<string, int> List;
		for(unsigned int i = 0;i < words.size();i++){
			map<string, int>::iterator iter = List.find(words[i]);
			if(iter != List.end())
				iter->second++;
			else
				List.insert(pair<string, int>(words[i], 1));
		}

		int wordLen = words[0].size();
		for(unsigned int i = 0;i < wordLen;i++){
			map<string, int> templist;
			int left = i, count = 0;
			while(left+(count+1)*wordLen <= s.size()){
				string sub = s.substr(left+count*wordLen, wordLen);
				if(List.find(sub) != List.end()){
					count++;
					if(templist.find(sub) != templist.end())
						templist[sub]++;
					else
						templist.insert(pair<string, int>(sub, 1));
					while(templist[sub] > List[sub]){
						string sub2 = s.substr(left, wordLen);
						templist[sub2]--;
						count--;
						left+=wordLen;
					}
				}
				//出现了单词列表中没有的单词
				else{
					left += (count+1) * wordLen;
					count = 0;
					templist.clear();
				}
				if(count == words.size()){
					res.push_back(left);
				}
			}
		}
		return res;
    }
};

void print(string str){
	cout<<str<<endl;
}

int main(){
	Solution sul;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words;
	words.push_back("word");  
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	vector<int> res = sul.findSubstring(s, words);
	for(unsigned int i = 0;i < res.size();i++) cout<<res[i]<<endl;
	getchar();getchar();
	return 0;
}