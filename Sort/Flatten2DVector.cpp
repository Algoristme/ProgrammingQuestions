Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6]

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        listIt = vec2d.begin();
        listItEnd = vec2d.end();
        if(listIt != listItEnd) {
            it = listIt->begin();
          while(it == listIt->end() && listIt!=listItEnd){
              ++listIt;
              it = listIt->begin();
          }
          //listIt = listItEnd;            
        }            
    }

    int next() {                
        if(it != listIt->end()) {}
        else {
            ++listIt;
            it = listIt->begin();            
        }
        //cout << " Returning " << *it << endl;
        int ret = *it;
        it++;        
        while(it == listIt->end()  && listIt!=listItEnd) {  
            ++listIt;            
            if(listIt != listItEnd ) {
                it = listIt->begin();                            
            }
            else {
                //cout << "Both are null" << endl;
                listIt = listItEnd;                
            }              
        }
        return ret;
    }

    bool hasNext() {
        auto tmpIt = it;
        auto tmpListIt = listIt;
        if(tmpListIt == listItEnd) {
            return false;
        }
        //cout << " Has Next " << false << endl;
        return true;
    }
    
    vector<vector<int>>::iterator listIt;
    vector<vector<int>>::iterator listItEnd;
    vector<int>::iterator it;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */