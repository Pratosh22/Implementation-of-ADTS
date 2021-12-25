#include <iostream>
using namespace std;
class stack  
{
    int *arr;
    int next_index;
    int capacity;

public:
    stack()   //stack capacity by default
    {
        capacity = 4;
        arr = new int[capacity];
        next_index = 0;
    }
    stack(int cap)  //stack capacity assigned by user
    {
        capacity = cap;
        arr = new int[capacity];
        next_index = 0;
    }
    int size()
    {
        return next_index;
    }
    bool isEmpty()   //checks if stack is empty
    {
        if (next_index == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int element)   //inserts element at top
    {
        if (next_index == capacity)
        {
            cout << "Stack full " << endl;
            return;
        }
        arr[next_index] = element;
        next_index++;
    }
    void pop()   //deletes element from top
    {
        if (next_index == 0)
        {
            cout << "Stack empty " << endl;
        }
        else
        {
            cout << "Deleted Item is: " << arr[next_index - 1] << endl;
            next_index--;
        }
    }
    int peek()  //top value is printed
    {
        if (isEmpty())
        {
            cout << "stack is empty " << endl;
            return -1;
        }
        return arr[next_index - 1];
    }
};
int main()
{   int n;
    cout<<"Enter the size of stack: "<<endl; 
    cin>>n;
    stack s(n);
    int ch, val;
    cout << "Enter the option to be performed: \n1.Insert element \n2.Pop from stack\n3.showtop\n4.Exit " << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            s.push(val);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }

        case 3:
        {
            s.peek();
            break;
        }
        case 4:
        {
            cout << "Exit " << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }

    } while (ch != 4);
    return 0;
}
