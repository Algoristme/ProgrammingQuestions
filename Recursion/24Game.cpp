// 24 Game
// BackTracking

class Solution {
public:
    bool judgePoint24(vector<int>& in) {
        if(in.size() == 0 ) return false;
        vector<int> out;
        vector<float> nums; 
        for(int i = 0; i < in.size(); ++i) {
            nums.push_back(in[i]);
        }
        int found = false;
        pickTwo(out,nums,0,found);
        return found;
    }
    float doOp(int i, float a, float b){
        switch(i) {
            case 1 : return (float)a+b;
            case 2 : return (float)abs(a-b) ;
            case 3 : return (float)a*b;
            case 4 : {
                if (b == 0.0 ) return 0.0;
                return (float)a/b;
            }
            case 5 : {
                if (a == 0.0) return 0.0;
                return (float)b/a;
            } 
            
        }
        return 0;
    }
    void pickTwo(vector<int> out, vector<float>  nums,  int start, int &found) {    
        if(found) return;
        if(nums.size()==2) {
            //cout << "Nums " << nums[0] << " " << nums[1] << endl;
            int k = 6;
            while (k--){                
                if(abs(doOp(k,nums[0],nums[1])-24.0) <= 0.00001) {
                    cout << "Nums " << nums[0] << " " << nums[1] << endl;
                    cout << doOp(k,nums[0],nums[1]) << endl; 
                    found = true;
                }
            }            
            return;
        }
        if(out.size() == 2) {
            //cout << out[0] << " " << out[1] << endl;
            //return;
            int i = 6;
            
            while(i--){
            float res = doOp(i,nums[out[0]],nums[out[1]]);
            if(res == 0) continue;
                        
            vector<float> nset;
            nset.emplace_back(res);
            for(int i = 0; i < nums.size(); ++i) {
                if(i == out[0] || i == out[1]) {  
                    continue;
                }
                nset.push_back(nums[i]);
            }
            //cout << "Size " << nset.size() << endl;
            vector<int> dout;
            pickTwo(dout,nset,0,found);
            }
            return;
        }            
        if(start == nums.size()) return;
        pickTwo(out,nums,start+1,found);
        out.emplace_back(start);
        pickTwo(out,nums,start+1,found);
        out.pop_back();        
    }
};