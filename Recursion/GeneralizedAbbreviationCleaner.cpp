// Generalize Abbreviations

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        helper(word,"",word.size(),0);
        return out;
    }
    void helper(string word, string encode, int cnt, int ind){
        if(ind==word.size()) {
            out.push_back(encode);
            return;
        }
        string str ="";
        //cout << "choosing " << word[ind] << endl;
        str = encode+word[ind];
        helper(word,str,word.size()-ind,ind+1);
        
        //cout << "not choosing " << word[ind] << " " << encode<<endl;
        // if the previous index is a number
        // extract the number and add one to it.
        string num;
        int j = encode.size()-1;
        for(;j>=0;--j){
            if(encode[j]-'0'>=0 && encode[j]-'0' <=9){
                num = encode[j]+num;
            }
            //cout << num << endl;
            break;
        }
        if(num.size()>0){
             //strip the previous nums
             encode = encode.substr(0,j);
             //cout << "After stripping " <<j << " "<<encode.size()<< encode << endl;
             int cnt = stoi(num)+1;
             encode+=to_string(cnt);
        }
        else
            encode+=to_string(1);    
        
        helper(word,encode,word.size()-ind,ind+1);
    }
private:
    vector<string> out;
};