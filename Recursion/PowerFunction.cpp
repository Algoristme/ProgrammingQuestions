// Implement pow(x, n)
class Solution {
public:
    double myPow(double x, int n) {
        return n >= 0 ? helper(x,n) : 1/helper(x,n);
    }
    double helper(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        auto it = cache.find(n);
        if(it != cache.end()) {
            return it->second;
        }
        
        double result;
        if(n%2 ==0)
          result = helper(x,n/2) * helper(x,n/2);
        else
          result = x * helper(x,n/2) * helper(x,n/2);
        cache.emplace(n,result);
        return result;
    }
private :
    unordered_map<int,double> cache;    
};