<h1><b>Welcome To Sasta Swiggy<b></h1><br>
 <h2><u>Contents:</u></h2><br>
<ul>
 <li>Overview</li>
 <li>Features</li>
 <li>How to use the Restaurant side</li>
 <li>Create an account or log in</li>
 <li>If no menu auto opens menu creator</li>
<li>If the menu is there opens the menu editor, which allows you to do the following stuff:
 <ol type="i)">
  <li>Create a completely new menu </li>
  <li> Add menu items</li>
  <li> Delete menu items</li>
  <li> View the current menu</li></ol></li>
 <li>When ordered gives the option to accept or reject orders</li>
<li>Exit the directory</li>
<li>How to use customer side</li>
<li>Creating an account or logging in or Deleting an existing account</li>
<li>Searching through menu</li>
<li>Searching  through food</li>
<li>Ordering from restaurant </li>
<li>Order confirmation and timer indicating time to arrive</li>
<li>Feedback form after delivery </li>
<li>Developers</li>
 </ul>
 <br>
 <h2><u>Overview:</u></h2>
 <p>Note: if you extract files with data you can see it work with sample restaurants note do no extract MenuOwner.c from zip as it is outdated</p>
<p>The C project is a Logistics Optimization Platform for Food Delivery called SastaSwiggy. This Management System is easy to use and it can be accessed by only certain customers and restaurants who are aware of the username and password. However, new account creation is allowed. This app had a wide functionality, from simple order creation to server-related order confirmation. <p>
 <br>
 <h2><u>Features:</u></h2>
<p>This Food Delivery Management System has many features which make it user-friendly, even a layman would not have any problem using it. Apart from some default data, there are many inbuilt functions to help you manage your directory as per your needs, giving it a personalized feel. You also have a password for your directory so, no one else can get your personalized information.</p><br>
 <h2><u>SastaSwiggy enables the following features:</u></h2>
<ol type="A)">
 <li>FOR Customer
Login and Signup and Delete an existing account 
Allows you to see your order history which is stored in a file for every customer
Search 
 restaurants_list 
 By item name or restaurant name(keyword search) 
Search by category of food item(veg, non-veg etc)(Filter search) 
Order food from the desired restaurant 
Once the food is ordered there is an option for the restaurant owner to accept or reject the order 
After confirmation of the order shows a Timer indicating the time to arrive with messages about where the current driver is
  After the order is delivered a feedback form is prompted</li>
<li>FOR Restaurant
 <ol type="1.">
  <li> Options for login and signup </li>
<li> Edit Menu 
 <ol type="a.">
  <li> Create a new Menu</li>
  <li> Delete items from menu</li>
  <li> Add items to menu</li>
  <li> View current menu</li></ol></li>
  <li> Confirm pending orders</li></ol></li></ol>

Using the interface
 <h2><u>Setup:</u></h2>
 Type: <code>make</code> (on the terminal) <br>
(u will see a list of commands executed displaying that the program has been compiled)<br>
 Type: <code>./sastaswiggy customer</code>(if you are logging in as a customer) <br>
 Type: <code>./sastaswiggy owner</code> (if ur logging in as a restaurant)<br>
 Install <code>conio.h</code> using https://github.com/zoelabbb/conio.h in some computers it is inbuilt<br>
The program reads from files, prompts the user for input, and interacts with other programs through the command line. The program takes one command-line argument, either "owner" or "customer". Depending on the argument, the program branches into two sections of code.
 <h2><u>Restaurant</u></h2>
For the "owner" section, the program prompts the user to enter a number that will determine the action the user wants to take. If the user enters 1, the program calls the f2() function to get the name of an existing restaurant owner from a file. If the user enters anything other than 1, the program compiles and executes another C program called restaurant_signup.c. After getting the name of the restaurant owner, the program sets the "head" pointer of the restaurant to NULL<br>
 <h2><u>Customer</u></h2>
<p>For the "customer" section, the program prompts the user to enter a number that will determine the action the user wants to take. If the user enters 1, the program calls the f1() function to get the name of an existing customer from a file. If the user enters anything other than 1 or 2, the program compiles and executes another C program called user_signup.c. If the user enters 2, the program compiles and executes user_delete.c. After getting the name of the customer, the program prompts the user to enter "continue" to proceed, "history" to view previous orders, or anything else to print an error message.</p>
 <br>
<p>If the user enters "continue", the program calls the menu search () function to help the customer search for his desired dish/restaurant. Here, the customer is provided with the option to search by dish or restaurant, keyword search and filter search. Once the customer finds his desired restaurant, he can order from there.</p>
 <br>
<p>Here, the user also has the option to say ‘history’ instead of continue to view his order history.</p>
 <br>
<p>Next, if the user enters "list", the program prints a list of all the restaurants in the system. Now the user is allowed to choose the restaurant of his choice. Then, you can type “start” to start ordering from the restaurant of your choice. It shows you the menu and you can enter the dish names and their respective quantities. It then asks you for your coordinates using which the estimated time of arrival is calculated. Finally, it shows you the bill and stores the order data in a separate file which is your order history which can be viewed by you. </p>
 <br>
<p>The bill is also stored in a temporary file, 'common.txt'. A signal is then sent to the restaurant owner's terminal which then opens the temporary file and prints the bill in the owner's bill. This is to display the order to the restaurant owner to prepare the order. The owner then gets two options, either to confirm the order or to deny the order. The response is using a 'Y' or a 'N' character. If the character 'Y' is entered, a signal is sent again from owner's terminal to the customer's terminal.</p>
 <br>
<p>If the order is confirmed, it asks you for your feedback and if you say yes, it shows you a feedback form and that feedback form goes to the restaurant from which you are ordering.</p>

 <h2><u>Developers:</u></h2>
<ul>
 <li>Siddharth Palod: IMT2022002</li>
 <li>Prateek Rath: IMT2022017</li>
 <li>Shiven Phogat: IMT2022050</li>
<li>Aaditya Gole: IMT2022087</li>
 <li>Shashwat Chaturvedi: IMT2022118</li>
 <li>Soham Pawar: IMT2022127</li></ul>
