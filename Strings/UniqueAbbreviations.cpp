//288. Unique Word Abbreviation
//An abbreviation of a word follows the form <first letter><number><last letter>.Below are some examples of word abbreviations :
//
//a) it--> it(no abbreviation)
//
//1
//b) d | o | g--> d1g
//
//1    1  1
//1-- - 5----0----5--8
//c) i | nternationalizatio | n--> i18n
//
//1
//1-- - 5----0
//d) l | ocalizatio | n--> l10n
//
//Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
//Example:
//
//Given dictionary = ["deer", "door", "cake", "card"]
//
//isUnique("dear") ->
//false
//
//isUnique("cart") ->
//true
//
//isUnique("cane") ->
//false
//
//isUnique("make") ->
//true



class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> dictionary) {
		for (auto word : dictionary) {
			auto it = dict.emplace(word);
			if (it.second)
				populateAbbrs(word);

		}
	}
	// Interesting cases that I ought to have thought:
	// 1. Does the dictionary have dups?
	// 2. Will isUnique be called for words in dict?

	// Can be done with only one hashmap
	// Use hashmap with key as abbrv and value as the word.
	// if two words have the same key and if the words are different
	// invalidate the abbr by making the value ""
	// When checking for unique, compute the abbr and search in the map
	// if the value is current word then return true else return false
	bool isUnique(string word) {
		//populateAbbrs(word);
		if (abbr[computeAbbr(word)] == 0 || (abbr[computeAbbr(word)] == 1 && dict.find(word) != dict.end())) {
			return true;
		}
		return false;
	}
	string computeAbbr(string &word) {
		if (word.size() <= 2) {
			return word;
		}
		int num = word.size() - 2;
		string res = word[0] + to_string(num) + word[word.size() - 1];
		return res;
	}
	void populateAbbrs(string word) {
		string str = computeAbbr(word);
		++abbr[str];
		//cout << word << " " << str << " " << abbr[str] << endl;
	}
	// will contain all the unique abbreviations from the set.
	unordered_map<string, int> abbr;
	unordered_set<string> dict;
};

/**
* Your ValidWordAbbr object will be instantiated and called as such:
* ValidWordAbbr obj = new ValidWordAbbr(dictionary);
* bool param_1 = obj.isUnique(word);
*/