#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
//��ʱ
class Solution {
public:
    string getPermutation(int n, int k) {
		string str;
		for(int i = 1;i <= n;i++)
			str += to_string(i);
		int index, cur, count = 1;
		if(count == k)
			return str;
		while(true){
			for(index = n-1;index > 0;--index)
				if(str[index] > str[index-1])
					break;
			if(index == 0)
				break;
			index--;
			for(cur = n-1;cur > index;--cur)
				if(str[cur] > str[index])
					break;
			swap(str[index], str[cur]);
			int low = index+1, high = n-1;
			while(low < high){
				swap(str[low], str[high]);
				low++;high--;
			}
			//cout<<str<<" "<<count<<endl;
			if(++count == k)
				break;
		}
		return str;
    }
};*/


class Solution {
public:
    string getPermutation(int n, int k) {
		k--;
		int m = n;
		vector<int> vec;  //���
		while(m != 0){
			int index = k / fac(m-1);
			k = k % fac(m-1);
			m--;
			vec.push_back(index);
		}
		vector<int> res;   //���
		vector<int> num;   //���е����֣�����num
		for(int i = 0;i < n;i++){
			num.push_back(i+1);
		}
		for(int i = 0;i < n;i++){
			int a = vec[i];               //���
			res.push_back(num[a]);        //�ִ�ĵ�aС������
			auto it = find(num.begin(), num.end(), num[a]);  //ɾ��������
			num.erase(it);
		}
		//תΪstring
		string str;
		for(int i = 0;i < n;i++)
			str += to_string(res[i]);
		return str;
	}

	int fac(int n){
		int res = 1;
		for(int i = 1;i <= n;i++){
			res *= i;	
		}
		return res;
	}
};


int main(){
	Solution sul;
	int n = 5, k = 1;
	string str = sul.getPermutation(n, k);
	cout<<str<<endl;
	
	getchar();
	return 0;
}