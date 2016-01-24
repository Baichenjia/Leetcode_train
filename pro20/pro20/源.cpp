#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
		if(s.size()%2 == 1)
			return false;
		for(int i = 0;i < s.size();i++){
			if(vec.size() == 0)
				vec.push_back(s[i]);
			else if(reverse(vec[vec.size()-1]) == s[i]){
				vec.pop_back();
			}
			else{
				vec.push_back(s[i]);
			}
		}
		if(vec.size() == 0)
			return true;
		else
			return false;
    }

	char reverse(char c){
		switch(c){
		case '{':return '}';
		case '(':return ')';
		case '[':return ']';
		}
		return c;
	}
};

int main(){
	Solution sul;
	string str = "{[{()}]{[]}({})}";
	if(sul.isValid(str)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	getchar();getchar();return 0;
}

//另一个种解法
/*
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': paren.push(c); break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; // pass
            }
        }
        return paren.empty() ;
    }
};*/