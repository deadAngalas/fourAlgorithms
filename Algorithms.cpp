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

  enum KEYS { num1 = 49, num2 = 50, num3 = 51 , num4 = 52, num5 = 53, num6 = 54, num7 = 55, num8 = 56, num9 = 57, num10 = 45, num11 = 61, num12 = 112, num13 = 91, num14 = 93 };
  /*
  num10 = 45; it is   -
  num11 = 61; it is   =
  num12 = 112; it is  p
  num13 = 91; it is   [
  num14 = 93; it is   ]
  */

  int choice;
  int limit = 0;

  system("cls");
  cout << "\n\t\tLinked List\n\n";
  cout << "\n Author: Vladislav Ryazancev\n Ver: 5.2.7\n Date (start): 06.09.2023 / 14:33\n Date (end): 11.10.2023 / 16:13\n\n";

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
         // if(limit == 0)
         // {
         //   q.Init();
         //   cout << "Queue was initialized!" << endl;
         //   limit++;
         // }
         // else
         // {
         //   cout << "ERROR!\nQueue is already initialized!" << "\n\n";
         // }
         break;
       }
       case num2:
       {
         // if(limit == 0)
         // {
         //   cout << "Can NOT add! Queue is not initialized!\n";
         // }
         // else
         // {
         //   q.Enqueue();
         // }
         break;
       }
       case num3:
       {
         // if(limit == 0)
         // {
         //   cout << "Can NOT remove! Queue is not initialized!\n";
         // }
         // else
         // {
         //   q.Dequeue();
         // }
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
         // if(limit == 0)
         // {
         //   cout << "Can NOT print! Queue is not initialized!\n";
         // }
         // else if(q.Size() == 0)
         // {
         //   cout << "Nodes count: 0\n";
         // }
         // else
         // {
         //   cout << "Nodes count: " << q.Size() << endl;
         // }
         break;
       }
       case num7:
       {

         break;
       }
       case num8:
       {

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
