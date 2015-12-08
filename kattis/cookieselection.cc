#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int d;
    priority_queue<int> max_heap;
    // this changes the default max heap behaviour to a min heap
    priority_queue<int, vector<int>, greater<int> > min_heap;

    // i imagine this problem like two cones pointing at each other:
    //
    // the min element in this cone sinks down to the bottom
    // min heap
    //   \ /
    //    V    <- you want to make sure there is always an element here,
    //            since whatever element is here is the median
    //    ^
    //   / \
    // max heap
    // the max element in this cone bubbles up to the top

    while (cin >> s)
    {
        if (s == "#")
        {
            // get the median cookie, which should always be at the
            // top of your min heap
            cout << min_heap.top() << endl;
            min_heap.pop();
        }
        else
        {
            // convert to an int
            d = stoi(s);

            // if your min heap (and so the 'median spot') is empty,
            // or this d is larger than the min element in your min heap,
            // this belongs in the min heap
            if (min_heap.empty() || d > min_heap.top())
            {
                min_heap.push(d);
            }
            // otherwise, it's less than or equal, so we can put it
            // in the bottom cone
            else
            {
                max_heap.push(d);
            }
        }

        // let's make sure the median element is at the top of the min heap
        if (max_heap.size() > min_heap.size())
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        if (min_heap.size() > max_heap.size() + 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
}
