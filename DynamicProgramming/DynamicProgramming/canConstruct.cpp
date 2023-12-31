#include "canConstruct.hpp"

bool canConstructHelper(std::string& construct, std::vector<std::string>& words, std::string replicate, std::unordered_map<std::string, bool>& hashmap) {
	if (replicate == construct) { return true; }
	else if (replicate.size() > construct.size()) { return false; }
	else if (hashmap.count(replicate) > 0) return hashmap[replicate];
	for (std::string word : words) {
		if (canConstructHelper(construct, words, replicate + word, hashmap)) {
			return true;
		}
	}
	hashmap[replicate] = false;
	return false;
}

bool canConstructHelperv2(std::string& construct, std::vector<std::string>& words, std::string replicate, std::unordered_map<std::string, bool>& hashmap) {
	//THIS ONE IS BETTER, NOT CHECKING USELESS PREFIXES (AT LEAST FOR BIGGER TARGETS)
	if (replicate == construct) { return true; }
	else if (replicate.size() > construct.size()) { return false; }
	else if (hashmap.count(replicate) > 0) return hashmap[replicate];
	std::string new_replicate;
	for (std::string word : words) {
		new_replicate = replicate + word;//INSTEAD OF THIS YOU CAN JUST USE STD::FIND, TO CHECK, REDUCE THE STRING WITH SUBSTRING
		if (new_replicate == construct.substr(0, new_replicate.size()) && canConstructHelper(construct, words, new_replicate, hashmap)) {
			return true;
		}
	}
	hashmap[replicate] = false;
	return false;
}

bool canConstruct(std::string construct, std::vector<std::string> words, std::string replicate) {
	std::unordered_map<std::string, bool> hashmap;
	return canConstructHelperv2(construct, words, replicate, hashmap);
}

bool canConstructTab(std::string construct, std::vector<std::string> words) {
	//Done on my own :)
	std::vector < bool > dp(construct.size() + 1, false);
	dp[0] = true;

	for (int i = 1; i < dp.size(); i++) {
		for (std::string& word : words) {
			//std::string copy{ construct };
			if (i >= word.size()) {
				dp[i] = (word== construct.substr(i-word.size(), word.size()) && dp[i - word.size()])||dp[i] ;
			}
		}
	}


	return dp.back();
}

bool canConstructTab2(std::string construct, std::vector<std::string> words) {
	//Teacher version in js logic
	std::vector < bool > dp(construct.size() + 1, false);
	dp[0] = true;

	for (int i = 0; i < dp.size(); i++) {
		if (dp[i]) {
			for (std::string& word : words) {
				//std::string copy{ construct };
				if (dp.size() > i+word.size() && (word == construct.substr(i, word.size()))) {
					dp[i+word.size()] =  true;//To avoid the or for assignment?? It it really that faster to avoid assignments in general?
				}
			}
		}
	}


	return dp.back();
}
