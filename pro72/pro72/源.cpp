#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=(int)word1.length()+1;  
        int len2=(int)word2.length()+1;  
        int** p=new int*[len1];  
        if(!p){  
            return 0;  
        }  
  
        for(int i=0;i<len1;i++){  
            p[i]=new int[len2];  
            if(!p[i]){  
                return 0;  
            }  
        }  
        for(int i=0;i<len1;i++){  
            p[i][0]=i;  
        }  
        for(int j=0;j<len2;j++){  
            p[0][j]=j;  
        }  
        for(int i=1;i<len1;i++){  
            for(int j=1;j<len2;j++){  
                int tmp_step;  
                if( word1[i-1]==word2[j-1])//注意这里下标容易写错。一开始写成了if(word[i]==word2[j])  
                    tmp_step=0+p[i-1][j-1];  
                else  
                    tmp_step=1+p[i-1][j-1];  
                int tmp_step2=min((p[i-1][j]+1),(p[i][j-1]+1));  
                p[i][j]=min(tmp_step2,tmp_step);  
            }  
        }  
          
        return p[len1-1][len2-1];  
    }  
};

int main(){
	string str1 = "a";
	string str2 = "b";
	Solution sul;
	int res = sul.minDistance(str1, str2);
	cout<<res<<endl;

	getchar();
	return 0;
}