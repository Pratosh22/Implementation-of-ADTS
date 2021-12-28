#include <iostream>
using namespace std;

class node // declare node of linked list
{
public:
    int data;
    node *next;
};

node *top = NULL;

bool isempty() // checks if stack is empty
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int x) // insert at beginning of stack i.e insertion at head
{
    node *n = new node();
    n->data = x;
    n->next = top;
    top = n;
}
void pop() // deletion of top element of stack
{
    if (top == NULL)
    {
        cout << "Stack is empty!" << endl;
    }
    node *todelete = top;
    top = top->next;
    delete todelete;
}
void display() // Displays the elements present in the stack
{
    if (isempty())
    {
        cout << "Stack is empty!" << endl;
    }

    node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void peek() // prints the peek element(top)
{
    if (isempty())
    {
        cout << "Stack is empty!" << endl;
    }
    cout << "The element at top: " << top->data << endl;
}

int main()
{
    int ch, val;

    cout << "Enter the option to be performed: \n1.Insert element \n2.Pop from stack\n3.Display stack\n4.showtop\n5.Exit " << endl;  //switch statement for menu
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
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            cout << "Exit " << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } while (ch != 5);
    return 0;
}
