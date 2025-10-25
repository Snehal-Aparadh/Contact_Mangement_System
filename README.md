📞 My Contact Management System
This is a Mini Project for my second year, built using the C programming language. It is a simple tool that runs in the console (like Command Prompt or Terminal) and helps manage a list of contacts.

All the contact information is saved permanently in a text file named contact_manager.txt.

✨ What It Can Do (Features)
The program offers a menu with these options:

Add Contact: You can save new contacts with details like First Name, Last Name, Profession, two Phone Numbers, Email, and a Nickname.

Smart Checks (Validation): It won't let you add a contact if the name is already used, a phone number is a duplicate, or if the number isn't exactly 10 digits.

View All Contacts: Shows all the saved contacts in a clear, easy-to-read table.

Search Contact: You can find a contact just by typing the starting letters of their first or last name.

Delete Contact: Removes a contact when you provide their first and last name.

Update Contact: You can change the details of an existing contact. You find the contact by searching their name or any of their numbers.

Clear All Contacts: Deletes all contacts saved in the file.

🛠️ How to Run It
You need a C compiler (like GCC) to turn the code into a program that runs.

Compile: Open your terminal and run this command:

Bash

gcc Contact_Management_System.c -o contact_manager
Run: After compiling, start the program with:

Bash

./contact_manager
Use the Menu: The program will show a numbered menu, and you enter the number for the action you want to perform (1 for Add, 2 for Delete, etc.).

💾 Technical Details
Language: C

Data Storage: File Handling (using contact_manager.txt)

Key Functions:

add_contact()

delete_contact()

update_contact()

search_by_name()
