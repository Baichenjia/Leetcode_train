#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		vector<pair<int, int>> point;
		for(int i = 0;i < height.size();i++){  //ÅÅÐò
			point.push_back(pair<int, int>(height[i], i));
		}
		sort(point.begin(), point.end());
		int maxarea = 0;
		for(vector<pair<int, int>>::iterator iter1 = point.begin();iter1 != point.end();++iter1)
		{               
			int a1 = iter1->first;
			int a2 = iter1->second;
			for(vector<pair<int, int>>::iterator iter2 = iter1;iter2 != point.end();iter2++)
			{
				int b1 = iter2->first;
				int b2 = iter2->second;
				int area = b2-a2 * a1;
				if(maxarea < area)
					maxarea = area;
			}
		}
		return maxarea;
    }


	int maxArea2(vector<int>& height) {
		int water = 0;
		int i = 0, j = height.size() - 1;
		while (i < j) {
			int h = min(height[i], height[j]);
			water = max(water, (j - i) * h);
			while (height[i] <= h && i < j) i++;
			while (height[j] <= h && i < j) j--;
		}
		return water;
	}
};

int main(){
	Solution sul;
	int a[4] = {3, 1, 2, 1};
	vector<int> height(a, a+4);
	int maxarea = sul.maxArea(height);
	cout<<maxarea<<endl;
	getchar();getchar();
	return 0;
}