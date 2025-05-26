class Solution {
public:
    int  bs(vector<pair<int, int>>& indexedIntervals, int num)
    {
        int n=indexedIntervals.size();
        int low=0;
        int high=n-1;
        vector<int>llows;
         int mini=-1;
        while(low<=high)
        {
              int mid = low + (high - low) / 2;
            
            if (indexedIntervals[mid].first >= num) {
                mini = indexedIntervals[mid].second; 
                high = mid - 1;                      
            } else {
                low = mid + 1;                      
            }
        }
       return mini;
       
       

    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       
        int n = intervals.size();
        // Store intervals' start points and their original indices
        vector<pair<int, int>> indexedIntervals; 
        for (int i = 0; i < n; i++) {
            indexedIntervals.emplace_back(intervals[i][0], i);
        }


        vector<int>res(intervals.size(),-1);

          // Iterate over each interval to find the right interval
        sort(indexedIntervals.begin(), indexedIntervals.end());


       // Iterate over each interval to find the right interval
        for(int i=0; i<intervals.size(); i++ )
        {
            int resultant_index=bs(indexedIntervals, intervals[i][1]);
            res[i]=resultant_index;
        }
        return res;
    }
};