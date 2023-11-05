#include<iostream>
#include<cstdlib>
#include<conio.h>

using namespace std;

struct Node
{
  int data;
  Node *link;
};

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |      Queue            | |"<< endl;
  cout <<"              | |          Program      | |"<< endl;
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

Node *CreateNode()
{
  Node *newNode;
  newNode = new Node;
  cout << "\nEnter number to node: ";
  cin >> newNode->data;
  newNode->link = NULL;
  return newNode;
}

class Queue
{
  private:
      Node *back; // last element (right site)
      Node *front; // first element (left site)
      int size;

  public:
      void Init();
      void Enqueue(); // add node queue at the end
      void Dequeue(); // remove node at the beginning
      void PrintQueue();
      int Size();
      void RemoveAll();
};

void Queue::Init()
{
  back = NULL;
  front = NULL;
  size = 0;
}

void Queue::Enqueue()
{
  Node *newNode;
  newNode = CreateNode();

  if(back == NULL) // if queue is empty
  {
    // first node is front & back
    back = newNode;
    front = newNode;
  }
  else // if queue is not empty
  {
    back->link = newNode;
    back = newNode;
  }
  size++;
}

void Queue::Dequeue()
{
  if(front == NULL) // if queue is empty
  {
    cout << "Queue is empty! Nothing to remove!\n";
  }
  else // if queue is not empty we can remove
  {
    if(front == back) // if there 1 node
    {
      delete front;
      size--;
      front = back = NULL;
    }
    else
    {
      Node *temp = front;
      front = front->link;
      delete temp;
      size--;
    }
    cout << "Node has been removed!" << endl;
  }
}

void Queue::PrintQueue()
{
  // queue feature - first in, first out (FIFO)
  if(front == nullptr) // if queue is empty
  {
    cout << "Queue is empty!\n";
  }
  else // if queue is not empty
  {
    Node *cur = front;
    cout << "Queue elements:\n\n";
    while (cur != nullptr)
    {
      cout << " " << cur->data;
      cur = cur->link;
    }
  }
}

int Queue::Size()
{
    return size;
}

void Queue::RemoveAll()
{
  if(front == NULL)
  {
    cout << "Queue is empty! Nothing to remove!\n";
  }
  else
  {
    Node *temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->link;
        delete temp;
    }
    size = 0;
    back = NULL;
    cout << "All nodes have been removed!\n";
  }
}

int main()
{
  Queue q;

  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55 };

  int choice;
  int limit = 0;

  system("cls");
  cout << "\n\t\tQueue\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 2.1.1\n Date (start): 05.11.2023 / 13:31\n Date (end): 05.11.2023 / 15:46\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\t -- MENU --\n\n";
      cout << "-------------- INITIALIZATION ----------------\n";
      cout << "1. Initialize queue\n";
      cout << "\n------------------- ADD ----------------------\n";
      cout << "2. Add node at the queue end\n";
      cout << "\n------------------ REMOVE --------------------\n";
      cout << "3. Remove node at the queue beginning\n";
      cout << "4. Remove all nodes\n";
      cout << "\n-------------- PRINT & COUNT -----------------\n";
      cout << "5. Print queue\n";
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
            q.Init();
            cout << "Queue was initialized!" << endl;
            limit++;
          }
          else
          {
            cout << "ERROR!\nQueue is already initialized!" << "\n\n";
          }
          break;
        }
        case num2:
        {
          if(limit == 0)
          {
            cout << "Can NOT add! Queue is not initialized!\n";
          }
          else
          {
            q.Enqueue();
          }
          break;
        }
        case num3:
        {
          if(limit == 0)
          {
            cout << "Can NOT remove! Queue is not initialized!\n";
          }
          else
          {
            q.Dequeue();
          }
          break;
        }
        case num4:
        {
          if(limit == 0)
          {
            cout << "Can NOT remove! Queue is not initialized!\n";
          }
          else
          {
            q.RemoveAll();
          }
          break;
        }
        case num5:
        {
          if(limit == 0)
          {
            cout << "Can NOT print! Queue is not initialized!\n";
          }
          else
          {
            q.PrintQueue();
          }
          break;
        }
        case num6:
        {
          if(limit == 0)
          {
            cout << "Can NOT print! Queue is not initialized!\n";
          }
          else if(q.Size() == 0)
          {
            cout << "Nodes count: 0\n";
          }
          else
          {
            cout << "Nodes count: " << q.Size() << endl;
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
