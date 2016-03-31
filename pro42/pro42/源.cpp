#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int> A) {
		int n = A.size();
        int left = 0; int right = n-1;
        int res = 0;
        int maxleft = 0, maxright = 0;
        while(left <= right){
            if(A[left] <= A[right]){
                if(A[left] >= maxleft) 
					maxleft = A[left];
                else 
					res += maxleft-A[left];
                left++;
            }
            else{
                if(A[right] >= maxright) 
					maxright = A[right];
                else 
					res += maxright-A[right];
                right--;
            }
        }
        return res;
    }
};


int main(){
	Solution sul;
	int arr[12] = {0, 0, 2, 1101, 1000};
	vector<int> A(arr, arr+1);
	int res = sul.trap(A);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}