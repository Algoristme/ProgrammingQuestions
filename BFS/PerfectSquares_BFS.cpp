{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sl240\slmult1\lang9\f0\fs22\par
\par
//Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, //9, 16, ...) which sum to n.\par
\par
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = //4 + 9. \par
\par
class Solution \{\par
public:\par
    int numSquares(int n) \{\par
        if(n < 0) return -1;\par
        queue<int> q;\par
        q.push(n);\par
        int depth = 0;\par
        while(!q.empty())\{\par
            ++depth;\par
            int sz = q.size();                                 \par
            for(int i = 0; i < sz; ++i ) \{             \par
             int curr = q.front();            \par
             int sr = sqrt(curr);\par
             q.pop();   \par
             for(int n = sr; n >0; --n)\{\par
                int delta = curr -(n*n);\par
                if(delta == 0) \{\par
                  //cout << curr << " " << n << endl;\par
                  return depth;   \par
                \}\par
                q.push(delta);\par
                //cout << "Delta " << delta << endl;\par
             \}\par
            \}\par
        \}\par
    \}\par
\};\par
}
 