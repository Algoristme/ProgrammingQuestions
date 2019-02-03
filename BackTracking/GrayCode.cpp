class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> v;
        helper(n,"01",v,"");
        return v;
    }
    void helper(int n, string order, vector<int> &v, string s) {
        if(n == 0) return;
        
        if(n == 1) {
            if(order == "01") {
                v.emplace_back(stoi(s+"0",nullptr,2));
                v.emplace_back(stoi(s+"1",nullptr,2));
            }
            else {
                v.emplace_back(stoi(s+"1",nullptr,2));
                v.emplace_back(stoi(s+"0",nullptr,2));
            }
            return;
        }
        if(order == "01") {
            helper(n-1,"01",v,s+"0");
            helper(n-1,"10",v,s+"1");
        }
        if(order == "10") {
            helper(n-1,"01",v,s+"1");
            helper(n-1,"10",v,s+"0");            
        }
    }
};