#include <iostream>
using namespace std;

class node // creating node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class queue // creating queue
{
public:
    node *front;
    node *back;

    queue()
    {
        front = back = NULL;
    }

    void enqueue(int x) // insertion of element i.e insertion at tail
    {
        node *n = new node(x);

        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = n;
    }
    void dequeue() // deletion of element i.e at head
    {
        if (front == NULL)
        {
            cout << "queue is empty!" << endl;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }
    int peek() // prints the top element,i.e,the element present at front
    {
        if (front == NULL)
        {
            cout << "stak is empty!" << endl;
            return -1;
        }

        return front->data;
    }
    void display()
    { // displays element int the queue
        node *temp = front;
        if (front == NULL)
        {
            cout << "Queue is empty!" << endl;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    queue q;

    int ch, val;

    cout << "Enter the option to be performed: \n1.Insert element \n2.Delete element\n3.Display stack\n4.showtop\n5.Exit " << endl; // switch statement for menu
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to enqueue" << endl;
            cin >> val;
            q.enqueue(val);
            break;
        }
        case 2:
        {
            q.dequeue();
            break;
        }
        case 3:
        {
            q.display();
            break;
        }
        case 4:
        {
            q.peek();
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