#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
			return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int i = 0, j = n-1;
		while(i < m && j >= 0){
			if(matrix[i][j] == target)
				return true;
			else if(matrix[i][j] < target)
				++i;
			else
				--j;	
		}
		return false;
	}
};

int main(){
	int arr1[] = {1, 3, 5, 7};  vector<int> vec1(begin(arr1), end(arr1));
	int arr2[] = {10, 11, 16, 20};  vector<int> vec2(begin(arr2), end(arr2));
	int arr3[] = {23, 30, 34, 50};  vector<int> vec3(begin(arr3), end(arr3));
	vector<vector<int>> matrix;
	matrix.push_back(vec1); matrix.push_back(vec2);  matrix.push_back(vec3);
	int target = 55;

	Solution sul;
	bool flag = sul.searchMatrix(matrix, target);
	if(flag)  cout<<"True"<<endl;
	else  cout<<"False"<<endl;

	getchar();
	return 0;
}