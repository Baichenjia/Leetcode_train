#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
		vector<int> sort_nums;
		for(int i = 0;i < nums1.size(); i++)
			sort_nums.push_back(nums1[i]);
		for(int j = 0;j < nums2.size(); j++)
			sort_nums.push_back(nums2[j]);
		sort(sort_nums.begin(), sort_nums.end());
		int n = sort_nums.size();
		double res;
		if(n%2 == 1)
			res = sort_nums[(n-1)/2];
		else
			res = double(sort_nums[n/2] + sort_nums[n/2-1]) / 2.0;
		return res;
	}


	double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
		vector<int> sum_nums;
		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		while(true)
		{
			if(it1 == nums1.end()){
				for(;it2 != nums2.end();it2++)
					sum_nums.push_back(*it2);
				break;
			}
			if(it2 == nums2.end()){
				for(;it1 != nums1.end();it1++)
					sum_nums.push_back(*it1);
				break;
			}
			if(*it1 <= *it2){
				sum_nums.push_back(*it1);
				it1++;
			}
			else{
				sum_nums.push_back(*it2);
				it2++;
			}
		}
		int n = sum_nums.size();
		if(n%2 == 1)
			return sum_nums[(n-1)/2];
		else
			return (sum_nums[n/2] + sum_nums[n/2 - 1]) / 2.0;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		
	
	}

};


int main()
{
	int arr1[5] = {};
	int arr2[3] = {2, 3};
	vector<int> nums1;
	vector<int> nums2(arr2, arr2+2);
	Solution sul;
	double res = sul.findMedianSortedArrays(nums1, nums2);
	cout<<res<<endl;

	getchar(); getchar();
	return 0;
}


//****************************************************
//CÓïÑÔ½â·¨
/*
double min(int x,int y)
{
    if(x < y)
        return x;
    else
        return y;
}

double findKth(int a[], int m, int b[], int n, int k)
{
	//always assume that m is equal or smaller than n
	if (m > n)
		return findKth(b, n, a, m, k);
	if (m == 0)
		return b[k - 1];
	if (k == 1)
		return min(a[0], b[0]);
	//divide k into two parts
	int pa = min(k / 2, m), pb = k - pa;
	if (a[pa - 1] < b[pb - 1])
		return findKth(a + pa, m - pa, b, n, k - pa);
	else if (a[pa - 1] > b[pb - 1])
		return findKth(a, m, b + pb, n - pb, k - pb);
	else
		return a[pa - 1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    //int m = sizeof(A)/sizeof(A[0]);
    //int n = sizeof(B)/sizeof(B[0]);
	int total = m + n;
	if (total & 0x1)
		return findKth(A, m, B, n, total / 2 + 1);
	else
		return (findKth(A, m, B, n, total / 2)
				+ findKth(A, m, B, n, total / 2 + 1)) / 2;
}
*/