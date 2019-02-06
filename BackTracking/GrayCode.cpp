// Given a binary tree, return the vertical order traversal of its nodes values.

// For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

// Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

// If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

// Return an list of non-empty reports in order of X coordinate.  Every
// report will have a list of values of nodes.

 Solution {
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