#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        if(n == 0)  return 1;
        int k = partation(A);
        int first_missing_index = k;
        for(int i = 0;i < k;i++){
            int temp = abs(A[i]);
            if(temp <= k && A[temp-1] > 0)
                A[temp-1] = -A[temp-1];
        }
        for(int i = 0;i < k;i++){
            if(A[i] > 0){
                first_missing_index = i;
                break;
            }
        }
        return first_missing_index+1;
    }
    
    int partation(vector<int> &A){
        int low = 0, high = A.size()-1;
        while(low < high){
            while(low < high && A[high] <= 0) 
				--high;
            while(low < high && A[low] > 0) 
				++low;
            if(low < high){
                swap(A[low], A[high]);
				if(A[low] == 0 && A[high] == 0)
					low++;
            }
			cout<<endl;
			for(int i = 0;i < A.size();i++)
				cout<<A[i]<<"  ";
        }
        if(A.size() == 1 && high == 0 && A[0] <= 0) return 0;
        else
            return high+1;
    }
};

int main(){
	Solution sul;
	int arr[100] = {0, 0, 1, 0, 3}; 
	vector<int> nums(arr, arr+1);
	int res = sul.firstMissingPositive(nums);
	cout<<res<<endl;
	getchar();getchar();
	return 0;
}