#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the 'getMaximumPower' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY power as parameter.
 */

bool compare(int i, int j) {
    return i < j;
}

long getMaximumPower(vector<int> power) {
    unordered_map<int, int> occurrences = {};
    for(int p: power) {
        if(occurrences.count(p))
            occurrences[p]++;
        else occurrences.insert({p, 1});
    }

    vector<int> elements;
    for(auto p: occurrences) {
        elements.push_back(p.first);
    }

    sort(elements.begin(), elements.end(), compare);

    for(int i: elements)
        cout << i << ":" << occurrences[i] << " ";
    cout << endl;

    vector<int> sums = {elements[0]*occurrences[elements[0]]};

    for(int i = 1; i < elements.size(); i++) {
        if(elements[i] == elements[i - 1] + 1) {
            int latestSum = sums[i - 1];
            int secondLatestSum = i >= 2? sums[i - 2]: 0;
            int newSum = secondLatestSum + elements[i] * occurrences[elements[i]];
            cout << "current sum: "<< latestSum << ", new sum: " << newSum << endl;
            sums.push_back(max(newSum, latestSum));
        }
        else sums.push_back(sums[i-1] + elements[i] * occurrences[elements[i]]);
    }

    for(int i: sums)
        cout << i << " ";
    cout << endl;

    return sums[sums.size() - 1];
}

int main() {
    vector<int> list = {1,1,1,2,3,3,4,5,5,5,5};
    cout << getMaximumPower(list) << endl;
    return 0;
}