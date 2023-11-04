#include<iostream>
#include<cstdlib>
#include<conio.h>
#define N 100

using namespace std;

struct Node
{
  int data;
  Node *back;
  Node *front;
};

void ProgEnd()
{
  system("cls");
  cout << "\n\n\t\t\tCLOSING...\n\n";
  cout <<"              ,---------------------------," << endl;
  cout <<"              |  ---------------------  |"<< endl;
  cout <<"              | |                       | |"<< endl;
  cout <<"              | |   Bidirectional       | |"<< endl;
  cout <<"              | |         List          | |"<< endl;
  cout <<"              | |            Program    | |"<< endl;
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
  newNode->back = NULL;
  newNode->front = NULL;
  return newNode;
}

void PrintList (Node *head)
{
  if(head)
  {
    Node *cur; // adress
    cout<<"  Bidirectional list elements:\n\n";
    cur = head;

    cout << "\tLooping forward through list items:\n\t";
    while (cur->front != NULL)
    {
      cout << cur->data << " ";
      cur = cur->front;
    }
    cout << cur->data << " " << endl;

    cout << "\n\tLooping backwards through list items:\n\t";
    while (cur->back != NULL)
    {
      cout << cur->data << " ";
      cur = cur->back;
    }
    cout << cur->data << " " << endl;
  }
  else cout << "Bidirectional list is empty!\n\n";
}

Node *AddFirst(Node *head)
{
  Node *cur;
  cur = new Node;
  cur = CreateNode();

  if(head)
  {
    cur->front = head;
    head->back = cur;
    head = cur;
  }
  else
  {
    head = cur;
  }
  return head;
}

Node *AddEnd(Node *head)
{
  Node *cur, *cur1;
  cur1 = new Node;
  cur1 = CreateNode();

  cur = head;
  while (cur->front != NULL)
  {
      cur = cur->front;
  }
  cur->front = cur1;
  cur1->back = cur;

  return head;
}

Node *FindNode(Node *head, int x)
{
  Node *cur;
  cur = head;

  while(cur != NULL && cur->data != x)
  {
      cur = cur->front;
  }
  return cur;
}

Node *AddBefore(Node *head)
{
  int x;
  Node *cur, *newNode, *prev;
  cout << "Before which node add: ";
  cin >> x;

  cur = FindNode(head, x);
  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode();
    prev = cur->back;
    if(head->data == x)
    {
      newNode->front = head;
      head->back = newNode;
      head = newNode;
    }
    else
    {
      cur->back = newNode;
      newNode->front = cur;
      newNode->back = prev;
      prev->front = newNode;
    }
    cout << "New node is added!\n";
  }
  else cout << "Node does not exist!\n";

 return head;
}

Node *AddAfter(Node *head)
{
  int x;
  Node *cur, *newNode, *next;
  cout << "After which node add: ";
  cin >> x;

  cur = FindNode(head, x);

  if(cur)
  {
    cout << "Node exist!\n";
    newNode = CreateNode();
    next = cur->front;

    if(!next)
    {
      cur->front = newNode;
      newNode->back = cur;
    }
    else
    {
      cur->front = newNode;
      newNode->back = cur;
      newNode->front = next;
      next->back = newNode;
    }

    cout << "New node is added!\n";
  }
  else cout << "Node does not exist!\n";

  return head;
}

int NumberOfNodes(Node *head)
{
  Node *cur;
  cur = head;
  int amount = 0;

  while(cur != NULL)
  {
    cur = cur->front;
    amount++;
  }

  return amount;
}

Node* RemoveNodeBeginning(Node *head)
{
  Node* cur;
  cur = head->front;

  if(head->front != NULL)
  {
    cur->back = NULL;
    delete head;
  }
  else
  {
    delete head;
  }

  return cur;
}

Node* RemoveNodeEnd(Node *head)
{
  Node *cur, *prev;

  if(head->front != NULL)
  {
    cur = head;

    while(cur->front != NULL)
    {
      cur = cur->front;
    }
    prev = cur->back;
    delete cur;
    prev->front = NULL;
  }
  else
  {
    head = RemoveNodeBeginning(head);
  }
  return head;
}

Node* RemoveAll(Node *head)
{
  Node* cur;
  while(head != nullptr)
  {
    cur = head;
    head = head->front;
    delete cur;
  }

  return head;
}

Node* RemoveBefore(Node *head)
{
  int x;
  cout << "Before which node remove: ";
  cin >> x;

  Node *cur, *prev, *prev2;

  cur = FindNode(head, x);

  if(cur)
  {
    cout << "Node exist!\n";
    if(head->data == x)
    {
      cout << "Nothing to delete!\n";
    }
    else
    {
      prev = cur->back;
      if(prev->data == head->data)
      {
        head = cur;
        head->back = NULL;
        delete prev;
      }
      else
      {
        prev2 = prev->back;
        prev2->front = cur;
        cur->back = prev2;
        delete prev;
      }
      cout << "Node has been removed!\n";
    }
  }
  else cout << "Node does not exist!\n";
  return head;
}

