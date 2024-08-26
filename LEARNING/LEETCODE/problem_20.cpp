class Stacks
{
    char *arr = nullptr;
    int capacity;
    int size;

public:
    Stacks(int capacity)
    {
        this->size = 0;
        this->capacity = capacity;
        arr = new char[capacity]();
    }

    void Push(char a)
    {
        if (size >= capacity)
        {
            cout << "stack overflow";
            return;
        }
        arr[size++] = a;
    }

    void Pop()
    {
        if (size <= 0)
        {
            cout << "stack underflow";
            return;
        }
        size--;
    }

    char Top()
    {
        if (size > 0) {
            return arr[size - 1];
        }
        return '\0'; // Return null character if the stack is empty
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int Size()
    {
        return size;
    }

    void erase()
    {
        this->size = 0;
    }
};
class Solution {
public:
    bool isValid(string str) {
            int len = str.length();
    Stacks stack(len);

    for (int i = 0; i < len; i++)
    {
        char a = str[i];
        if (a == '[' || a == '{' || a == '(')
        {
            stack.Push(a);
        }
        else if (a == ']' && !stack.isEmpty() && stack.Top() == '[')
        {
            stack.Pop();
        }
        else if (a == '}' && !stack.isEmpty() && stack.Top() == '{')
        {
            stack.Pop();
        }
        else if (a == ')' && !stack.isEmpty() && stack.Top() == '(')
        {
            stack.Pop();
        }
        else
        {
            return false;
        }
    }
    return stack.isEmpty();
    }
};