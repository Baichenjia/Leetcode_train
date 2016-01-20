#include "iostream"
#include "string"
using namespace std;

class Solution{
public:
	string intToRoman(int num){
        string roman[][10] = {  
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
            {"", "M", "MM", "MMM"}  
        };  
		string ret = "";
		int digit = 0;
		while(num != 0){
			int remain = num % 10;
			ret = roman[digit][remain] + ret;
			digit++;
			num /= 10;
		}
		return ret;
	}

	int romanToInt(string s) {
		int ret = toNumber(s[0]);
		for(int i = 1;i < s.length();i++){
			if(toNumber(s[i - 1]) < toNumber(s[i])){
				ret += toNumber(s[i]) - 2 * toNumber(s[i-1]);
			}
			else{
				ret += toNumber(s[i]);
			}
		}
		return ret;
    }
	
	int toNumber(char ch){
		switch(ch){
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
		return 0;
	}
};

int main(){
	Solution sul;
	string ret = sul.intToRoman(13);
	cout<<ret<<endl;
	cout<<sul.romanToInt("XIII")<<endl;
	getchar();getchar();
	return 0;
}