#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

static bool compVectorOfSetsFirstElement(set<string>& a, set<string>& b) {
    return *a.begin() < *b.begin();
}

int main()
{
    int const maxLetters = 30;
    int n;
    vector<string> words[maxLetters];
    map<string, string> wordsMap[maxLetters];
    multimap<string, string> wordsMultimap[maxLetters];
    vector<set<string>> groups;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        words[word.length() - 1].push_back(word);
    }

    for (int i = 0; i < maxLetters; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            string word = words[i][j];
            sort(word.begin(), word.end());
            wordsMap[i][words[i][j]] = word;
            wordsMultimap[i].insert(pair<string, string>(word, words[i][j]));
        }
    }
    //cout << endl;

    /*for (int i = 0; i < maxLetters; i++) {
        for (auto j = wordsMap[i].begin(); j != wordsMap[i].end(); j++) {
            cout << j->first << " -> " << j->second << endl;
        }
    }
    cout << endl;*/

    for (int i = 0; i < maxLetters; i++) {
        set<string> group;

        if (wordsMultimap[i].size() >= 1) {
            group.insert(wordsMultimap[i].begin()->second);
        }

        if (wordsMultimap[i].size() > 1) {
            auto lastWordIterator = wordsMultimap[i].begin();

            for (auto j = next(wordsMultimap[i].begin()); j != wordsMultimap[i].end(); j++) {
                if (lastWordIterator->first == j->first) {
                    //cout << lastWordIterator->first << " ~= " << lastWordIterator->second << ", " << j->second << endl;
                    group.insert(j->second);
                    group.insert(lastWordIterator->second);
                }
                else {
                    groups.push_back(group);
                    group.clear();

                    /*if (wordsMultimap[i].size() >= 1) {
                        group.insert(wordsMultimap[i].begin()->second);
                    }*/
                }
                lastWordIterator = j;
            }
        }

        if (wordsMultimap[i].size() >= 1) {
            groups.push_back(group);
        }
    }
    //cout << endl;

    /*for (auto j = groups.begin(); j != groups.end(); j++) {
        for (auto k = j->begin(); k != j->end(); k++) {
            cout << *k << " ";
        }
        cout << endl;
    }
    cout << endl;*/

    sort(groups.begin(), groups.end(), compVectorOfSetsFirstElement);

    for (auto j = groups.begin(); j != groups.end(); j++) {
        for (auto k = j->begin(); k != j->end(); k++) {
            cout << *k << " ";
        }
        cout << endl;
    }
}

/*
10
liszka
tuba
tuba
klisza
kretes
anakonda
sekret
szalik
buta
tabu
*/