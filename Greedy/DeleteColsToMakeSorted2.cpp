// Delete columns to make sorted - 2
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        unordered_set<int> deleted;
        for(int word = 0; word < A.size()-1; ++word) {
            for (int index = 0; index < A[0].size() ; ++index) {
                // if this column is deleted, or if the chars are equal, keep comparing to find who is first.
                if(deleted.find(index) != deleted.end() || A[word][index] == A[word+1][index]) continue;
                // if this char in word[i] > word[j] delete this,
                // deleting this has a side effect, in the previous line we skipped chars that were equal
                // deleting this column might mean that we are breaking the lexicograph order of the previous
                // ones.
                // Eg w1.... x _b_ d...
                //    w2.... x _c_ a...
                //    w3.... x  a 
                // In the code we break when we see _b_ & _c_ for w1 and w2 we break and compare w2 and w3
                // We see that for w2 and w3 c > a thus we mark this column for deletion
                // But hey, if we delete this column, w1 and w2 are not lexicographic either...
                // After deletion
                // w1 ...xd...
                // w2 ...xa...
                // Oops! We need to start things from scratch again!
                
                if(A[word][index] > A[word+1][index]) {
                    deleted.insert(index);
                    word = -1;
                }
                // if word[i][col] < word[i][col] go the next word.
                break;
            }
        }
        return deleted.size();
    }
};