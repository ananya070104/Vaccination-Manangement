#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    
    char name[30];
    int adhar_No[30];
    int age;
    int temperature;
    int blood_Pressure;
    long int mble_no;
    char sex[8];
    char mail[100];
};

// Defining person data type.
typedef struct person person;

// All function declaration.
void remove_all();
void print_menu();
void add_person();
void list_record();
void search_person();
void remove_person();
void update_person();
void take_input(person *p);


// Program starts here.
void start();
void login();
int main()
{
    login();
    start();
    return 0;
}

// This function will start our program.
void login() {

    char userids[5][10];
    strcpy(userids[0],"Kiran");
    strcpy(userids[1],"Ram");
    strcpy(userids[2],"Harini");
    strcpy(userids[3],"Sneha");


    char passwords[5][10];
    strcpy(passwords[0],"Confirm@#");
    strcpy(passwords[1],"ABC@123");
    strcpy(passwords[2],"Entry4me");
    strcpy(passwords[3],"Happy&987");
    char id[10];

    User:

    printf("Enter your id:\n");

    scanf("%s", &id);
    int flag = -1;
    for(int i=0;i<4;i++) {
        if(strcmp(id,userids[i])==0) {
            flag = i;
        }
    }
    if (flag!=-1)

    {

    printf("Id is correct\n");

    }

    else

    {

    printf("You have enetred an invalid user id\nPlease enter id again\n");


    goto User;

    }

    char pass[50];

    pass:

    printf("Enter your password: ");

    scanf("%s", &pass);
    
    if(strcmp(pass,passwords[flag])==0)

    {

    printf("You have successly loged in into Vaccination Management\n");

    }

    else

    {

    printf("You have entered a wrong password\nEnter your password again\n");

    goto pass;

    }
}
void start()
{
    int choice;
    while(1)
    {
        print_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                list_record();
                getchar();
                getchar();
                break;
            case 2:
                add_person();
                getchar();
                getchar();
                break;
            case 3:
                search_person();
                getchar();
                getchar();
                break;
            case 4:
                remove_person();
                getchar();
                getchar();
                break;
            case 5:
                update_person();
                getchar();
                getchar();
                break;
            case 6:
                remove_all();
                getchar();
                getchar();
                break;
            default :
                system("cls");
                printf("Thanks for using VACCINE MANAGEMENT SYSTEM  : )\n");
                getchar();
                getchar();
                exit(1);
        }
    }
}

// This will print main menu.
void print_menu()
{
    system("cls");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                  Welcome to get vaccinated                    *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t\t1) list record\n\n");
    printf("\t\t\t2) Add person\n\n");
    printf("\t\t\t3) Search person Details\n\n");
    printf("\t\t\t4) Remove person\n\n");
    printf("\t\t\t5) Update person\n\n");
    printf("\t\t\t6) Delete all contacts\n\n");
    printf("\t\t\t7) exit Vaccination management system\n\n\n");

    printf("\t\t\t\tEnter your Choice : ");
}

// This function will add contact into system.
void add_person()
{
    system("cls");
    FILE *fp;
    fp = fopen("system_db", "ab+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        take_input(&p);
        fwrite(&p, sizeof(p), 1, fp);
        fflush(stdin);
        fclose(fp);
        system("clear");
        printf("Record added Successfully\n");
        printf("Press any key to continue ....\n");

    }
}

// By this we take contact information.
void take_input(person *p)
{
    system("cls");
    // This getchar is for taking \n occured by previous functions.
    // So that scanset in scanf will work properly.
    getchar();
    printf("Enter name : ");
    // Here we are using scanset '^' - >  until get
    scanf("%[^\n]s",p->name);

    printf("Enter adhar No. : ");
    scanf("%s",p-> adhar_No); 

    printf("Enter age : ");
    scanf("%d",&p-> age); 

    printf("Enter temperature : ");
    scanf("%d",&p-> temperature); 

    printf("Enter blood Pressure : ");
    scanf("%d",&p-> blood_Pressure); 

    
    printf("Enter mobile no : ");
    scanf("%ld",&p->mble_no); 

    printf("Enter sex : ");
    scanf("%s",p->sex); 
    
    printf("Enter email : ");
    scanf("%s",p->mail); 
}

