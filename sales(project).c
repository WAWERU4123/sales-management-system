// This is a simple sales management system written in C language.
// The program allows the user to log in and choose from several options including updating sales, updating loss, updating stock, and log out.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
int greetings();
int log_in();
int page_1();

int main()
{
greetings(); // Display the greeting message
log_in(); // Prompt the user to enter login credentials
page_1(); // Display the main menu
printf("\n\n=========================================================================\n\n");
  return 0; // Recursive call to main function to restart the program
  }

// Function to display a greeting message and prompt the user to enter the name of their company
int greetings()
{
char company[100];
printf("Enter name of your company: ");
fgets(company , 100 , stdin); // Get input from user using fgets to avoid buffer overflow
company[strcspn(company, "\n")]=0; // Remove the newline character from the string
printf("<<<<<<<<<<<<<<<<<<<<<<<<< %s >>>>>>>>>>>>>>>>>>>>>>>>>\n\n",company);
printf("HELLO AND WELCOME TO SALES MANAGEMENT.....\n");
printf("\n------------------------------------------------------------------------------------\n\n");
return 0;
}

// Function to prompt the user to enter their login credentials
int log_in()
{
printf("ENTER LOG IN DETAILS.\n\n");
char username_1[15];
char password_1[15];
printf("Enter username: ");
scanf("%s",&username_1); // Get input from user using scanf
fgetc(stdin); // Clear the input buffer
printf("Enter password: ");
scanf("%s",&password_1);
fgetc(stdin);
printf("\n------------------------------------------------------------------------------------\n\n");
return 0;
}

// Function to display menu and get user input
int page_1()
{
      // Declare variables
      int choice;         // User's choice from menu
      int current, sold, used, bought;    // Quantity values
      int initial_R = 24;    // Initial router quantity
      int initial_C = 300;   // Initial cable quantity
      char reason[30];       // Reason for loss (input as string)

      // Display menu options
      printf("WHAT ARE YOU HERE FOR TODAY? \n\n");
      printf("1. Update sales \n2. Update loss \n3. Update stock \n4. log out\n CHOICE: ");

      // Get user's choice
      scanf("%d",&choice);

      // Declare a variable for the second choice (router or cable)
      int choice_2;

      // Switch statement to perform the selected task
      switch (choice)
      {
          // Update sales
          case 1:
            printf("\n(1) Routers \n(2) Ethernet Cables\nCHOICE: ");
            scanf("%d",&choice_2);
            printf("\nEnter number sold: ");
            scanf("%d",&sold);

            // Update router quantity
            if (choice_2 == 1)
            {
                  current = initial_R - sold;
                  printf("\nInitial \tSold \tCurrent\n");
                  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                  printf("%d       \t%d     \t%d\n",initial_R,sold,current);
            }

            // Update cable quantity
            if (choice_2 == 2)
            {
                  current = initial_C - sold;
                  printf("\nInitial \tSold \tCurrent\n");
                  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                  printf("%d       \t%d     \t%d\n",initial_C,sold,current);
            }
            break;

            // Update losses
            case 2:
            printf("\n(1) Routers \n(2) Ethernet Cables\nCHOICE: ");
            scanf("%d",&choice_2);
            printf("\nEnter number used: ");
            scanf("%d",&used);
            printf("REASON: ");
            //scanf("%s",&reason);
           fgets(reason , 30 , stdin);
           reason[strcspn(reason, "\n")]=0;

            // Update router quantity
            if (choice_2 == 1)
            {
                  current = initial_R - used;
                  printf("\nInitial \tUsed \tCurrent\n");
                  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                  printf("%d       \t%d    \t%d\n",initial_R,used,current);
                    printf("\nREASON BEING: %s",reason);
            }

            // Update cable quantity
            if (choice_2 == 2)
            {
                  current = initial_C - used;
                  printf("\nInitial \tUsed \tCurrent\n");
                  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
                  printf("%d       \t%d     \t%d\n",initial_C,used,current);
                    printf("\nREASON BEING: %s",reason);
            }
            break;

case 3: // if the user chose to update stock
      printf("\n(1) Routers \n(2) Ethernet Cables\nCHOICE: ");
      scanf("%d",&choice_2); // read in the user's second choice
        printf("\nEnter number bought: ");
      scanf("%d",&bought); // read in the quantity bought
       if (choice_2 == 1) // if the user chose to update the router count
      {
            current = initial_R + bought; // calculate the new count of routers
            printf("\nInitial \tBought \tCurrent\n");
             printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("%d        \t%d     \t%d\n",initial_R,bought,current); // display the count information
      }
      if (choice_2 == 2) // if the user chose to update the Ethernet cable count
      {
            current = initial_C + bought; // calculate the new count of Ethernet cables
            printf("\nInitial \tBought \tCurrent\n");
            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("%d       \t%d     \t%d\n",initial_C,bought,current); // display the count information
      }
      break;
case 4: // if the user chose to log out
      printf("\n************************Thank you for using our system. Have a nice day**********************\n"); // display a farewell message
      break;
default: // if the user entered an invalid choice
      printf("INVALID CHOICE\n"); // display an error message
      page_1(); // call the function again to prompt the user for a valid choice
      break;
      }
      return 0; // indicate successful completion of the function
}
