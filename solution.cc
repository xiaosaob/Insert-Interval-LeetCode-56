// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;
        while(i < intervals.size() && intervals[i].end < newInterval.start) {
            res.push_back(intervals[i]);
            ++i;
        }
        
        if(i < intervals.size() && isOvlp(intervals[i], newInterval)) {
            int start = min(intervals[i].start, newInterval.start);
            int end = max(intervals[i].end, newInterval.end);
            while(++i < intervals.size() && isOvlp(intervals[i], newInterval)) {
                end = max(end, intervals[i].end);
            }
            res.push_back(Interval(start,end));
        } else {
            res.push_back(newInterval);
        }
        
        while(i < intervals.size())
            res.push_back(intervals[i++]);
            
        return res;
    }
    
    bool isOvlp(const Interval &i1, const Interval &i2) {
        return !(i1.start > i2.end || i2.start > i1.end);
    }
};
