#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int index = -1;
		vector<string> res;
		int n = words.size();
		while(index < n){
			vector<string> line;
			int wordlen = 0, spacelen = 0;
			bool flag = false;
			while(wordlen <= maxWidth+1){
				++index;
				if(index == words.size()){
					flag = true;
					break;
				}
				wordlen += words[index].size() + 1;
				line.push_back(words[index]);
			}
			if(!flag){
				line.pop_back();
				wordlen = wordlen - words[index--].size() - 2;
			}
			else
				wordlen = wordlen - 1;
			spacelen = maxWidth - wordlen;
			string str;
			//last line
			if(index == n){
				int left_space = spacelen;
				for(int i = 0;i < line.size()-1;++i){
					str += line[i];
					str += " ";
				}
				str += line[line.size()-1];
				while(left_space--)
					str += " ";
			}
			else if(line.size() != 1){
				int avg_space = spacelen / (line.size() - 1);  //line.size()!=1
				int left_space = spacelen - (avg_space * (line.size()-1));
				for(int i = 0;i < line.size()-1;++i){
					int temp = avg_space;
					str += line[i];
					str += " ";
					while(temp--)
						str += " ";
					if(left_space > 0)
						str += " ";
					left_space--;
				}//for
				str += line[line.size()-1];
			}//if
			else{
				str += line[0];
				int temp = spacelen;
				while(temp--)
					str += " ";
			}
			res.push_back(str);
		}//while
		return res;
    }
};

int main(){
	string arr[] = {"What", "must", "be", "shall", "be."};
	vector<string> vec(begin(arr), end(arr));
	Solution sul;
	vector<string> res = sul.fullJustify(vec, 12);
	for(int i = 0;i < res.size();++i)
		cout<<"--"<<res[i]<<"--"<<endl;

	getchar();
	return 0;
}