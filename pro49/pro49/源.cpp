#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> total_vec;
		for(int i = 0;i < strs.size();i++){
			vector<string> vec;
			string temp = strs[i];
			if(temp == "")
				continue;
			vec.push_back(temp);
			sort(temp.begin(), temp.end());
			for(int j = i+1;j < strs.size();j++){
				if(strs[j] == "")
					continue;
				string temp1 = strs[j];
				sort(temp1.begin(), temp1.end());
				if(temp == temp1){
					vec.push_back(strs[j]);
					strs[j] = "";
				}
			}
			sort(vec.begin(), vec.end());
			total_vec.push_back(vec);
		}
		return total_vec;
    }
};*/

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int n = strs.size();
		vector<string> strs_copy(strs);
		vector<int> flag(n, 0);
		for(int i = 0;i < n;i++){
			sort(strs_copy[i].begin(), strs_copy[i].end());
		}
		int count = 0;
		for(int i = 0;i < n;i++){
			if(flag[i] != 0)
				continue;
			flag[i] = ++count;
			for(int j = i+1;j < n;j++){
				if(flag[j] != 0)
					continue;
				if(strs_copy[i] == strs_copy[j])
					flag[j] = count;
			}
		}

		vector<vector<string>> res(count);
		for(int i = 0;i < n;i++){
			res[flag[i]-1].push_back(strs[i]);
		}
		for(int i = 0;i < count;i++)
			sort(res[i].begin(), res[i].end());
		return res;
    }
};*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		multimap<string, vector<string>> strmap;
		for(unsigned int i = 0;i < strs.size();++i){
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			map<string, vector<string>>::iterator it = strmap.find(temp);
			if(it == strmap.end()){
				vector<string> vec_temp;
				vec_temp.push_back(strs[i]);
				strmap.insert(pair<string, vector<string>>(temp, vec_temp));
			}
			else{
				it->second.push_back(strs[i]);
			}
		}
		vector<vector<string>> res;
		for(auto it1 = strmap.begin(); it1 != strmap.end(); ++it1){
			sort(it1->second.begin(), it1->second.end());
			res.push_back(it1->second);
		}
		return res;
    }
};




int main(){
	string str[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> strs(begin(str), end(str));
	Solution sul;
	vector<vector<string>> res = sul.groupAnagrams(strs);
	for(auto i = 0;i < res.size();i++){
		for(auto j = 0;j < res[i].size();j++){
			cout<<res[i][j]<<"  ";
		}
		cout<<endl;
	}
	getchar();
	return 0;
}