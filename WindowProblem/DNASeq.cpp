// Repeated DNA sequence
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// Example:

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

// Output: ["AAAAACCCCC", "CCCCCAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10) return {};
        unordered_map<string,int> dict;
        vector<string> out;
        for(int i = 0; i <= s.size()-10; ++i) {   
            string pattern(s.begin()+i,s.begin()+i+10);
            ++dict[pattern];
            if(dict[pattern] > 2 || dict[pattern] < 2) continue;   
            // If we are here, we have already seen the pattern once and we are seeing 
            // it for the second time. We found a repetition add it to output.
            out.emplace_back(pattern);                
        }
        return out;
    }
};
