Welcome To Sasta Swiggy
Contents:
Overview
Features
How to use the Restaurant side
Create an account or log in
If no menu auto opens menu creator
If the menu is there opens the menu editor, which allows you to do the following stuff:
i) Create a completely new menu 
ii) Add menu items
iii) Delete menu items
iv) View the current menu
When ordered gives the option to accept or reject orders
Exit the directory
How to use customer side
Creating an account or logging in or Deleting an existing account
Searching through menu
Searching  through food
Ordering from restaurant 
Order confirmation and timer indicating time to arrive
Feedback form after delivery 
Developers
Overview
The C project is a Food Delivery Management system called SastaSwiggy. This Management System is easy to use and it can be accessed by only certain customers and restaurants who are aware of the username and password. However, new account creation is allowed. This app had a wide functionality, from simple order creation to server-related order confirmation. 
Features
This Food Delivery Management System has many features which make it user-friendly, even a layman would not have any problem using it. Apart from some default data, there are many inbuilt functions to help you manage your directory as per your needs, giving it a personalized feel. You also have a password for your directory so, no one else can get your personalized information.
SastaSwiggy enables the following features:
FOR CUSTOMER
Login and Signup and Delete an existing account 
Allows you to see your order history which is stored in a file for every customer
Search 
 restaurants_list 
 By item name or restaurant name(keyword search) 
Search by category of food item(veg, non-veg etc)(Filter search) 
Order food from the desired restaurant 
Once the food is ordered there is an option for the restaurant owner to accept or reject the order 
After confirmation of the order shows a Timer indicating the time to arrive with messages about where the current driver is
After the order is delivered a feedback form is prompted
B) FOR Restaurant
1. Options for login and signup 
2. Edit Menu 
a. Create a new Menu
b. Delete items from menu
c. Add items to menu
d. View current menu
3. Confirm pending orders

Using the interface
Setup
Type: make (on the terminal) 
(u will see a list of commands executed displaying that the program has been compiled)
Type: ./sastaswiggy customer(if you are logging in as a customer) 
Type: ./sastaswiggy owner (if ur logging in as a restaurant)
Install conio.h using https://github.com/zoelabbb/conio.h in some computers it is inbuilt
The program reads from files, prompts the user for input, and interacts with other programs through the command line. The program takes one command-line argument, either "owner" or "customer". Depending on the argument, the program branches into two sections of code.
Restaurant
For the "owner" section, the program prompts the user to enter a number that will determine the action the user wants to take. If the user enters 1, the program calls the f2() function to get the name of an existing restaurant owner from a file. If the user enters anything other than 1, the program compiles and executes another C program called restaurant_signup.c. After getting the name of the restaurant owner, the program sets the "head" pointer of the restaurant to NULL
Customer
For the "customer" section, the program prompts the user to enter a number that will determine the action the user wants to take. If the user enters 1, the program calls the f1() function to get the name of an existing customer from a file. If the user enters anything other than 1 or 2, the program compiles and executes another C program called user_signup.c. If the user enters 2, the program compiles and executes user_delete.c. After getting the name of the customer, the program prompts the user to enter "continue" to proceed, "history" to view previous orders, or anything else to print an error message.
If the user enters "continue", the program calls the menu search () function to help the customer search for his desired dish/restaurant. Here, the customer is provided with the option to search by dish or restaurant, keyword search and filter search. Once the customer finds his desired restaurant, he can order from there.
Here, the user also has the option to say ‘history’ instead of continue to view his order history.
Next, if the user enters "list", the program prints a list of all the restaurants in the system. Now the user is allowed to choose the restaurant of his choice. Then, you can type “start” to start ordering from the restaurant of your choice. It shows you the menu and you can enter the dish names and their respective quantities. It then asks you for your coordinates using which the estimated time of arrival is calculated. Finally, it shows you the bill and stores the order data in a separate file which is your order history which can be viewed by you. 
//hgfherfhbeuef
If the order is confirmed, it asks you for your feedback and if you say yes, it shows you a feedback form and that feedback form goes to the restaurant from which you are ordering.




Developers:
Siddharth Palod: IMT2022002

Prateek Rath: IMT2022017

Shiven Phogat: IMT2022050

Aaditya Gole: IMT2022087

Shashwat Chaturvedi: IMT2022118

Soham Pawar: IMT2022127
