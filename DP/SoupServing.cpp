// There are two types of soup: type A and type B. Initially we have N ml of each type of soup. There are four kinds of operations:


//     Serve 100 ml of soup A and 0 ml of soup B
//     Serve 75 ml of soup A and 25 ml of soup B
//     Serve 50 ml of soup A and 50 ml of soup B
//     Serve 25 ml of soup A and 75 ml of soup B

// When we serve some soup, we give it to someone and we no longer have it.  Each turn, we will choose from the four operations with equal probability 0.25. If the remaining volume of soup is not enough to complete the operation, we will serve as much as we can.  We stop once we no longer have some quantity of both types of soup.

// Note that we do not have the operation where all 100 ml's of soup B are used first.  

// Return the probability that soup A will be empty first, plus half the probability that A and B become empty at the same tim

class Solution {
public:
    double soupServings(int N) {
        map<pair<int,int>,double> dp;
        if(N > 4800) return 1.0;
        return dfs(N,N,dp);
    }
    
    // probability that A is empty and B is not 
    // probability that A and B is empty
    double dfs(int A, int B, map<pair<int,int>,double> &dp) {
        
        if(dp.find(pair<int,int>(A,B)) != dp.end()) {
            return dp[pair<int,int>(A,B)];
        }
        
        if(A <= 0 && B > 0 ) return 1.0;
        if(A <=0 && B <=0) return 0.5;
        if(A > 0 && B <= 0) return 0.0;
        
        // option 1
        double p1 = 0.25 *dfs(A-100,B,dp);
        //cout << p1 << endl;
        
        // option 2
        double p2 = 0.25 * dfs(A-75,B-25,dp);
        //cout << p2 << endl;
        
        // option 3
        double p3 = 0.25 * dfs(A-50,B-50,dp);
        //cout << p3 << endl;
        
        // option 4
        double p4 = 0.25 * dfs(A-25,B-75,dp);
        //cout << p4 << endl;
        
        dp[pair<int,int>(A,B)] = p1+p2+p3+p4;
        
        return p1+p2+p3+p4;
        
        
    }
};