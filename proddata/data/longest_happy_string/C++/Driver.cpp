#include <algorithm>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

#include "Solution.hpp"

using namespace std;

int main()
{
    int numInputs = 0;
    int target = 0;
    string input1;
    string expected_output;
    string actual_output;
    ifstream infile("../testcases.txt");
    Solution *obj = new Solution();
    string line;
    int lineNo = 0;
    while (getline(infile, line))
    {
        for (int i = 0, len = line.size(); i < len; i++)
        {
            if (ispunct(line[i]))
            {
                line.erase(i--, 1);
                len = line.size();
            }
        }
        if (lineNo == 0)
        {
            lineNo += 1;
            continue;
        }
        if ((lineNo % 2) != 0)
        {
            input1 = line;

            string s = line;
            stringstream ss(s);
            istream_iterator<int> begin(ss);
            istream_iterator<int> end;
            vector<int> input(begin, end);
            string res = obj->longestDiverseString(input[0], input[1], input[2]);
            actual_output = res;
        }
        else
        {
            expected_output = line;
            sort(expected_output.begin(), expected_output.end());
            sort(actual_output.begin(), actual_output.end());
            if (expected_output != actual_output)
            {
                cout << "Result: Failed" << endl;
                cout << "Input: " << input1 << endl;
                cout << "Expected Output: " << expected_output << endl;
                cout << "Actual Output: " << actual_output << endl;
                return 0;
            }
        }
        lineNo += 1;
    }
    cout << "Result: Success" << endl;
    return 0;
}