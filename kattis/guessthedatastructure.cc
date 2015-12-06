#include <bits/stdc++.h>
using namespace std;

// the main idea is just simulate each data structure
int main()
{
    int n, command, val;
    while (scanf("%d", &n) != EOF)
    {
        stack<int> my_stack;
        queue<int> my_queue;
        priority_queue<int> my_pqueue;
        bool stack_ok = true;
        bool queue_ok = true;
        bool pqueue_ok = true;

        while (n--)
        {
            scanf("%d %d", &command, &val);
            // insert the element
            if (command == 1)
            {
                my_stack.push(val);
                my_queue.push(val);
                my_pqueue.push(val);
            }
            // see if the element is the same as the one
            // removed from each data structure
            else
            {
                // check that there are elements to take out
                // or else the data structure should be impossible
                if (stack_ok)
                    if (my_stack.size() > 0 && my_stack.top() == val)
                        my_stack.pop();
                    else
                        stack_ok = false;
                if (queue_ok)
                    if (my_queue.size() > 0 && my_queue.front() == val)
                        my_queue.pop();
                    else
                        queue_ok = false;
                if (pqueue_ok)
                    if (my_pqueue.size() > 0 && my_pqueue.top() == val)
                        my_pqueue.pop();
                    else
                        pqueue_ok = false;
            }
        }

        // basically see if you get 0, 1 or many data structures
        // that pass the above simulation
        // print out the appropriate message
        if (stack_ok || queue_ok || pqueue_ok)
        {
            if (stack_ok)
            {
                if (queue_ok || pqueue_ok)
                    printf("not sure\n");
                else
                    printf("stack\n");
            }
            else
            {
                if (queue_ok)
                    if (pqueue_ok)
                        printf("not sure\n");
                    else
                        printf("queue\n");
                else
                    printf("priority queue\n");
            }
        }
        else
        {
            printf("impossible\n");
        }
    }
}
