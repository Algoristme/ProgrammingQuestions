{\rtf1\ansi\deff0{\fonttbl{\f0\fnil\fcharset0 Calibri;}}
{\*\generator Msftedit 5.41.21.2510;}\viewkind4\uc1\pard\sl240\slmult1\lang9\f0\fs22 class Solution \{\par
public:\par
    vector<int> productExceptSelf(vector<int>& nums) \{\par
         int product = 1;\par
         int zeros = 0;\par
         vector<int> out(nums.size());         \par
         for( auto num : nums) \{             \par
             if(num == 0) \{\par
                 ++zeros;\par
                 if(zeros > 1) \{\par
                     return out;\par
                 \}\par
                 continue;\par
             \}\par
             product *= num;\par
         \} \par
        \par
        int i = 0;\par
        for( auto num : nums) \{\par
            if(num ==0) \{\par
                if(zeros == 1) \{\par
                  out[i++]=product;   \par
                  break;\par
                \}                \par
            \}\par
            else \{\par
                cout << zeros << endl;\par
                if(zeros == 0) \{\par
                  cout << "came here " << std::endl;\par
                  out[i++]= product/num;\par
                \}  \par
                else\{\par
                    out[i++]=0;\par
                \}                \par
            \}\par
            \par
        \}\par
        return out;\par
    \}\par
\};\par
}
 