// This function will list contact available in system.
void list_record()
{
    system("cls");
    FILE *fp;
    fp = fopen("system_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        printf("\n\t\t\t\t******************************************************************************\n");
        printf("\t\t\t\t*                  Here is all records listed in vaccination system                 *\n");
        printf("\t\t\t\t******************************************************************************\n\n\n");
        printf("  NAME\t\t\t\t ADHAR NO\t\t AGE\t\t TEMPERATURE\t\t BP\t\t  PHONE NO\t\t SEX\t\t   EMAIL\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        // fseek(fp,-(sizeof(p)*2L),2);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            int i;
            int len1 = 40 - strlen(p.name);
            int len2 = 19 - strlen(p.adhar_No);
            int len3 = 17;
            int len4 = 18;
            int len5 = 16;
            int len6 = 19;
            int len7 = 21 - strlen(p.sex);
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");

            printf("%s",p.adhar_No);
            for(i=0;i<len2;i++) printf(" ");

            printf("%d",p.age);
            for(i=0;i<len3;i++) printf(" ");

            printf("%d",p.temperature);
            for(i=0;i<len4;i++) printf(" ");

            printf("%d",p.blood_Pressure);
            for(i=0;i<len5;i++) printf(" ");

            printf("%ld",p.mble_no);
            for(i=0;i<len6;i++) printf(" ");

            printf("%s",p.sex);
            for(i=0;i<len7;i++) printf(" ");

            printf("%s",p.mail);
            printf("\n");
            fflush(stdin);
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
        
    }
}

// This function will search contact in system.
void search_person()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to search : ");
    scanf("%ld",&phone);

    FILE *fp;
    fp = fopen("system_db", "rb");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                printf("  NAME\t\t\t\t   ADHAR NO\t\t   AGE\t\t    TEMP\t\t    BP\t\t    PHONE NO\t\t    SEX\t\t             EMAIL\n");
               
                printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
                int i;
                int len1 = 40 - strlen(p.name);
                int len2 = 19 - strlen(p.adhar_No);
                int len3 = 17;
                int len4 = 18;
                int len5 = 16;
                int len6 = 15;
                int len7 = 21 - strlen(p.sex);
            printf("%s",p.name);
            for(i=0;i<len1;i++) printf(" ");

            printf("%s",&p.adhar_No);
            for(i=0;i<len2;i++) printf(" ");

            printf("%d",p.age);
            for(i=0;i<len3;i++) printf(" ");

            printf("%d",p.temperature);
            for(i=0;i<len4;i++) printf(" ");

            printf("%d",p.blood_Pressure);
            for(i=0;i<len5;i++) printf(" ");

            printf("%ld",p.mble_no);
            for(i=0;i<len6;i++) printf(" ");

            printf("%s",p.sex);
            for(i=0;i<len7;i++) printf(" ");

            printf("%s",p.mail);
            printf("\n");
                
                flag = 1;
                break;
            }
            else continue;
            // fflush(stdin);
        }
        if(flag == 0) 
        {
            system("cls");
            printf("Person is not in the vaccination management system\n");
        }
        fflush(stdin);
        fclose(fp);
        printf("\n\nPress any key to continue....\n");
    }

}

// This function will remove contact from system.
void remove_person()
{
    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to remove from vaccination management system : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("system_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        person p;
        int flag = 0;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone)
            {
                system("cls");
                printf("Person removed successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %ld number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("system_db");
        rename("temp","system_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
        
    }

}

// This function will update contact information.
void update_person()
{

    system("cls");
    long int phone;
    printf("Enter Phone number of the person you want to update details : ");
    scanf("%ld",&phone);

    FILE *fp,*temp;
    fp = fopen("system_db", "rb");
    temp = fopen("temp","wb+");
    if (fp == NULL)
    {
        printf("Error in file opening, Plz try again !\n");
        printf("Press any key to continue....\n");
        return;
    }
    else
    {
        int flag = 0;
        person p;
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if(p.mble_no == phone) 
            {   
                take_input(&p);
                fwrite(&p, sizeof(p), 1, temp);
                system("cls");
                printf("Data updated successfully\n");
                flag = 1;
            }
            else fwrite(&p,sizeof(p),1,temp);
            fflush(stdin);
        }
        if(flag == 0)
        {
            system("cls");
            printf("No record found for %ld number\n",phone);
        }
        fclose(fp);
        fclose(temp);
        remove("system_db");
        rename("temp","system_db");
        fflush(stdin);
        printf("Press any key to continue....\n");
    }
}


// This function will clear all the data of system.
void remove_all()
{
    char choice;
    system("cls");
    remove("./system_db");
    printf("All data in the vaccine management system deleted successfully\n");
    printf("Press any key to continue ... \n");
}