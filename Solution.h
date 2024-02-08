#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <unordered_map>

class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> charMap;
        countChars(s, charMap);

        std::vector<std::pair<char, int>> charList;
        for (auto pair : charMap) {
            charList.push_back(pair);
        }

        sort(charList.begin(), charList.end(), compare);

        std::string answer = "";
        for (auto pair : charList) {
            for (int i = 0; i < pair.second; i++) {
                answer.push_back(pair.first);
            }
        }
        return answer;
    }

    void countChars(std::string& s, std::unordered_map<char, int>& charMap) {
        for (char ch : s) {
            if (charMap.find(ch) == charMap.end()) charMap.insert({ch, 1});
            else charMap[ch]++;
        }
    }

    static bool compare(std::pair<char, int>& pair1, std::pair<char, int>& pair2) {
        return pair1.second > pair2.second;
    }
};


#endif
