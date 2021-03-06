// Skyline problem.
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // Out of each building triplet we create two coordinates
        // 1. (buildingStart, Height)
        // 2. (buildingEnd, -Height) -- because when the building end, ht decreases by -ht
        vector<pair<int,int>> coords;
        for (vector<int> eachB:buildings) {
            coords.push_back({eachB[0],-eachB[2]});
            coords.push_back({eachB[1],eachB[2]});
        }
        sort(coords.begin(),coords.end());
        
        // Plotting part
        // Datastructure below, keeps a list of building hts which are active
        // The skyline is nothing but the tallest of all the active buildings.
        multiset<int> activeBuildingHts{0};
        vector<pair<int,int>> skyLine; 
        // Before starting the walk, intialize prevHt to -1 to indicate that 
        // nothing has been processed yet.
        int prevHt = 0;
        int tallestActiveBuildingHt;
        // We are walking from left to right, on coordinate axes
        for(auto pt : coords) {
            if(pt.second<0) {
                // Ht > 0, indicates an active building, add this to 
                // active building heights
                activeBuildingHts.emplace(-pt.second);
            }
            else {
                // We just passed this building, this won't be part of the 
                // skyline any more.
                activeBuildingHts.erase(activeBuildingHts.find(pt.second));
            }
            tallestActiveBuildingHt = *activeBuildingHts.rbegin();
            if(prevHt !=tallestActiveBuildingHt) {
                skyLine.emplace_back(pt.first,tallestActiveBuildingHt);
                prevHt = tallestActiveBuildingHt; 
            }
        }
        return skyLine;
    }
};