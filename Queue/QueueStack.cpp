//queue using stack with costly enqueue method
//Stack STL is included
#include <iostream>
#include <stack>
using namespace std;

class queue   //two stacks are created
{
    stack<int> s1;
    stack<int> s2;

public:
    void enqueue(int x) //enqueue the element to the queue
    {
        s1.push(x);  //pushes the element to first stack
    }
    int dequeue()
    {
        while (s1.empty() && s2.empty())   //if both stacks are empty
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        if (s2.empty())   //if s2 is empty move elements from s1
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();  
        s2.pop();
        return topval;  //returns the top value of stack2
    }
    bool isEmpty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
 
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
 
    return 0;
}
