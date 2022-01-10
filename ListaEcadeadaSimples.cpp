#include <iostream>

using namespace std;

class Node
{
    private:
        int value;
        Node* next;

    public:
        Node(int value)
        {
            this->value = value;
            this->next = nullptr;
        }

        int getValue()
        {
            return value;
        }

        Node* getNext()
        {
            return next;
        }

        void setNext(Node* n)
        {
            next = n;
        }
};

class LinkedList
{
    private:
        Node* head;
        Node* last;

    public:
        LinkedList()
        {
            head = nullptr;
            last = nullptr;
        }

        LinkedList(int value)
        {
            head = new Node(value);
            last = head;
        }

        virtual ~LinkedList()
        {
            delete head;
        }

        bool empty()
        {
            return (head == nullptr);
        }

        void printList()
        {
            cout << "Printing all elements... \n";
            Node* h = head;
            if(empty())
                cout << "The Linked list has no elements!!\n";
            else
            {
                while(h)
                {
                    cout << h->getValue() << " -> ";
                    h = h->getNext();
                }
                cout << "\n";
            }
        }

        void insertFirst(int value)
        {
            Node* new_node = new Node(value);
            if(empty())
            {
                head = new_node;
                last = new_node;
            }
            else
            {
                new_node->setNext(head);
                head = new_node;
            }
        }

        void insertLast(int value)
        {
            Node* new_node = new Node(value);
            if(empty())
            {
                head = new_node;
                last = new_node;
            }
            else
            {
                last->setNext(new_node);
                last = new_node;
 
            }
        }

        int size()
        {
            if(empty())
            {
                return 0;
            }
            else
            {
                Node* h = head;
                int size = 0;
                do
                {
                    h = h->getNext();
                    ++size;
                }
                while(h);      
            }
        }

        bool isPresent(int value)
        {
            Node* h = head;
            while(h)
            {
                if(h->getValue() == value)
                    return true;
                h = h->getNext();
            }

            return false;
        }

        void removeLast()
        {
            if(!empty())
            {
                //only 1 element
                if(head->getNext() == nullptr)
                {
                    //removes the 1 element
                    head = nullptr;
                }
                // more than 1 element
                else
                {
                    Node* previous = head;
                    Node* aux = head->getNext();
                    while (aux->getNext() != nullptr)
                    {
                        previous = aux;
                        aux = aux->getNext();
                    }
                    delete aux;
                    previous->setNext(nullptr);
                    last = previous;
                }
            }
        }
};

int main()
{
    LinkedList ll;

    if(ll.empty())
        cout << "Empty Linked list!!\n";
    else
        cout << "Linked list NOT empty!\n";

    ll.printList();

    cout << "List size: " << ll.size() << endl;

    if(!ll.isPresent(10))
        cout << "Element '10' is NOT present on the linked list!\n";
    else
        cout << "Element '10' is present on the linked list!\n";
    
    cout << "inserting 10....\n\n";

    ll.insertFirst(10);

    if(ll.empty())
        cout << "Empty Linked list!!\n";
    else
        cout << "Linked list NOT empty!\n";

    ll.printList();
    cout << "List size: " << ll.size() << endl;

    if(!ll.isPresent(10))
        cout << "Element '10' is NOT present on the linked list!\n";
    else
        cout << "Element '10' is present on the linked list!\n";
    
    cout << "inserting 20 and 30....\n\n";

    ll.insertFirst(20);
    ll.insertLast(30);
    if(!ll.isPresent(30))
        cout << "Element '30' is NOT present on the linked list!\n";
    else
        cout << "Element '30' is present on the linked list!\n";
    ll.printList();
    cout << "List size: " << ll.size() << endl;
    cout << "removing 30....\n\n";
    ll.removeLast();
    if (!ll.isPresent(30))
        cout << "Element '30' is NOT present on the linked list!\n";
    else
        cout << "Element '30' is present on the linked list!\n";
    ll.printList();
    cout << "List size: " << ll.size() << endl;

    return 0;
}