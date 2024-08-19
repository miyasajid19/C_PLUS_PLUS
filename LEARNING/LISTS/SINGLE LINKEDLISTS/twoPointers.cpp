#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
public:
  int value;
  Node *Next;
  Node(int value)
  {
    this->value = value;
    this->Next = nullptr;
  }
};
class LinkedLists
{
public:
  Node *head;
  LinkedLists()
  {
    head = nullptr;
  }
  void add(int value)
  {
    Node *new_node = new Node(value);
    if (head == nullptr)
    {
      head = new_node;
      return;
    }
    Node *temp = head;
    while (temp->Next)
    {
      temp = temp->Next;
    }
    temp->Next = new_node;
  }
  void display()
  {
    if (!head)
    {
      return;
    }
    Node *temp = head;
    while (temp)
    {
      cout << temp->value << "->";
      temp = temp->Next;
    }
    cout << "NULL" << endl;
  }
};
bool checkEqual(Node *head1, Node *head2)
{
  Node *ptr1 = head1;
  Node *ptr2 = head2;
  while (ptr1 != nullptr and ptr2 != nullptr)
  {
    if (ptr1->value != ptr2->value)
    {
      return false;
    }
    ptr1 = ptr1->Next;
    ptr2 = ptr2->Next;
  }
  return ptr1 == NULL and ptr2 == NULL;
}
int main()
{
#ifndef JUDGE_ONLINE
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
#endif
  // LinkedLists lists;
  LinkedLists lists1;
  lists1.add(1);
  lists1.add(2);
  lists1.add(3);
  lists1.display();
  LinkedLists lists2;
  lists2.add(1);
  lists2.add(2);
  lists2.add(3);
  lists2.display();
  cout << boolalpha;
  cout << checkEqual(lists1.head, lists2.head);
  return EXIT_SUCCESS;
}