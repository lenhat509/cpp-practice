/*
My appoarch is to store the numbers and corresponding words in a hash map. It allows optimal insertion and quick lookup.
Then I determine the last number at line i following the formula: number = i(i+1)/2.
Finally, the code loops through the ending numbers that are less then the size of the hash map and append the corresponding words to the result string.
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
using namespace std;

string decode(ifstream &file);

int main()
{
    ifstream file;
    file.open("coding_qual_input.txt");
    cout << decode(file);
}

string decode(ifstream &file)
{
    unordered_map<int, string> map;
    while (!file.eof())
    {
        string line;
        stringstream linestream;
        getline(file, line);
        linestream << line;
        int num;
        string word;
        linestream >> num >> word;
        map.insert({num, word});
    }
    file.close();
    // find the numbers at the end of each line
    int lineEnd = 1;
    int line = 1;
    string result;
    while (lineEnd <= map.size())
    {
        result.append(map[lineEnd]);
        line++;
        lineEnd = line * (line + 1) / 2;
        if (lineEnd <= map.size())
            result.push_back(' ');
    }
    return result;
}