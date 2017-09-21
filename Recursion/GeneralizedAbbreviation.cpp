// Write a function to generate the generalized abbreviations of a word.

// Example:

// Given word = "word", return the following list (order does not matter):

// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]


class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> allAbbrv;        
        if(word.size()==0){
            allAbbrv.emplace_back("");
            return allAbbrv;
        }
        int cnt = word.size();                
        allAbbrv.emplace_back(to_string(cnt));
        for(int i = 1; i <= cnt; ++i){
            vector<bool> leftIndices(cnt,0);
            genAbbrvs(word, leftIndices, allAbbrv, i, 0);
        }
        return allAbbrv;
    }
    
    void genAbbrvs(string word, vector<bool> &used, vector<string> &out, int cnt, int ind) {        
        if(cnt == 0) {
            //for(int i=0; i < used.size(); ++i) 
                //cout << used[i] << " " ;
            
            //cout<< endl;

            string abbr = genAbbrv(word,used);
            out.push_back(abbr);
            return;
        }
        if(ind == word.size()) return;
        //for ( int i = ind; i < word.size(); ++i) {
                if(!used[ind]) {
                   used[ind] = true;
                   //cout << "chose " << ind <<  endl;
                   genAbbrvs(word,used,out,cnt-1,ind+1);
                   used[ind] = false;    
                }                            
                genAbbrvs(word,used,out,cnt,ind+1);
        //}        
        
    }
    
    string genAbbrv(string word, vector<bool> &unused) {
        int cnt=0;
        string out;
        for(int i = 0; i < unused.size(); ++i) {
            if(!unused[i]) {
                ++cnt;
                if(i == unused.size()-1) {
                    out+=to_string(cnt);
                }
            }
            else {
                if(cnt >0) {
                    out+=to_string(cnt);
                    cnt = 0;
                }
                out +=word[i];                
            }
        }
        return out;
    }
};