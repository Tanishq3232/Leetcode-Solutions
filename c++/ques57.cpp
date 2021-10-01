class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        vector<int> prev=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> temp=intervals[i];
            if(temp[0]>prev[1])
            {
                ans.push_back(temp);
                prev=temp;
            }
            else if(temp[0]<=prev[1] && temp[1]>prev[1])
            {
                temp[0]=prev[0];
                ans.pop_back();
                ans.push_back(temp);
                prev=temp;
            }
        }
        return ans;
    }
};