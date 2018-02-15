// In a forest, each rabbit has some color. Some subset of rabbits (possibly
// all of them) tell you how many other rabbits have the same color as them.
// Those answers are placed in an array.

// Return the minimum number of rabbits that could be in the forest.

// Examples:
// Input: answers = [1, 1, 2]
// Output: 5
// Explanation:
// The two rabbits that answered "1" could both be the same color, say red.
// The rabbit than answered "2" can't be red or the answers would be inconsistent.
// Say the rabbit that answered "2" was blue.
// Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
// The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

// Input: answers = [10, 10, 10]
// Output: 11

// Input: answers = []
// Output: 0


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_set<int> colorMap;
        unordered_map<int,int> hits;
        int minRabbs = 0;
        for (int i = 0 ; i < answers.size(); ++i ) {
            if(answers[i] !=0 && colorMap.find(answers[i]+1) != colorMap.end()) {  
                ++hits[answers[i]+1];
                if(hits[answers[i]+1] == answers[i]+1) {
                    auto it = colorMap.find(answers[i]+1);
                    hits[answers[i]+1] = 0;
                    colorMap.erase(it);
                }             
                continue;
            }
            minRabbs += answers[i]+1;
             ++hits[answers[i]+1];
            colorMap.emplace(answers[i]+1);
        }
        
        return minRabbs;
        
    }
};