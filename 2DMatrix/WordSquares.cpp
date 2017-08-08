//Word Squares
//Given a set of words(without duplicates), find all word squares you can build from them.
//
//A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
//
//	For example, the word sequence["ball", "area", "lead", "lady"] forms a word square because each word reads the same both horizontally and vertically.
//
//	b a l l
//	a r e a
//	l e a d
//	l a d y
//
//	Note :
//
//There are at least 1 and at most 1000 words.
//All words will have the exact same length.
//Word length is at least 1 and at most 5.
//Each word contains only lowercase English alphabet a - z.
//
//Example 1:
//
//Input:
//["area", "lead", "wall", "lady", "ball"]
//
//Output :
//	[
//		["wall",
//		"area",
//		"lead",
//		"lady"
//		],
//	["ball",
//	"area",
//	"lead",
//	"lady"
//	]
//	]
//
//	   Explanation:
//				  The output consists of two word squares.The order of output does not matter(just the order of words in each word square matters).
//
//					  Example 2 :
//
//					  Input :
//					  ["abat", "baba", "atan", "atal"]
//
//				  Output :
//					  [
//						  ["baba",
//						  "abat",
//						  "baba",
//						  "atan"
//						  ],
//					  ["baba",
//					  "abat",
//					  "baba",
//					  "atal"
//					  ]
//					  ]
//
//						 Explanation:
//									The output consists of two word squares.The order of output does not matter(just the order of words in each word square matters).
//
//										Seen this question in a real interview before ?
//
//										Difficulty : Hard
//										Total Accepted : 8.7K
//										Total Submissions : 20.6K
//										Contributor : LeetCode
//										Companies
//
//
//										Related Topics
//
//
//										Similar Questions
//										Valid Word Square
//

class Solution {
public:
	vector<vector<string>> wordSquares(vector<string>& words) {
		unordered_map<string, vector<string>> prefixMap;
		// build prefix map   
		for (auto word : words) {
			buildPrefixMap(word, prefixMap);
		}

		vector<vector<string>> out;
		unordered_set<string> visited;
		for (auto word : words) {
			vector<string> squareGrid;
			// put this word as the first string in row.            
			// build square matrix from here...            
			auto it = visited.emplace(word);
			//cout << word << endl;
			if (!it.second) {
				// this word has already been tried as the first candidate.
				//cout << "Found!" << endl;
				continue;
			}
			squareGrid.push_back(word);
			canBuildSquareMatrix(1, prefixMap, squareGrid, out);
		}
		return out;

	}
	void buildPrefixMap(string str, unordered_map<string, vector<string>> &prefixMap) {
		string prefix = "";
		// prefix map has to be built for one less than the string length.
		// This is because consider the case where the string is are
		// if the map looks like below
		// a - are
		// ar - are
		// are - are
		// when we search for prefix are, we find a candidate, so even after completing the grid we substitute are with are
		// this gives duplicates in the output.
		for (int i = 0; i < str.size() - 1; ++i) {
			prefix += str[i];
			prefixMap[prefix].push_back(str);
		}
	}

	void canBuildSquareMatrix(int start, unordered_map<string, vector<string>> &prefixMap, vector<string> grid, vector<vector<string>>                                                                                                                                          &out) {
		string prefix = "";
		if (grid[0].size() == grid.size()) {
			out.push_back(grid);
			//cout << "pushing out " << endl;
		}
		// This additional for loop caused all the pain. Why ?
		// 
		//for(int i = start ; i < grid[0].size(); ++i) {
		for (int row = 0; row < grid.size(); ++row) {
			prefix = prefix + grid[row][start];
		}
		//}
		auto candidates = prefixMap[prefix];
		// can't build square matrix with this combination.
		if (candidates.size() == 0) {
			return;
		}
		for (auto eachCandidate : candidates) {
			grid.push_back(eachCandidate);
			//++start; Why having this does not work ? 
			// reason after finishing the call below, we want to restore the state
			// so that we can pick the next candidate and then compute the prefix
			// doing a post increment disturbs the state.
			canBuildSquareMatrix(start + 1, prefixMap, grid, out);
			// undo the last change.            
			grid.resize(grid.size() - 1);
		}
		//}                      
	}
};