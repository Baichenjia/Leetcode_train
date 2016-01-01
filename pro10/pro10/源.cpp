#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;



bool isMatch(char *s, char *p) {  
	if (*p == 0) return *s == 0;  
	if (*(p+1) != '*')  
	{  
		if (*s != 0 && (*p == *s || *p == '.')) return isMatch(s+1, p+1);  
		else return false;  
	}  
	else  
	{  
		while (*s != 0 && (*s == *p || *p == '.'))  
		{  
			if (isMatch(s, p+2)) return true;  
			s++;  
		}  
		return (isMatch(s, p+2));  
	}  

}


int main(){
	char s[] = "aab";
	char p[] = "c*a*.";
	bool flag = isMatch(s, p);
	if(flag)  cout<<"Yes"<<endl;
	else  cout<<"No"<<endl;

	getchar();getchar();
	return 0;
}