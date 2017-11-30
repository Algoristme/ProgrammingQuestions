// Perfect Rectangle

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
       set<pair<int,int>> uncovered;
       unordered_set<int> r;
       if(rectangles.size() <=1) return true;
       int area = 0;
       vector<pair<int,int>> coords = {make_pair(0,1),make_pair(0,3),make_pair(2,3),make_pair(2,1)};
       for(auto quad : rectangles) {
           int hash = quad[0]*1000+quad[1]*100+quad[2]*10+quad[3];
           int len   =(quad[2]-quad[0]);
           int width =(quad[3]-quad[1]);
           area+=(len*width);
           //if(r.find(hash) != r.end()) return false;
           //r.emplace(hash);
           for(auto point : coords) {
               auto x_y = make_pair(quad[point.first],quad[point.second]);
               auto it = uncovered.find(x_y);
               if(it != uncovered.end()) {
                   uncovered.erase(it);                   
               }
               else {
                   uncovered.emplace(x_y);
               }
           }           
       }
        
        if(uncovered.size() == 4) {
            auto it1 = uncovered.begin();
            auto it2 = uncovered.rbegin();    
            cout << it1->first << " " << it1->second << endl;
            cout << it2->first << " " << it2->second << endl;
            int hash = (it1->first)*1000+(it1->second)*100+(it2->first)*10+(it2->second);
            int len1 = it2->first-it1->first;
            int width1 = it2->second-it1->second;
           //if(r.find(hash) == r.end() && (rectangles%2 !=0 && (len1 == len || width1 ==wi)))
           if(area == (len1*width1))
           return true;
        }
        return false;
    }
};