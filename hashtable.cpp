#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* next;
};

class HashTable
{
private:
    Node* table[10];

public:
    HashTable()
	{
        for (int i = 0; i < 10; i++)
		{
            table[i] = NULL;
        }
    }

    int hashFunction(int key)
	{
        return key % 10;
    }

void insert(int key)
    {
        int index = hashFunction(key);
        Node* newNode = new Node();
        newNode->key = key;
        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() 
	{
        for (int i = 0; i < 10; i++)
		{
            cout << "Bucket " << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << temp->key << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    ht.display();
    return 0;
}




