#include "countConstruct.hpp"
unsigned int countConstructHelper(std::string& construct, std::vector<std::string>& words, std::string replicate, std::map<std::string, int>& hashmap) {
	if (replicate == construct) { return 1; }
	else if (replicate.size() > construct.size()) { return 0; }
	else if (hashmap.count(replicate) > 0) return hashmap[replicate];
	std::string new_replicate;
	int count{};
	for (std::string word : words) {
		new_replicate = replicate + word;//INSTEAD OF THIS YOU CAN JUST USE STD::FIND, TO CHECK, REDUCE THE STRING WITH SUBSTRING
		if (new_replicate == construct.substr(0, new_replicate.size())) {
			count += countConstructHelper(construct, words, new_replicate, hashmap);
		}
	}
	hashmap[replicate] = count;
	return hashmap[replicate];
}
unsigned int countConstruct(std::string construct, std::vector<std::string> words, std::string replicate) {
	std::map<std::string, int> hashmap;
	//int mod = static_cast<int>(pow(10, 9) + 7);
	return (countConstructHelper(construct, words, replicate, hashmap));
}

int countConstructTab(std::string construct, std::vector<std::string> words) {
	//Did it myself too :)
	std::vector<int> dp(construct.size() + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < dp.size(); i++) {
		for (std::string& word : words) {
			if (i + word.size() < dp.size() && word == construct.substr(i, word.size())) {
				dp[i + word.size()] += dp[i];
			}
		}
	}
	return dp.back();
}