Node* RemoveAfter(Node *head)
{
  int x;
  cout << "After which node remove: ";
  cin >> x;

  Node *cur, *next, *next2;
  cur = FindNode(head, x);

  if(cur)
  {
    cout << "Node exist!\n";
    if(cur->front == NULL)
    {
      cout << "Nothing to delete!\n";
    }
    else
    {
      next = cur->front;
      if(next->front == NULL)
      {
        head = RemoveNodeEnd(head);
      }
      else
      {
        next2 = next->front;
        delete next;
        cur->front = next2;
        next2->back = cur;
      }
      cout << "Node has been removed!\n";
    }
  }
  else cout << "Node does not exist!\n";
  return head;
}

int main()
{
  Node *head = NULL;
  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112, num13 = 91, num14 = 93 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
  num13 = 91; it is   [
  num14 = 93; it is   ]
  */
  int choice;

  system("cls");
  cout << "\n\t\tBidirectional List\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 3.1.4\n Date (start): 04.11.2023 / 15:35\n Date (end): xx.11.2023 / 16:13\n\n";

  do
    {
      system("pause>nul");
      system("cls");

      cout << "\n\t\t -- MENU --\n\n";
      cout << "------------------- HEAD ----------------------\n";
      cout << "1. Create head\n";
      cout << "2. Print head value and back/front link\n";
      cout << "\n------------------- ADD -----------------------\n";
      cout << "3. Add node to list beginning\n";
      cout << "4. Add node to list end\n";
      cout << "5. Add node before\n";
      cout << "6. Add node after\n";
      cout << "\n--------------- COUNT & PRINT ----------------\n";
      cout << "7. Show how many nodes exist\n";
      cout << "8. Print List\n";
      cout << "\n------------------ REMOVE --------------------\n";
      cout << "9. Remove node at the beginning\n";
      cout << "10. Remove node at the end (-)\n";
      cout << "11. Remove node before (=)\n";
      cout << "12. Remove node after (p)\n";
      cout << "13. Remove all nodes ([)\n";
      cout << "\n------------------- STOP ---------------------\n";
      cout << "14. Stop Program (])\n";
      cout << "\n----------------------------------------------\n\n";

      choice = getch();

      switch(choice)
      {
        case num1:
        {
          if(!head)
          {
            head = CreateNode();
          }
          else cout << "Head already exist!\n";
          break;
        }
        case num2:
        {
          if(head)
          {
            cout << "Head data: " << head->data << endl;
            cout << "Head back link: " << head->back << endl;
            cout << "Head front link: " << head->front << endl;
          }
          else cout << "Head does not exists! Create Head!\n";
          system("pause>nul");
          break;
        }
        case num3:
        {
          head = AddFirst(head);
          break;
        }
        case num4:
        {
          if(head)
          {
            AddEnd(head);
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num5:
        {
          if(head)
          {
            head = AddBefore(head);
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num6:
        {
          if(head)
          {
            AddAfter(head);
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num7:
        {
          int amount = NumberOfNodes(head);
          cout << "Now there is " << amount << " node/s!";
          break;
        }
        case num8: PrintList(head); break;
        case num9:
        {
          if(head)
          {
            head = RemoveNodeBeginning(head);
            cout << "First node has been removed!\n";
          }
          else cout << "Head does not exists! Create Head!\n";
          break;
        }
        case num10:
        {
          if(head)
          {
            head = RemoveNodeEnd(head);
            cout << "Last node has been removed!\n";
          }
          else cout << "Bidirectional list is empty! Can not remove!\n";
          break;
        }
        case num11:
        {
          if(head)
          {
            head = RemoveBefore(head);
          }
          else cout << "Bidirectional list is empty! Can not remove!\n";
          break;
        }
        case num12:
        {
          if(head)
          {
            head = RemoveAfter(head);
          }
          else cout << "Bidirectional list is empty! Can not remove!\n";
          break;
        }
        case num13:
        {
          if(head)
          {
            head = RemoveAll(head);
            cout << "All nodes have been removed!!\n";
          }
          else cout << "Bidirectional list is empty! Can not remove!\n";
          break;
        }
        case num14: cout << "\nProgram is stopped! Goodbye!"; ProgEnd(); break;
        default: cout << "Incorrect input!\n";
      }
    } while(choice != num14);

  system("pause>nul");
  return 0;
}
