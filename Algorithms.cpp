#include<iostream>
#include<cstdlib>
#include<conio.h>
#define N 100

using namespace std;

struct Node
{
  int data;
  Node *link;
};

Node *CreateNode()
{
  Node *newNode;
  newNode = new Node;
  cout << "\nEnter number to node: ";
  cin >> newNode->data;
  newNode->link = NULL;
  return newNode;
}

class Stack
{
  private:
      Node *top; // top node
      int size; // stack size

  public:
      void Init();
      void Push();
      void Pop();
      void PrintStack();
      int Size();
      void RemoveAll();
};

void Stack::Init()
{
  top = NULL;
  size = 0;
}

void Stack::Push()
{
  Node *newNode;
  newNode = CreateNode();
  newNode->link = top; // newNode link points to the current top node
  top = newNode; // new node is the top node
  size++; // +1 node count
}

// remove node at the beginning
void Stack::Pop()
{
    Node *temp = top;
    top = top->link;
    delete temp;
    size--;
    cout << "Node has been removed!" << endl;
}

// stack output
void Stack::PrintStack()
{
    Node *cur = top; // start print from top node -> stack feature - last in, first out
    cout << "Stack elements:\n\n";
    while (cur != nullptr) // while cur exists
    {
        cout << "  " << cur->data << "\n";
        cur = cur->link; // node which is under
    }
}

// node count
int Stack::Size()
{
    return size;
}

// all nodes removing
void Stack::RemoveAll()
{
    Node *temp;
    while (top != nullptr) // while top exists
    {
        temp = top;
        top = top->link;
        delete temp;
    }
    size = 0;
    cout << "All nodes have been removed!\n";
}

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |      Stack            | |"<< endl;
  cout <<"              | |         Program       | |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              |  _____________________  |"<< endl;
  cout <<"              |___________________________|"<< endl;
  cout <<"            ,---_____     []     _______------,"<< endl;
  cout <<"            |      ______________           |"<< endl;
  cout <<"        ___________________________________   | ___"<< endl;
  cout <<"        |                                   |   |    )"<< endl;
  cout <<"        |  _ _ _                 [-------]  |   |   ("<< endl;
  cout <<"        |  o o o                 [-------]  |      _)_"<< endl;
  cout <<"        |__________________________________ |       "<< endl;
  cout <<"    -------------------------------------|      ( )"<< endl;
  cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  cout << endl;
}

int main()
{
  Stack s;

  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55 };

  int choice;
  int limit = 0; // checking whether the stack has been initialized or not

  system("cls");
  cout << "\n\t\tStack\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 2.1.1\n Date (start): 05.11.2023 / 11:17\n Date (end): xx.11.2023 / 16:13\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\t -- MENU --\n\n";
      cout << "-------------- INITIALIZATION ----------------\n";
      cout << "1. Initialize stack\n";
      cout << "\n------------------- ADD ----------------------\n";
      cout << "2. Add node at the stack beginning\n";
      cout << "\n------------------ REMOVE --------------------\n";
      cout << "3. Remove node at the stack beginning\n";
      cout << "4. Remove all nodes\n";
      cout << "\n-------------- PRINT & COUNT -----------------\n";
      cout << "5. Print stack\n";
      cout << "6. Show how many nodes exist\n";
      cout << "\n------------------ STOP ----------------------\n";
      cout << "7. Stop Program\n";
      cout << "\n----------------------------------------------\n\n";

      choice = getch();

      switch(choice)
      {
        case num1:
        {
          if(limit == 0)
          {
            s.Init();
            cout << "Stack was initialized!" << endl;
            limit++;
          }
          else
          {
            cout << "ERROR!\nStack is already initialized!" << "\n\n";
          }
          break;
        }
        case num2:
        {
          if(limit == 0)
          {
            cout << "Can NOT add! Stack is not initialized!\n";
          }
          else
          {
            s.Push();
          }
          break;
        }
        case num3:
        {
          if(limit == 0)
          {
            cout << "Can NOT remove! Stack is not initialized!\n";
          }
          else if(s.Size() == 0)
          {
            cout << "Stack is empty! Nothing to remove!\n";
          }
          else
          {
            s.Pop();
          }
          break;
        }
        case num4:
        {
          if(limit == 0)
          {
            cout << "Can NOT remove! Stack is not initialized!\n";
          }
          else if(s.Size() == 0)
          {
            cout << "Stack is empty! Nothing to remove!\n";
          }
          else
          {
            s.RemoveAll();
          }
          break;
        }
        case num5:
        {
          if(limit == 0)
          {
            cout << "Can NOT print! Stack is not initialized!\n";
          }
          else if(s.Size() == 0)
          {
            cout << "Stack is empty!\n";
          }
          else
          {
            s.PrintStack();
          }
          break;
        }
        case num6:
        {
          if(limit == 0)
          {
            cout << "Can NOT print! Stack is not initialized!\n";
          }
          else if(s.Size() == 0)
          {
            cout << "Nodes count: 0\n";
          }
          else
          {
            cout << "Nodes count: " << s.Size() << endl;
          }
          break;
        }
        case num7:
        {
          cout << "\nProgram is stopped! Goodbye!";
          ProgEnd();
          break;
        }
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num7);

  system("pause>nul");
  return 0;
}
