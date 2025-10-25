//Mini Project:Contact list search and update.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct contacts
{
	char Fname[15];
	char Lname[15];
	char profession[15];
	char mob[12];
	char mob2[12];
	char email[25];
	char nick_nm[10];
};

int contact_exists(const char *Fname, const char *Lname);
void add_contact();
bool is_duplicate_number(const char *number);
void delete_contact();
void view_all_contact();
void search_by_name();
void clear_contacts();
void update_contact();

int main()
{
    int choice;
    do 
    {
        printf("\nContact List:\n");
        printf("\t 1. Add contact\n");
        printf("\t 2. Delete contact\n");
        printf("\t 3. View all contacts\n");
        printf("\t 4. Search contact\n");
        printf("\t 5. Clear all contacts\n");
        printf("\t 6. Update contact\n");
        printf("\t 7. Exit\n");

        printf("Enter option from above list: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                view_all_contact();
                break;
            case 4:
                search_by_name();
                break;
            case 5:
                clear_contacts();
                break;
            case 6:
            	update_contact();
            	break;
            case 7:printf("Exit");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 7);

}

void add_contact()
{
   
	struct contacts contact;
   
	FILE *fp;
	fp = fopen("contact_manager.txt", "a+");
	if (fp == NULL)
	{
		printf("Error opening file for writing.\n");
		return;
	}
	printf("\nContact List:\n");
	printf("\tFirst Name: ");
	scanf("%s", contact.Fname);
	printf("\tLast Name: ");
	scanf("%s", contact.Lname);
    
	if(contact_exists(contact.Fname, contact.Lname))     //Check if contact with same name exists.
	{
		printf("Contact with the same name already exists, so we cannot add duplicate contact.\n");
		return;
	}

	printf("\tProfession: ");
	scanf("%s", contact.profession);
    
	do 
	{
		printf("\tNumber (exactly 10 digits): ");
		scanf("%11s", contact.mob);
		if (strlen(contact.mob) != 10)
		{
			printf("Error: Phone number must be exactly 10 digits.\n");
		}
	}while (strlen(contact.mob) != 10);
    
	char choice;
	printf("\nDo you want to add another number (y/n): ");
	scanf(" %c",&choice);
    	
	if(choice== 'y' || choice== 'Y')
	{
		do 
		{
			printf("\tNumber2 (exactly 10 digits): ");
			scanf("%11s", contact.mob2);
			if (strlen(contact.mob2) != 10)
			{
				printf("Error: Phone number must be exactly 10 digits.\n");
			}

		}while (strlen(contact.mob2) != 10);
	}
	else
	{
		strcpy(contact.mob2, "**********");
	}

	if (is_duplicate_number(contact.mob) || (strlen(contact.mob2) > 0 && is_duplicate_number(contact.mob2))) 
	{
        	printf("Error: Phone number already exists.\n");
        	return;
	}
	do
	{
		printf("Email :");
		scanf("%s",contact.email);
		if(strstr(contact.email,"@gmail.com") == NULL)
		{
			printf("Error : Email must end with @gmail.com \n" );
		}
		
	}while(strstr(contact.email,"@gmail.com") ==NULL);
    
	printf("\tNick Name:");
	scanf("%s", contact.nick_nm);

	fprintf(fp, "%s \t %s \t %s \t %s \t", contact.Fname, contact.Lname, contact.profession, contact.mob);

	if(choice == 'Y' || choice == 'y')
	{
		fprintf(fp, "%s\t",contact.mob2);
	}
	else
	{
		fprintf(fp,"%s\t", contact.mob2);
	}
	
	fprintf(fp, "%s \t%s\n", contact.email, contact.nick_nm);

	fclose(fp);
	printf("Contact added successfully.\n");
}

int contact_exists(const char *Fname, const char *Lname)
{
	FILE *fp;
	struct contacts temp_contact;
	fp=fopen("contact_manager.txt","r");
	if(fp==NULL)
	{
		printf("Error in opening file for reading.\n");
		return 0;
	}
	
	while(fscanf(fp, "%s %s %s %s %s %s %s", temp_contact.Fname, temp_contact.Lname, temp_contact.profession, temp_contact.mob, temp_contact.mob2, temp_contact.email, temp_contact.nick_nm)!= EOF)
	{
		if(strcmp(Fname,temp_contact.Fname) == 0 && strcmp(Lname, temp_contact.Lname)== 0)
		{
			fclose(fp);
			return 1; //Contact with same name already exists
		}
	} 
	fclose(fp);
	return 0; //Contact doesn't exists with same name.
	
}

bool is_duplicate_number(const char* number) {
    FILE *fp;
    struct contacts temp_contact;

    fp = fopen("contact_manager.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return false;
    }

    while (fscanf(fp, "%s %s %s %s %s %s %s", temp_contact.Fname, temp_contact.Lname, temp_contact.profession, temp_contact.mob, temp_contact.mob2, temp_contact.email, temp_contact.nick_nm) != EOF) {
        if (strcmp(number, temp_contact.mob) == 0 || strcmp(temp_contact.mob2,"**********") !=0 && strcmp(number, temp_contact.mob2) == 0) 
        {
            fclose(fp);
            return true; // Number already exists
        }
    }

    fclose(fp);
    return false; // Number 
 }   
 
void delete_contact()
{
	char Fname[50], Lname[50];
	
	FILE *fp, *temp;
	struct contacts contact;

	fp = fopen("contact_manager.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}
	
	temp = fopen("temp.txt", "w");
	if (temp == NULL)
	{
		printf("Error creating temporary file.\n");
		fclose(fp);
	return;
	}
	
	printf("\nDelete contact\n");
	printf("\tFirst Name: ");
	scanf("%s", Fname);
	printf("\tLast Name: ");
	scanf("%s", Lname);
    
	int found = 0;
	while(fscanf(fp, "%s %s %s %s %s %s %s", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm) != EOF)
	{
		if(strcmp(Fname, contact.Fname) == 0 && strcmp(Lname, contact.Lname) == 0)
		{
			found = 1;
			printf("Contact deleted successfully.\n");
		}
		else
		{
			fprintf(temp, "%s %s %s %s %s %s %s\n", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm);
		}
	}
	
	fclose(fp);
	fclose(temp);
	remove("contact_manager.txt");
	rename("temp.txt", "contact_manager.txt");
	if (!found)
	{
		printf("Contact not found.\n");
	}
}

void view_all_contact()
{
	
	struct contacts contact;
	FILE *fp;
	fp = fopen("contact_manager.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}
	printf("\n**View all contacts\n");
	printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-25s | %-10s |\n", "First Name", "Last Name", "Profession", "Number1", "Number2", "Email ID", "Nick Name");
	printf("+-----------------+-----------------+-----------------+-----------------+-----------------+---------------------------+------------+\n");
	while(fscanf(fp, "%s %s %s %s %s %s %s", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm) != EOF)
	{
		if(strcmp(contact.mob2,"") == 0)
		{
			printf("| %-15s | %-15s | %-15s | +91-%-11s | +91-%-11s | %-25s | %-10s |\n", contact.Fname, contact.Lname, contact.profession, contact.mob, "**********", contact.email, contact.nick_nm);
		}
		else
		{
			printf("| %-15s | %-15s | %-15s | +91-%-11s | +91-%-11s | %-25s | %-10s |\n", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2 , contact.email, contact.nick_nm);
		}
		
	}
	printf("+-----------------+-----------------+-----------------+-----------------+-----------------+---------------------------+------------+\n");
	fclose(fp);
	
}


void search_by_name()
{
	char substring[15];
	
	struct contacts contact;
	FILE *fp;
	int found = 0;
	fp = fopen("contact_manager.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file for reading.\n");
		return;
	}
	printf("\n**Search contact by starting substring of first name or last name:\n");
	printf("Enter Substring: ");
	scanf("%s", substring);
	
	printf("| %-15s | %-15s | %-15s | %-15s | %-15s | %-25s | %10s |\n", "First Name", "Last Name", "Profession", "Number1", "Number2", "Email ID", "Nick Name");
	printf("+-----------------+-----------------+-----------------+-----------------+-----------------+---------------------------+-----------+\n");
	
	while(fscanf(fp, "%s %s %s %s %s %s %s", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm) != EOF)
	{
		if(strstr(contact.Fname, substring) == contact.Fname || strstr(contact.Lname, substring)== contact.Lname)
		{
			printf("| %-15s | %-15s | %-15s | +91-%-11s | +91-%-11s |%-25s | %-10s |\n", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm);
			found = 1;
		}
	}
	printf("+-----------------+-----------------+-----------------+-----------------+-----------------+---------------------------+------------+\n");
	fclose(fp);
	if (!found)
	{
		printf("No contacts found matching the given substring.\n");
	}
}


void clear_contacts()
{
	FILE *fp;
	fp = fopen("contact_manager.txt", "w");
	if (fp == NULL)
	{
		printf("Error opening file for writing.\n");
		return;
	}
	
	fclose(fp);
	printf("All contacts cleared successfully.\n");
}

void update_contact()
{
	char search_query[20]; // To store the search query (name or number)
	struct contacts contact; // Structure to hold contact details

	// Open the file for reading and writing
	FILE *fp, *temp;
	fp = fopen("contact_manager.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file for reading and writing.\n");
		return;
	}

	temp=fopen("temp.txt","w");
	if(temp==NULL)
	{
		printf("Error creating temporary file");
		fclose(fp);
		return;
		
	}
	
	// Ask the user to enter the name or number of the contact to update
	printf("Enter the name or number of the contact you want to update: ");
	scanf("%s", search_query);

	int found=0;
	// Search for the contact in the file
	while (fscanf(fp, "%s %s %s %s %s %s %s", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm) != EOF)			
	{
		// Check if the contact matches the search query
		if (strcmp(contact.Fname, search_query) == 0 || strcmp(contact.mob, search_query) == 0 || strcmp(contact.mob2, search_query) == 0)
		{
			    found=1;
			    // Display the contact details
			    printf("Contact Found:\n");
			    printf("First Name: %s\n", contact.Fname);
			    printf("Last Name: %s\n", contact.Lname);
			    printf("Profession: %s\n", contact.profession);
			    printf("Mobile Number 1: %s\n", contact.mob);
			    printf("Mobile Number 2: %s\n", contact.mob2);
			    printf("Email: %s\n", contact.email);
			    printf("Nick Name: %s\n", contact.nick_nm);

			    // Ask the user for the details to update
			    printf("Enter the new details for the contact:\n");
			    printf("First Name: ");
			    scanf("%s", contact.Fname);
			    printf("Last Name: ");
			    scanf("%s", contact.Lname);
			    printf("Profession: ");
			    scanf("%s", contact.profession);
			    printf("Mobile Number 1: ");
			    scanf("%s", contact.mob);
			    printf("Mobile Number 2: ");
			    scanf("%s", contact.mob2);
		}
			
			// Write the updated contact details to the file
			fprintf(temp, "%s %s %s %s %s %s %s\n", contact.Fname, contact.Lname, contact.profession, contact.mob, contact.mob2, contact.email, contact.nick_nm);
	}
	
	fclose(fp);
	fclose(temp);
	
	remove("contact_manager.txt");
	rename("temp.txt","contact_manager.txt");
	
	if(!found)
	{
		printf("Contact not found\n");
	}
	else
	{
		printf("Contact updated successfully\n");
	}
}
