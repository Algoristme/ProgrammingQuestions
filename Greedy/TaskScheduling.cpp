// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish all the given tasks.

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

// Note:

//     The number of tasks is in the range [1, 10000].

// Challenge, if you have less tasks, u have to idle and pick the current task....that is finish one cycle before going to the next..
// i could not think of it.


// My solution for that question: My solution: 358. Rearrange String k Distance Apart

//     We use map to count the frequencies of each chars in our vector, and use priority queue to sort our pairs according to the chars' frequencies.

//     For this problem, we use the greedy algorithm. That means when we choose one char, we always try to use the char with the largest frequency among the remaining chars. By this step, we can use the least steps to satisfy the requirements.

//     While the priority queue is not empty, we choose the top element from the queue, because the distance between two same chars must be n, so we will go to our queue to find out n different chars.

//     (a) If there is n different types of chars in our queue, of course, that's perfect, we can deduce 1 from their frequency and then push it into our cache vector if its frequency is not 0.
//     (The cache vector will store the pairs from the queue, and then after one round search, we will push the elements in this vector to our priority queue.)

//     (b) If there is less n different chars in the queue, then we will use idle. This step is easy.

//     So when shall we stop our loop? 1. When the priority queue is empty after one round search. 2. When all of the elements are used up, that's why we use len in our loop as a counter for the number of remaining elements.


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<char> schedule;
        unordered_map<char,int> cntMap;
        priority_queue<pair<int,char>> pq;
        
        for(auto ch : tasks) {
            cntMap[ch]++;
        }
        
        for(auto p : cntMap) {
            pq.emplace(p.second,p.first);
        }
        int res =0 , len = tasks.size();
        while(!pq.empty()) {
            vector<pair<int,char>> waitingQ;
            // The whole purpose of this for loop is to
            // finish one cycle of scheduling. We could idle
            // or not idle, but by the end of this for loop
            // one round of scheduling is done. Every task instance
            // decreases by 1.
            // Eg Scheduling A A A B B after the for loop
            // reduces to scheduling A A B
            for(int i = 0 ; i <= n; ++i) {
                if(!len) return res;
                if(!pq.empty()) {
                    ++res;
                    --len;
                    auto curr = pq.top();
                    pq.pop();
                    if(--curr.first > 0) {
                        waitingQ.push_back(curr);
                    }
                }
                else {
                    ++res;
                }
            }
            // Prepare for the second round of scheduling.
            for(auto p : waitingQ) {
                pq.push(p);
            }            
        }
        return res;
    }
};