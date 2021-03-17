#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
	char name[50];
	char number[15];
};

int main(void)
{
	int input;
	do{
		printf("\n**********CONTACT MANAGER**********");
    
    		printf("\npress 1 to Add contact");
		printf("\npress 2 to Read all contacts");
		printf("\npress 3 to Search contact");
		printf("\npress 4 to Edit contact");
		printf("\npress 5 to delete contact");
		printf("\npress 0 to exit");
		scanf("%d",&input);
        	fflush(stdin);
        	switch(input)
		{
			case 1:
			printf("\n*****ADD CONTACT*****");
			addcontact();
			break;

			case 2:
			printf("*****ALL CONTACTS*****\n");
			readcontact();
			break;

			case 3:
			printf("*****SEARCH CONTACT*****");
            		Searchcontact();
            		break;
			
			case 4:
			printf("*****EDIT CONTACT*****");
           		Editcontact();
           		break;

            		case 5:
          		printf("*****DELETE CONTACT*****");
            		deletecontact();
            		break;
			
            		case 0:
            		printf("*****EXITING CONTACT MANAGER*****");
            		return 0;
            		break;

            		default:
            		printf("\nInvalid Input");
            		printf("\nSelect correct input");
            		break;
		}
		
}while(1);
return 0;
}

int addcontact(void)
{
	{
	FILE* fptr = NULL;
	fptr = fopen("mycontacts.txt", "a");
	
	if (fptr == NULL)
	{
		printf("\n File not found");
		return 1;
	}

	struct contact add;
	
	  printf("\n Enter Name : ");
      	  scanf("%s",add.name);
	  printf("\n Enter number : ");
      	  scanf("%s",add.number);

	  fprintf( fptr,"%s\n", add.name);
	  fprintf( fptr,"%s\n", add.number);
	  printf("\n Contact Added Successfully.\n");
	  fclose(fptr);
	  return 0;
	}
}


int readcontact(void)
{
	{
      	FILE* fptr;
      	struct contact add;
      	fptr = fopen("mycontacts.txt", "r");
	                        
    
      	while(!feof(fptr))
     	{
      		fscanf(fptr,"%s\n",add.name);
      		printf("%s",add.name);
      		printf("\n");
      }
      fclose(fptr);
      return 0;
}
}

int Searchcontact(void)
{
	struct contact add;
	char name[30];
	int Search=0;
	char aname[30];
    	char anumber[30];
	
	FILE* fptr = NULL;
	fptr = fopen("mycontacts.txt", "r");
	
	printf("\n Enter Name :");
	scanf("\n%s", &name);
	
	while (fscanf (fptr, "%s\n\n%s\n\n", aname,anumber) != EOF)
	{
		if (strcmp(name,aname)== 0)
		{
			printf("\n%s" , aname);
			printf("\n%s\n" , anumber);
			Search++;	
		}
	}
	
	 if(Search==0)
	 {
         	printf("\n No Match Found");
		 }
      	 else{
         	printf("\n Total %d Record found\n",Search);
		 }
	
	fclose(fptr);
	return 0;
}

int Editcontact(void)
{
	struct contact add;
	char name[30];
	char aname[30];
    	char anumber[30];
	char editnumber[50];
	char editname[50];
	
	FILE* fptr = NULL;
	FILE* ft = NULL;
	fptr = fopen("mycontacts.txt", "r");
	ft=fopen("mytemp.txt","a");
	
	printf("\n Enter Name :");
	scanf("\n%s", &name);
	
	while (fscanf (fptr, "%s\n%s\n", aname,anumber) != EOF)
	{
		// Assuming that a name could only have one instance
		if (strcmp(name,aname)== 0)
		{
			printf("\n%s" , aname);
			printf("\n%s\n" , anumber);
			
			printf("Enter edited name");
			scanf("%s",&editname);
			printf("Enter edited number");
			scanf("%s",&editnumber);
			
			fprintf(ft,"%s\n%s\n",editname,editnumber);
		}
		else
		{
			// if this is not the record to be edited then copy it as it is...
			fprintf(ft,"%s\n%s\n",aname,anumber);
		}
	}
	
	fclose(fptr);
	fclose(ft);
	remove("mycontacts.txt");
	rename("mytemp.txt","mycontacts.txt");
	return 0;
}

int deletecontact(void)
{
	struct contact add;
	char name[30];
	char aname[30];
    	char anumber[30];
	char edata[]={""};
	char edata1[]={""};
	int input;
	
	FILE* fptr = NULL;
	FILE* fp = NULL;
	fptr = fopen("mycontacts.txt", "r");
	fp=fopen("mytemp.txt","a");
	
	printf("\n Enter Name :");
	scanf("\n%s", &name);
	
	while (fscanf (fptr, "%s\n%s\n", aname,anumber) != EOF)
	{
		if (strcmp(name,aname)== 0)
		{
			printf("\n%s" , aname);
			printf("\n%s\n" , anumber);
			
			printf("do u want to delete contact");
			printf("\npress 1 to yes or 2 to no");
			scanf("%d",&input);
			
			if(input == 1)
			{
			fprintf(fp,"%s\n%s\n",edata,edata1);
		    }
		    else if(input == 2)
		    {
		    	main();
		    	return 1;
		    }

		}
		else
		{
			fprintf(fp,"%s\n%s\n",aname,anumber);
		}
	}
	
	fclose(fptr);
	fclose(fp);
	remove("mycontacts.txt");
	rename("mytemp.txt","mycontacts.txt");
	return 0;
}