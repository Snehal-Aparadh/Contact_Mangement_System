📞 My Contact Management System:
This is a Mini Project for my second year, built using the C programming language. It is a simple tool that runs in the console (like Command Prompt or Terminal) and helps manage a list of contacts.
All the contact information is saved permanently in a text file named contact_manager.txt.

----------------------------------------------------------------------------------------------------------------------------------------
✨ What It Can Do (Features)
----------------------------------------------------------------------------------------------------------------------------------------
The program offers a menu with these options:

  1.Add Contact: You can save new contacts with details like First Name, Last Name, Profession, two Phone Numbers, Email, and a Nickname.
  
  2.Smart Checks (Validation): It won't let you add a contact if the name is already used, a phone number is a duplicate, or if the number isn't exactly 10 digits.
  
  3.View All Contacts: Shows all the saved contacts in a clear, easy-to-read table.
  
  4.Search Contact: You can find a contact just by typing the starting letters of their first or last name.
  
  5.Delete Contact: Removes a contact when you provide their first and last name.
  
  6.Update Contact: You can change the details of an existing contact. You find the contact by searching their name or any of their numbers.
  
  7.Clear All Contacts: Deletes all contacts saved in the file.
  
-----------------------------------------------------------------------------------------------------------------------------------------
🛠️ **How to Run It:**
------------------------------------------------------------------------------------------------------------------------------------------
You need a C compiler (like GCC) to turn the code into a program that runs.

1)Compile: Open your terminal and run this command:
  Bash
  gcc Contact_Management_System.c -o contact_manager
  
2)Run: After compiling, start the program with:
  Bash
  ./contact_manager

3)Use the Menu: The program will show a numbered menu, and you enter the number for the action you want to perform (1 for Add, 2 for Delete, etc.).

-----------------------------------------------------------------------------------------------------------------------------------------
💾 **Technical Details:**
---------------------------------------------------------------------------------------------------------------------------------------
Language: C

Data Storage: File Handling (using contact_manager.txt)

Key Functions:
    1.add_contact()
    2.delete_contact()
    3.update_contact()
    4.search_by_name()
