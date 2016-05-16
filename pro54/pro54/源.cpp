#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
		int start = 0;
		int rows = matrix.size();
		if(rows == 0)
			return res;		
		int columns = matrix[0].size();  //size of matrix
		while(rows > start*2 && columns > start*2){
			int endX = columns - 1 - start;
			int endY = rows - 1 - start;
			// 从左到右打印一行
			for(int i = start; i <= endX; ++i)
				res.push_back(matrix[start][i]);
			// 从上到下打印一列
			if(start < endY)
				for(int i = start + 1; i <= endY; ++i)
					res.push_back(matrix[i][endX]);
			// 从右到左打印一行
			if(start < endX && start < endY)
				for(int i = endX - 1; i >= start; --i)
					res.push_back(matrix[endY][i]);
			// 从下到上打印一行
			if(start < endX && start < endY - 1)
				for(int i = endY - 1; i >= start + 1; --i)
					res.push_back(matrix[i][start]);
			++start;
		}
		return res;
    }
};


int main(){
	vector<vector<int>> vec;
	/*
	int arr1[] = {1,2,3,4,5};      vector<int> vec1(begin(arr1), end(arr1));
	int arr2[] = {14,15,16,17,6};  vector<int> vec2(begin(arr2), end(arr2));
	int arr3[] = {13,20,19,18,7};  vector<int> vec3(begin(arr3), end(arr3));
	int arr4[] = {12,11,10,9,8};   vector<int> vec4(begin(arr4), end(arr4));
	vec.push_back(vec1);
	vec.push_back(vec2);
	vec.push_back(vec3);
	vec.push_back(vec4);

	*/
	vector<int> temp1; temp1.push_back(1);
	vec.push_back(temp1);
	temp1.clear(); temp1.push_back(2);  vec.push_back(temp1);
	temp1.clear(); temp1.push_back(3);  vec.push_back(temp1);

	vector<vector<int>> nullvec;
	Solution sul;
	vector<int> res = sul.spiralOrder(vec);
	for(int i = 0;i < res.size();++i)
		cout<<res[i]<<"  ";
	cout<<endl;
	getchar();
	return 0;
}