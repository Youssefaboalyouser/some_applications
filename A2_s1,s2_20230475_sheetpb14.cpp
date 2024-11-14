#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <initializer_list>
using namespace std;

class LabelGenerator
{
protected:
    int currentIndex;
    string prefix;

public:
    LabelGenerator(int current_index, const string &pre)
        : currentIndex(current_index), prefix(pre) {}

    virtual string next_label() = 0;
};

class FileGenerator : public LabelGenerator
{
private:
    vector<string> captions;
    vector<string> result;
    size_t caption_index;

public:
    FileGenerator(int current_index, const string &pre, const string &filename)
        : LabelGenerator(current_index, pre), caption_index(0)
    {

        ifstream file(filename);
        string line;

        if (!file)
        {
            cerr << "Error: Unable to open file " << filename << ". Returning to menu...\n";
            return;
        }

        while (getline(file, line))
        {
            captions.push_back(line);
        }
        file.close();
    }

    string next_label() override
    {
        string label = prefix + " " + to_string(currentIndex++);
        if (caption_index < captions.size())
        {
            label += " " + captions[caption_index++];
        }
        result.push_back(label);
        return label;
    }

    void generate_labels(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            next_label();
        }
    }

    void display() const
    {
        for (const string &str : result)
        {
            cout << str << endl;
        }
    }
};

template <class T>
class youssef_set
{
private:
    int capacity, size;
    T *items;

    // Private resize helper method
    void resize(int n_capacity)
    {
        T *n_item = new T[n_capacity];
        for (int i = 0; i < size; ++i)
        {
            n_item[i] = items[i];
        }
        delete[] items;
        items = n_item;
        capacity = n_capacity;
    }

public:
    // Default constructor
    youssef_set() : items(new T[2]), capacity(2), size(0) {}

    // Initializer list constructor
    youssef_set(initializer_list<T> temp_list)
        : items(new T[temp_list.size()]), capacity(temp_list.size()), size(0)
    {
        for (const T &item : temp_list)
        {
            add(item);
        }
    }

    // Destructor
    ~youssef_set()
    {
        delete[] items;
    }

    // Returns the number of elements in the set
    int noe() const
    {
        return size;
    }

    // Adds an item to the set, if it is not already present
    void add(const T &item)
    {
        if (!is_member(item))
        { // Only add if item is not present
            if (size == capacity)
            {
                resize(capacity * 2); // Double the capacity if needed
            }
            items[size++] = item;
        }
    }

    // Removes all occurrences of an item (for a set, it will be at most one occurrence)
    void remove_all(const T &item)
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i] == item)
            {
                // Shift all elements after i to the left
                for (int j = i; j < size - 1; ++j)
                {
                    items[j] = items[j + 1];
                }
                --size;
                break;
            }
        }
    }

    // Checks if an item is in the set
    bool is_member(const T &item) const
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i] == item)
            {
                return true;
            }
        }
        return false;
    }

    // Returns the index of an item in the set, or -1 if not found
    int index(const T &item) const
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i] == item)
            {
                return i;
            }
        }
        return -1; // Item not found
    }

    // Returns a dynamically allocated array containing each item in the set
    T *dynamical_container() const
    {
        T *dynamicArray = new T[size];
        for (int i = 0; i < size; ++i)
        {
            dynamicArray[i] = items[i];
        }
        return dynamicArray; // Caller is responsible for de-allocating this memory
    }

    // Overloads operator[] to access items by index
    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return items[index];
    }
};

// Function to validate integer input and avoid infinite loops
bool getIntInput(int &input)
{
    cin >> input;
    if (cin.fail())
    {
        cin.clear();                                         // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter an integer.\n";
        return false;
    }
    return true;
}

int main()
{
    string choice;
    while (true)
    {
        cout << "***************** Welcome to my program *****************\n";
        cout << "There are two programe:\n(1) Label Generator\n(2) Youssef's Set Container\n(3) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1")
        {
            string prefix, file_name;
            int initial_num;

            cout << "Enter initial index: ";
            while (!getIntInput(initial_num))
            {
                cout << "Enter a valid integer for initial index: ";
            }

            cout << "Enter your prefix: ";
            cin >> prefix;
            cout << "Enter file name: ";
            cin >> file_name;

            FileGenerator generator(initial_num, prefix, file_name);
            ifstream testFile(file_name);
            if (!testFile)
            {
                continue; // Return to menu if file is invalid
            }

            int label_count;
            cout << "How many labels would you like to generate? ";
            while (!getIntInput(label_count))
            {
                cout << "Enter a valid integer for label count: ";
            }

            generator.generate_labels(label_count);
            cout << "Generated labels:" << endl;
            generator.display();
        }
        else if (choice == "2")
        {
            youssef_set<int> test({1, 2, 3, 4});
            test.add(5);
            test.add(3);
            test.remove_all(5);
            cout << test.is_member(1) << endl;
            cout << test.is_member(0) << endl;
            int c = test.index(1);
            if (c == -1)
                cout << "not found!" << endl;
            else
                cout << c << endl;
            int *ptr = test.dynamical_container();
            for (int i = 0; i < test.noe(); i++)
            {
                cout << test[i] << endl;
            }
            delete[] ptr;
        }
        else if (choice == "3")
        {
            cout << "\n======>>> GOOD BYE <<<======\n";
            return 0;
        }
        else
        {
            cout << "Error: Please enter a valid choice!\n";
            cout << "=================================================\n";
        }
    }
}
