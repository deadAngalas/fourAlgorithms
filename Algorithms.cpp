#include<iostream>
#include<cstdlib>
#include<conio.h>

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

class DeQue
{
  private:
      Node *back; // last element (right site)
      Node *front; // first element (left site)
      int size;

  public:
      void Init();
      void AddBeginning();
      void AddEnd();
      void RemoveBeginning();
      void RemoveEnd();
      void PrintDeQue();
      int Size();
      void RemoveAll();
};

void DeQue::Init()
{
  back = NULL;
  front = NULL;
  size = 0;
}

void DeQue::AddBeginning()
{
  Node *newNode;
  newNode = CreateNode();

  if(Size() == 0) // if deque is empty
  {
    // first node is front & back
    back = newNode;
    front = newNode;
  }
  else // if deque is not empty
  {
    newNode->link = front;
    front = newNode;
  }
  size++;
}

void DeQue::AddEnd()
{
  Node *newNode;
  newNode = CreateNode();

  if(Size() == 0) // if deque is empty
  {
    // first node is front & back
    back = newNode;
    front = newNode;
  }
  else // if deque is not empty
  {
    back->link = newNode;
    back = newNode;
  }
  size++;
}

void DeQue::RemoveAll()
{
  if(Size() == 0)
  {
    cout << "DeQue is empty! Nothing to remove!\n";
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

void DeQue::PrintDeQue()
{
  // DeQue feature - first in, first out (FIFO) and last in first out (LIFO)
  if(Size() == 0) // if deque is empty
  {
    cout << "DeQue is empty!\n";
  }
  else // if deque is not empty
  {
    Node *cur = front;
    cout << "DeQue elements:\n\n";
    while (cur != nullptr)
    {
      cout << " " << cur->data;
      cur = cur->link;
    }
  }
}

void RemoveBeginning()
{
  if(Size() == 0) // if queue is empty
  {
    cout << "DeQue is empty! Nothing to remove!\n";
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

void RemoveEnd()
{
  if(Size() == 0) // if queue is empty
  {
    cout << "DeQue is empty! Nothing to remove!\n";
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
      Node *temp = back;
      front = front->link;
      delete temp;
      size--;
    }
    cout << "Node has been removed!" << endl;
  }
}

int DeQue::Size()
{
    return size;
}

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |      DeQue            | |"<< endl;
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

int main()
{
  DeQue Dq;

  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57 };

  int choice;
  int limit = 0;

  system("cls");
  cout << "\n\t\tLinked List\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 1.2.7\n Date (start): 05.09.2023 / 16:03\n Date (end): 05.10.2023 / 17:01\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\t -- MENU --\n\n";
      cout << "-------------- INITIALIZATION ----------------\n";
      cout << "1. Initialize DeQue\n";
      cout << "\n------------------- ADD ----------------------\n";
      cout << "2. Add node at the DeQue beginning\n";
      cout << "3. Add node at the DeQue end\n";
      cout << "\n------------------ REMOVE --------------------\n";
      cout << "4. Remove node at the DeQue beginning\n";
      cout << "5. Remove node at the DeQue end\n";
      cout << "6. Remove all nodes\n";
      cout << "\n-------------- PRINT & COUNT -----------------\n";
      cout << "7. Print DeQue\n";
      cout << "8. Show how many nodes exist\n";
      cout << "\n------------------ STOP ----------------------\n";
      cout << "9. Stop Program\n";
      cout << "\n----------------------------------------------\n\n";

      choice = getch();

      switch(choice)
     {
       case num1:
       {
         if(limit == 0)
         {
           Dq.Init();
           cout << "DeQue was initialized!" << endl;
           limit++;
         }
         else
         {
           cout << "ERROR!\nDeQue is already initialized!" << "\n\n";
         }
         break;
       }
       case num2:
       {
         if(limit == 0)
         {
           cout << "Can NOT add! DeQue is not initialized!\n";
         }
         else
         {
           Dq.AddBeginning();
         }
         break;
       }
       case num3:
       {
         if(limit == 0)
         {
           cout << "Can NOT add! DeQue is not initialized!\n";
         }
         else
         {
           Dq.AddEnd();
         }
         break;
       }
       case num4:
       {
         // if(limit == 0)
         // {
         //   cout << "Can NOT remove! Queue is not initialized!\n";
         // }
         // else
         // {
         //   q.RemoveAll();
         // }
         break;
       }
       case num5:
       {
         // if(limit == 0)
         // {
         //   cout << "Can NOT print! Queue is not initialized!\n";
         // }
         // else
         // {
         //   q.PrintQueue();
         // }
         break;
       }
       case num6:
       {
         if(limit == 0)
          {
            cout << "Can NOT remove! DeQue is not initialized!\n";
          }
          else
          {
            Dq.RemoveAll();
          }
         break;
       }
       case num7:
       {
         if(limit == 0)
          {
            cout << "Can NOT print! DeQue is not initialized!\n";
          }
          else
          {
            Dq.PrintDeQue();
          }
         break;
       }
       case num8:
       {
         if(limit == 0)
          {
            cout << "Can NOT print! DeQue is not initialized!\n";
          }
          else if(Dq.Size() == 0)
          {
            cout << "Nodes count: 0\n";
          }
          else
          {
            cout << "Nodes count: " << Dq.Size() << endl;
          }
         break;
       }
       case num9:
       {
         cout << "\nProgram is stopped! Goodbye!";
         ProgEnd();
         break;
       }
       default: cout << "Incorrect input!\n";
     }
   } while(choice != num9);

  system("pause>nul");
  return 0;
}
