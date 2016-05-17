#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/*
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
			return ;
		const int m = matrix.size();
		const int n = matrix[0].size();
		bool *rowflag = new bool[m];
		bool *colflag = new bool[n];
		for(int i = 0;i < m;++i)  rowflag[i] = false;
		for(int i = 0;i < n;++i)  colflag[i] = false;
		for(int i = 0;i < m;++i){
			for(int j = 0;j < n;++j){
				if(matrix[i][j] == 0){
					rowflag[i] = true;
					colflag[j] = true;
				}
			}
		}
		for(int i = 0;i < m;++i){
			if(rowflag[i] == true){
				for(int j = 0;j < n;++j){
					matrix[i][j] = 0;
				}
			}
		}
		for(int j = 0;j < n;++j){
			if(colflag[j] == true){
				for(int i = 0;i < m;++i){
					matrix[i][j] = 0;
				}
			}
		}
    }*/

	void setZeroes(vector<vector<int> > &matrix) {
		int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

	    for (int i = 0; i < rows; i++) {
		    if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < cols; j++)
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
		}

		for (int i = rows - 1; i >= 0; i--) {
			for (int j = cols - 1; j >= 1; j--)
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			if (col0 == 0) matrix[i][0] = 0;
		}	
	}


};

int main(){
	
	vector<vector<int>> matrix;
	int arr1[] = {1, 1, 1}; vector<int> vec1(begin(arr1), end(arr1));
	int arr2[] = {0, 1, 2}; vector<int> vec2(begin(arr2), end(arr2));
	matrix.push_back(vec1);
	matrix.push_back(vec2);

	Solution sul;
	sul.setZeroes(matrix);
	for(int i = 0;i < matrix.size();++i){
		for(int j = 0;j < matrix[i].size();++j)
			cout<<matrix[i][j]<<'\t';
		cout<<endl;
	}
	

	getchar();
	return 0;
}