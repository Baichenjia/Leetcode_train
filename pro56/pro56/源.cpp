#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool cmp(const Interval &A, const Interval &B){
		if(A.start < B.start)
			return true;
		else if(A.start == B.start){
			if(A.end < B.end)
				return true;
			return false;
		}
		else
			return false;
	}
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		int n = intervals.size();
		if(n == 0)
			return res;
		sort(intervals.begin(), intervals.end(), cmp);
		int start = intervals[0].start, end = intervals[0].end;
		for(int i = 1;i < n;++i){
			int t_start = intervals[i].start;
			int t_end = intervals[i].end;
			//cannot combine
			if(t_start > end){
				res.push_back(Interval(start, end));
				start = t_start;
				end = t_end;
			}
			else{
				end = max(end, t_end);
			}
		}
		res.push_back(Interval(start, end));
		return res;
    }


};

int main(){
	vector<Interval> vec;
	vec.push_back(Interval(1, 3));
	vec.push_back(Interval(8, 10));
	vec.push_back(Interval(0, 6));
	vec.push_back(Interval(15, 18));
	Solution sul;
	vector<Interval> res = sul.merge(vec);
	for(auto temp: res){
		cout<<"("<<temp.start<<", "<<temp.end<<")"<<endl;
	}
	getchar();
	return 0;
}