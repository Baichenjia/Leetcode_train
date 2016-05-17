#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
class Solution {
public:
    int mySqrt(int x){
		int low = 0;
		int high = min(46341, x);
		while(low <= high){
			int mid = (low + high)/2;
			int s = mid * mid;
			if(s == x)
				return mid;
			else if(s < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		low = min(46340, low);
		int temp = low * low;
		while(low * low > x)
			low--;
		return low;
	}
};*/

/*
class Solution {
public:
	int mySqrt(int x) {
		if (x == 0)
			return 0;
		int left = 1, right = INT_MAX;
		while (true) {
			int mid = left + (right - left)/2;
			if (mid > x/mid) {
				right = mid - 1;
			} 
			else {
				if (mid + 1 > x/(mid + 1))
					return mid;
				left = mid + 1;
			}
		}
	}
};*/


class Solution {
public:
	int mySqrt(int x){
		long long r = x;
		while(r*r > x)
			r = (r + x/r) / 2;
		return r;
	}
};


int main(){
	int n = 2147483647;
	//int n = 16;
	Solution sul;
	int res = sul.mySqrt(n);
	cout<<res<<endl;

	//cout<<sqrt(1579205274.0)<<endl;
	getchar();
	return 0;
}