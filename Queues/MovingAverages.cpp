//346. Moving Average from Data Stream
//
//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
//For example,
//
//MovingAverage m = new MovingAverage(3);
//m.next(1) = 1
//m.next(10) = (1 + 10) / 2
//m.next(3) = (1 + 10 + 3) / 3
//m.next(5) = (10 + 3 + 5) / 3

class MovingAverage {
public:
	/** Initialize your data structure here. */
	// Approach the problem such that you have a q 
	// Size of queue is constant and it stores the sum
	// until that point.
	MovingAverage(int size) : winSize(size) {
		sumSoFar = 0;
	}

	double next(int val) {
		sumSoFar += val;
		if (window.size() >= winSize) {
			sumSoFar -= window.front();
			window.pop();
		}
		window.emplace(val);
		return (1.0 * sumSoFar) / window.size();
	}

private:
	queue<int> window;
	int winSize;
	int sumSoFar;
};

/**
* Your MovingAverage object will be instantiated and called as such:
* MovingAverage obj = new MovingAverage(size);
* double param_1 = obj.next(val);
*/