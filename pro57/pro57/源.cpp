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
/*
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> vec;
		int n = intervals.size();
		if(n == 0){
			vec.push_back(newInterval);
			return vec;
		}
		int index, n_start = newInterval.start, n_end = newInterval.end;
		int g_start = n_start, g_end = n_end;
		for(index = 0;index < n;++index){
			int t_start = intervals[index].start;
			int t_end = intervals[index].end;
			if(n_start <= t_end)
				break;
			vec.push_back(intervals[index]);
		}
		if(index < n)
			g_start = min(intervals[index].start, n_start);
		for(; index < n;++index){
			int t_start = intervals[index].start;
			int t_end = intervals[index].end;
			if(t_start <= n_end && t_end >= n_end){
				g_end = t_end;
				index++;
				break;
			}
			else if(t_start > n_end){
				g_end = n_end;
				break;
			}
			else if(t_start < n_end && index == n-1){
				g_end = n_end;
				index++;
				break;
			}
		}
		vec.push_back(Interval(g_start, g_end));
		for(; index < n;++index){
			vec.push_back(intervals[index]);
		}
		return vec;
    }
};*/


class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		auto it = intervals.begin();
		for(; it!=intervals.end(); ++it){
			if(newInterval.end < (*it).start) //all intervals after will not overlap with the newInterval
				break; 
			else if(newInterval.start > (*it).end) //*it will not overlap with the newInterval
				ret.push_back(*it); 
			else{ //update newInterval bacause *it overlap with the newInterval
				newInterval.start = min(newInterval.start, (*it).start);
				newInterval.end = max(newInterval.end, (*it).end);
			}   
		}
		// don't forget the rest of the intervals and the newInterval
		ret.push_back(newInterval);
		for(; it!=intervals.end(); ++it)
			ret.push_back(*it);
		return ret;
	}
};

int main(){
	vector<Interval> vec;
	vec.push_back(Interval(1, 5));
	//vec.push_back(Interval(6, 8));
	//vec.push_back(Interval(6, 7));
	//vec.push_back(Interval(8, 10));
	//vec.push_back(Interval(12, 16));
	Interval newInterval(6, 8);
	Solution sul;
	vector<Interval> res = sul.insert(vec, newInterval);
	for(auto temp: res){
		cout<<"("<<temp.start<<", "<<temp.end<<")"<<endl;
	}
	getchar();
	return 0;
}