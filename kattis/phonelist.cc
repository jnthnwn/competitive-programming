#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        // eat your input
        cin >> n;
        vector<string> numbers(n);

        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        // get the numbers sorted into lexicographic order (as strings!)
        // C++'s sort does this by default
        sort(numbers.begin(), numbers.end());

        // assume all numbers are valid until they aren't
        bool okay = true;
        for (int i = 0; i < n-1; i++)
        {
            string str1 = numbers[i];
            string str2 = numbers[i+1];
            // check first that str1 is smaller than str2
            // since all numbers are unique, it's the only way you'll have
            // str1 be a prefix of str2
            if (str1.length() < str2.length())
            {
                // now you can just compare the strings up to
                // the length of str1 and see if you've got a match
                string substr2 = str2.substr(0,str1.length());
                if (!str1.compare(substr2))
                {
                    okay = false;
                    break;
                }
            }
        }

        if (okay)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
