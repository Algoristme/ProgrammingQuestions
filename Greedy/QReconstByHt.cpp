// Queue reconstruction by ht.

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        // sort the people based on their ht as the first parameter and,
        // use "k" to resolve the conflict.
        sort(people.begin(), people.end(),[](const pair<int,int> &p1, const pair<int,int> &p2)
                                           { return ((p1.first > p2.first) || (p1.first == p2.first)&&(p1.second < p2.second));});
        
        vector<pair<int,int>> out;                
        
        for( int i = 0; i < people.size(); ++i) {            
            out.insert(out.begin()+people[i].second,people[i]);
        }
        
        return out;
    }
};