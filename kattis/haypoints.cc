#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, val;
    string word;
    cin >> m >> n;
    // maps a word to a hay point value
    map<string, int> dict;
    while (m--)
    {
        // simply reading input and inserting it into our dictionary
        cin >> word >> val;
        dict.insert( pair<string, int>(word, val) );
    }
    while (n--)
    {
        int total = 0;
        // keep reading words until that word is a period by itself
        // for each word, add its value to the total
        while (cin >> word && word.compare(".") != 0)
        {
            total += dict[word];
        }
        cout << total << endl;
    }
}
