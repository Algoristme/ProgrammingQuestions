// Minimum costs for tickets
class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
      unordered_set<int> travel(begin(days), end(days));
      int dp[366] = {};
      for (int i = 1; i < 366; ++i) {
        if (travel.find(i) == travel.end()) dp[i] = dp[i - 1];
        else dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
       }
      return dp[365];
    }
    
    
    int mincostTickets1(vector<int>& days, vector<int>& costs) {
        map<int,int> dp;

        vector<int> passes = {1,7,30};       
        
        for(int i = 0; i < days.size(); ++i) {
            for(int j = 0; j < costs.size(); ++j) {    
                int prevInd = days[i]-passes[j];
                int prevVal = 0;
                if(dp.size() > 0 && prevInd > 0) {
                    auto it = dp.lower_bound(prevInd);
                    // one before the lowest
                    if(it == dp.end() || it->first > prevInd)--it;
                    prevVal = it->second;
                    //cout << days[i] << endl;
                    //cout << prevInd << "  lower_b " << it->first << " @ " << it->second << endl; 
                } 
                if(dp.find(days[i]) == dp.end()) {
                    dp[days[i]] = prevVal+costs[j];
                }
                else {
                    dp[days[i]] = min(prevVal+costs[j],dp[days[i]]);
                }                
            }
            //cout << " Min for " << days[i] << "==>" <<  dp[days[i]] << endl;
        }        
        return dp[days[days.size()-1]];
    }
};