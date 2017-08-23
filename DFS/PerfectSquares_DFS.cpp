{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sa200\sl276\slmult1\lang9\f0\fs22  //Given a positive integer n, find the least number of perfect square numbers (for example, //1, 4, 9, 16, ...) which sum to n.\par
\par
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = //4 + 9. \par
\par
class Solution \{\par
public:\par
    int numSquares(int n) \{\par
        int least = INT_MAX;\par
        dfs(n,0,least);\par
        return least;\par
    \}\par
    \par
    void dfs(int target, int cnt, int &least) \{\par
        if(cnt >= least) \{\par
            return;\par
        \}\par
        if(target == 0) \{\par
            least = min(cnt,least);\par
            return;\par
        \}\par
        if(target < 0) \{\par
            return;\par
        \}\par
        int start = sqrt(target);\par
        for(int i = start; i >=1; --i) \{\par
            int sum = target -(i*i);\par
            dfs(sum,cnt+1,least);\par
        \}\par
    \}\par
\};\par
}
 