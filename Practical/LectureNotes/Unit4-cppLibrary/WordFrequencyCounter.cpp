#include <iostream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main() {
    string paragraph;
    getline(cin, paragraph);
    stringstream ss(paragraph);
    set<string> uniqueWords;
    map<string, int> wordCount;
    string word;
    while (ss >> word) {
        auto it = word.begin();
        while (it != word.end()) {
            if (!isalpha(*it)) {
                word.erase(it);
            } else it++;
        }
        // as we want unique words we insert in set
        uniqueWords.insert(word);
        wordCount[word]++;
    }


}