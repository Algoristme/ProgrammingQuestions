{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22 //Skyline Problem\par
class Solution \{\par
public:\par
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) \{\par
        // Out of each building triplet we create two coordinates\par
        // 1. (buildingStart, -Height) -- we do this because, when we sort we want to add\par
        //                                a building before removing some other building.\par
        // 2. (buildingEnd, Height) -- because when the building end, ht decreases by -ht\par
        vector<pair<int,int>> coords;\par
        for (vector<int> eachB:buildings) \{\par
            coords.push_back(\{eachB[0],-eachB[2]\});\par
            coords.push_back(\{eachB[1],eachB[2]\});\par
        \}\par
        sort(coords.begin(),coords.end());\par
        \par
        // Plotting part\par
        // Datastructure below, keeps a list of building hts which are active\par
        // The skyline is nothing but the tallest of all the active buildings.\par
        multiset<int> activeBuildingHts\{0\};\par
        vector<pair<int,int>> skyLine; \par
        // Before starting the walk, intialize prevHt to -1 to indicate that \par
        // nothing has been processed yet.\par
        int prevHt = 0;\par
        int tallestActiveBuildingHt;\par
        // We are walking from left to right, on coordinate axes\par
        for(auto pt : coords) \{\par
            if(pt.second<0) \{\par
                // Ht > 0, indicates an active building, add this to \par
                // active building heights\par
                activeBuildingHts.emplace(-pt.second);\par
            \}\par
            else \{\par
                // We just passed this building, this won't be part of the \par
                // skyline any more.\par
                activeBuildingHts.erase(activeBuildingHts.find(pt.second));\par
            \}\par
            tallestActiveBuildingHt = *activeBuildingHts.rbegin();\par
            if(prevHt !=tallestActiveBuildingHt) \{\par
                skyLine.emplace_back(pt.first,tallestActiveBuildingHt);\par
                prevHt = tallestActiveBuildingHt; \par
            \}\par
        \}\par
        return skyLine;\par
    \}\par
\};\par
}
 