// K empty slots.

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> bloomedFlowers;
        int N = flowers.size();
        if(N < 2) return -1;
        bloomedFlowers.emplace(flowers[0]);
        for(int i = 1; i < N; ++i) {
            auto it = bloomedFlowers.emplace(flowers[i]).first;
            if(it != bloomedFlowers.begin()){
                auto pIt = prev(it);
                if(*pIt == flowers[i]-k-1) {
                    return i+1;
                }
            }
            ++it;
            if(it != bloomedFlowers.end() && *it == flowers[i]+k+1) return i+1;            
        }
        return -1;
    }
};