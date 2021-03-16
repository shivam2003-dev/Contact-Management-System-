#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct{
   char name[25];
   char phone[25]; 
      }c;
FILE *fp;
FILE *fp1;
int add_contact();
int view_contact();
int delete_contact();
int search_contact();
int edit_contact();
int main()
{
    system("cls");    /* ************Main menu ***********************  */
    int choice;
    printf("\n\t **** Welcome to Contact Management System ****");
    while(1){
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[6] Exit\n\t\t=================\n\t\t");

    printf("\n\t\tEnter the choice: ");

    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        add_contact();
        break;
    case 2:
        view_contact();
        break;
    case 3:
        search_contact();
        break;
    case 4:
        edit_contact();
        break;
    case 5:
        delete_contact();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("Invalid choice");
    }
  }
}
int add_contact()
{
    system("cls");
        char r[10];
        char number[10];
        gets(r);
        fp=fopen("contact.txt","a+");
        {
            printf("\n\n\n\t\t\t\tName : ");
            scanf("%s",c.name);
            printf("\n\t\t\t\tPhone Number : ");
            scanf("%s",&c.phone);
            
            fprintf(fp,"%s %s \n",c.name,c.phone);
            printf("\n\n\t\t\t\tRecord insert successful");

        }

       fclose(fp);

}
int view_contact()
{
    system("cls");
    fp=fopen("contact.txt","r");
    if(fp == NULL)
    {
        printf("file does not found !");
        exit(1);
    }
    else
    fp=fopen("contact.txt","r");
    {
        printf("\n\n\n\t\tName                 Phone number     ");
        printf("========================================================================================");
        while(fscanf(fp,"%s %s\n",c.name,c.phone)!=EOF)
        {
            printf("\n\nNAME: %s\t",c.name);
            printf("\tPHONE_NUMBER : %s",c.phone);
           
        }
        printf("\n\n=========================================================================================");

    }
   fclose(fp);

}
int delete_contact()
{
    system("cls");
     fp = fopen("contact.txt","r");
     fp1 = fopen("temp.txt","a");
     char number[100];
     char date[20];
     int f=0;
     printf("\n\n\n\t\t\t\tenter your name you want to Delete :  ");
     scanf("%s",&number);

     while(fscanf(fp,"%s %s \n",c.name,c.phone)!=EOF)
     {
            if(strcmp(c.name,number)==0)
            {
                    f =1;
                    printf("\n\n\n\t\t\t\tDelete successfull\n\n");
            }
            else
            {
                fprintf(fp1,"%s %s \n",c.name,c.phone);
            }

     }
     if(f==0)
     {
            printf("\n\n\t\t\tname not found");
     }
     fclose(fp);
     fclose(fp1);
     fp = fopen("contact.txt","w");
    fclose(fp);
     fp = fopen("contact.txt","a");
    fp1 = fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s \n",c.name,c.phone)!=EOF)
    {
        fprintf(fp,"%s %s \n",c.name,c.phone);
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("temp.txt","w");
    fclose(fp);

}
int search_contact()
{
    system("cls");
    char number[30];
    fp = fopen("contact.txt","r");
    printf("\n\n\n\t\t\t\tenter your name  :  ");
    scanf("%s",&number);
    if(fp == NULL)
    {
            printf("file does not found !");
            exit(1);
    }
    else{
        fp=fopen("contact.txt","r");
        {
            while(fscanf(fp,"%s %s \n",c.name,c.phone)!=EOF)
            {
                if(strcmp(c.name,number)==0)
                {
                    printf("\n\n\n\t\tName     \n");
                    printf("========================================================================================");
                    printf("\n\nNAME: %s",c.name);
                    printf("\nPHONE NUMBER : %s",c.phone);
                    printf("\n\n=========================================================================================");
                }

            }
        }
    }
    fclose(fp);

}
int edit_contact()
{
    system("cls");
    int choice;
    char number[50];
    char present[15];
    int f=0;
    fp = fopen("contact.txt","r");
    fp1 = fopen("temp.txt","a");
    printf("\n\n\t\t\twhat would you like to edit?");
    printf("\n\n\t\t\t[1] Name Edit ");
    printf("\n\t\t\t[2] Phone Number Edit ");
    printf("\n\t\t\t[5] Back To The Main Menu");
    printf("'\n\n\t\t\t Enter your choice : ");
    scanf("%d",&choice);
    if(choice == 1)
    {
        printf("\n\n\n\t\t\t\t Enter your Name :  ");
        scanf("%s",number);
        while(fscanf(fp,"%s %s \n",c.name,c.phone)!=EOF)
        {
            if(strcmp(c.name,number)==0)
            {
                f =1;
                printf("\n\n\t\t\tEnter The New Name :");
                scanf("%s",present);
                fprintf(fp1,"%s %s\n",present,c.phone);
                printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
            }
            else
            {
                fprintf(fp1,"%s %s \n",c.name,c.phone);
            }

        }
        if(f==0)
        {
            printf("\n\n\t\t\tName not found");
        }
        fclose(fp);
        fclose(fp1);
        fp = fopen("contact.txt","w");
        fclose(fp);
        fp = fopen("contact.txt","a");
        fp1 = fopen("temp.txt","r");
        while(fscanf(fp1,"%s %s \n",c.name,c.phone)!=EOF)
        {
           fprintf(fp,"%s %s \n",c.name,c.phone);
        }
        fclose(fp);
        fclose(fp1);
        fp = fopen("temp.txt","w");
        fclose(fp);
    }
    if(choice == 2)
    {
        printf("\n\n\n\t\t\t\t Enter your Name :  ");
        scanf("%s",number);
        while(fscanf(fp,"%s %s \n",c.name,c.phone)!=EOF)
        {
            if(strcmp(c.name,number)==0)
            {
                f =1;
                printf("\n\n\t\t\tEnter Your New Phone Number :");
                scanf("%s",present);
                fprintf(fp1,"%s %s \n",c.name,present);
                printf("\n\n\n\t\t\t\tsuccessfully update\n\n ");
            }
            else
            {
                fprintf(fp1,"%s %s \n",c.name,c.phone);
            }

        }
        if(f==0)
        {
            printf("\n\n\t\t\tName not found");
        }
        fclose(fp);
        fclose(fp1);
        fp = fopen("contact.txt","w");
        fclose(fp);
        fp = fopen("contact.txt","a");
        fp1 = fopen("temp.txt","r");
        while(fscanf(fp1,"%s %s \n",c.name,c.phone)!=EOF)
        {
           fprintf(fp,"%s %s \n",c.name,c.phone);
        }
        fclose(fp);
        fclose(fp1);
        fp = fopen("temp.txt","w");
        fclose(fp);
    }
    if(choice==5)
    {
        main();
    }

}