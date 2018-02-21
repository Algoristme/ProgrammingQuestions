// Pyramid Transition Matrix  We are stacking blocks to form a pyramid. Each
// block has a color which is a one letter string, like `'Z'`.

// For every block of color `C` we place not in the bottom row, we are placing
// it on top of a left block of color `A` and right block of color `B`. We are
// allowed to place the block there only if `(A, B, C)` is an allowed triple.

// We start with a bottom row of bottom, represented as a single string. We
// also start with a list of allowed triples allowed. Each allowed triple is
// represented as a string of length 3.

// Return true if we can build the pyramid all the way to the top, otherwise
// false.

// Example 1:

// Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"] Output: true
// Explanation: We can stack the pyramid like this:









//     A
//    / \
//   D   E
//  / \ / \
// X   Y   Z

// This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.

// Example 2:

// Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
// Output: false
// Explanation:
// We can't stack the pyramid to the top.
// Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.

// Note:

//     bottom will be a string with length in range [2, 8].
//     allowed will have length in range [0, 200].
//     Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

// Seen this question in a real interview before?  

//     Difficulty:Medium
//     Total Accepted:2.5K
//     Total Submissions:5.8K
//     Contributor:1337c0d3r

//     Subscribe to see which companies asked this question.
//     Related Topics 


class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<string>> substMap;
        for ( auto str : allowed) {
            substMap[str.substr(0,2)].push_back(str.substr(2));
        }
        
        return helper(bottom,"",substMap,0).first;
    }
    pair<bool,bool> helper(string curr, string next, unordered_map<string,vector<string>> & substMap, int ind) {
        if(next.size() == 0 && curr.size()==1) {
            return {true,true};
        }
        if(next.size() == curr.size()-1) {
            return {false,true};
        }
        auto allowedSubsts = substMap[curr.substr(ind,2)];
        for(auto subst : allowedSubsts) {
            string tmp = next+subst;
            // if the next level can be constructed
            auto canDoNext = helper(curr,tmp,substMap,ind+1);
            if(canDoNext.second) {
                auto ret = helper(tmp,"",substMap,0);
                if(ret.first) {
                    return {true,true};
                }
            }
            // Don't need this since this is an exhaustive search.
            // Returning below will trim the search
            //else {
                //return {canDoNext.first,false};
            //}
        }
        return {false,false};
    }
};