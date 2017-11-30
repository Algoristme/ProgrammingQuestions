// Next closest time.

class Solution {
public:
    string nextClosestTime(string time) {
        for(auto c: time) {
            if(c ==':') continue;
            digs.emplace(c);
        }
        string sec = time.substr(3);
        string min = time.substr(0,2);                
        
        auto ret = getNext(sec,false);
        if(strcmp(ret.data(),sec.data())<=0){
            min = getNext(min,true);
        }
        return min+":"+ret;
    }
    
    // returns false if it next closest is smaller
    // than the current str
    string getNext(string str, bool hrs){
        string nextClosest = str;                
        int i = 1;
        while(i>=0) {
            auto it = digs.find(str[i]);
            auto nextIt = next(it) ;
            if(nextIt != digs.end()) {
                nextClosest[i] = *nextIt;
            }
            if(nextIt == digs.end() || !isValid(nextClosest,hrs)){
                nextClosest[i] = *(digs.begin());
            }
            else {
                break;
            }
            --i;
        }
        return nextClosest;
    }
    
    bool isValid(string str, bool hrs){
        if(!hrs && str[0] < '6') return true;
        string hours ="24";
        if(hrs && strcmp(str.data(),hours.data()) <0) return true;
        return false;
    }
private:
    set<int> digs;
};