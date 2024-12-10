#include<iostream>

using namespace std;

class HashTable
{
    int size;
    int *arr;

    public:
    HashTable(int table_size)
    {
        size = table_size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = -1;
    }

    int hash_function(int keys)
    {
        return keys % size;
    }

    void insertion(int key)
    {
        int index = hash_function(key);

    // Linear probing to find the next available slot
    while (arr[index] != -1)
    {
        index = (index + 1) % size; // Move to the next slot and wrap around if necessary
        if (index == hash_function(key)) // If we loop back to the start, the table is full
        {
            cout << "The hash table is full" << endl;
            return;
        }
    }

    arr[index] = key; 
    }

    int searching(int key)
    {
        // Search for the value
        if (arr[hash_function(key)] == -1)
        {
            cout << "The value is not present in the hash" << endl;
            return 0;
        }

        if (arr[hash_function(key)] == key)
        {
            cout << "The value is present in the hash" << endl;
            return 1;
        }

        // Circular linear search
        int index = hash_function(key);
        while (arr[index] != key && arr[index] != -1)
        {
            index = (index + 1) % size;
            if (index == hash_function(key)) // If we loop back to the start, the value is not present
            {
                cout << "The value is not present in the hash" << endl;
                return 0;
            }
        }

        if (arr[index] == key)
        {
            cout << "The value is present in the hash" << endl;
            return 1;
        }
        else
        {
            cout << "The value is not present in the hash" << endl;
            return 0;
        }
    }

    void display_hash()
    {
        // Display the hash table
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    int table_size;
    cout << "Enter the size of the hash table:" << endl;
    cin >> table_size;
    HashTable obj(table_size);
    obj.insertion(10);
    obj.insertion(21);
    obj.insertion(22);
    obj.insertion(46);
    obj.insertion(45);
    obj.insertion(16);
    obj.insertion(17);
    obj.insertion(18);

    obj.searching(18);

    obj.display_hash();

    return 0;
}