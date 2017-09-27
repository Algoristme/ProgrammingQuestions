//Given two 1d vectors, implement an iterator to return their elements alternately.

//For example, given two 1d vectors:

//v1 = [1, 2]
//v2 = [3, 4, 5, 6]

//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

//Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

//Clarification for the follow up question - Update (2015-09-18):
//The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

//[1,2,3]
//[4,5,6,7]
//[8,9]

//It should return [1,4,8,2,5,9,3,6,7]. 


class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v.resize(2);
        v[0] = v1;
        v[1] = v2;
        
        vIt.resize(2);
        vIt[0] = v[0].begin();
        vIt[1] = v[1].begin();
        
        curr = 0;
    }

    int next() {
        int res;
        if(hasNext()) {
            res = *(vIt[curr]);
            ++vIt[curr];
            curr = (curr+1)%v.size();            
        }
        return res;
    }

    bool hasNext() {
        int i = 0;
        while( i < v.size()) {
            if(vIt[curr] != v[curr].end()){
                return true;
            }
            curr = (curr+1)%v.size();
            ++i;
        }
        return false;
    }
    vector<vector<int>> v;
    vector<vector<int>::iterator> vIt;
    int curr;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */