#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void username();
void password();
void addbook();
void deletebook();
void searchbook();
void booklist();
void mainmenu();
void closeapp();
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct books
{
    int id;
    char stname[20];
    char bookname[20];
    char author[20];
    int quantity;
    float price;
    int rackno;

};
FILE *fp;
FILE *ft;
char findbook;
struct books info[100];
int size;
int p;
int press;
char name[]="user";
char word[]="password";
int main()
{
    username();

    return 0;
}
void username()
{

    char user[10];
    PRINT:printf("\n\n\n\n\n                                              ENTER USERNAME: ");
    scanf("%s", user);
    if(strcmp(user,name)==0)
    {
         password();
    }
    else{

        system("cls");
        printf("\a");
        goto PRINT;
    }
}
void password()
{
    int i=0,ch;
    char pass[10];
    PASSWORD:printf("                                              ENTER PASSWORD: ");

    scanf("%s", pass);
    if(strcmp(pass,word)==0)
    {
        system("cls");
        printf("\n\n\n\n                        ********************(Welcome To Management System)********************\n\n\n");
        printf("\n\n\n\n\n\n\n\n\n           \t\t\t\t  Press 1 to CONTINUUE and 0 to EXIT: ");
        line:scanf("%d",&press);
        if(press==1){
            system("cls");
            mainmenu();
        }
        else if(press=0){
                system("cls");
                closeapp();
        }

    }
    else
    {
        printf("\a");
        system("cls");
        printf("\n\n\n\n\n                                              ENTER USERNAME: %s\n",name);
        //goto PASSWORD;
        password();
    }
}

void addbook()
{
    system("cls");
    int i;
    fp=fopen("BookInfo.txt","a+");
    if(fp!=NULL)
    {

        printf("\n\n\n\t\t        ************************BOOK ENTRY SECTION***********************\n\n\n\n\n\n\n");
        for(i=0;i<100;i++)
        {
        fflush(stdin);
        printf("                                             Enter book name: ");
        scanf("%s", info[i].bookname);
        printf("                                             Enter book ID: ");
        scanf("%d", &info[i].id);
        fflush(stdin);
        printf("                                             Enter Author: ");
        scanf("%s", info[i].author);
        printf("                                             Enter quantity: ");
        scanf("%d", &info[i].quantity);
        printf("                                             Enter price: ");
        scanf("%f", &info[i].price);
        printf("                                             Enter rack no: ");
        scanf("%d", &info[i].rackno);
        break;
    }
    while(1)
    {
        fprintf(fp,"%s ",info[i].bookname);
        fprintf(fp,"%d ",info[i].id);
        fprintf(fp,"%s ",info[i].author);
        fprintf(fp,"%d ",info[i].quantity);
        fprintf(fp,"%0.2f ",info[i].price);
        fprintf(fp,"%d \n",info[i].rackno);
        printf("\n\n\t\t\t\t\tSuccessfully add student data.......\n");
        break;
    }
     fclose(fp);
    }

    printf("\n\n\t\t\t\tFor add another student details press 1 else 0: ");
    scanf("%d",&press);
    if(press==1){
        addbook();
    }
    else
        system("cls");
        mainmenu();
}

void mainmenu()
{
    printf("\n\n\n\n\n\n\n                                 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n\n\t\t\t\t\t    1. Add Books\n");
            printf("       \t\t\t\t\t    2. Delete books\n");
	        printf("       \t\t\t\t\t    3. Search Books\n");
	        printf("       \t\t\t\t\t    4. View Book list\n");
	        printf("       \t\t\t\t\t    5. Close Application\n");


	        printf("\n\n\n\n\n                                      Enter your choice...........");
	        switch(getch())
	{
		case '1':
		addbook();
		break;
	    case '2':
		deletebook();
		break;
		case '3':
		searchbook();
	    break;
	    case '4':
        system("cls");
		booklist();
		break;
	    case '5':
		{
		system("cls");
		printf("\n\n\n\n\n\n\n                                   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 THANK YOU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\nThis Program made by: \n");
		printf("_____________________________________\n");
		printf("NAME            : ABDULLAH AL SHAFI\n");
		printf("ID              : 1911515\n");
		printf("SEC             : 02\n\n\n\n\n\n\n");
		printf("THANKS TO:\n");
		printf("________________\n");
		printf("FACULTY         : MOHAMMAD SHAHRIAR HOSSAIN\n");
		printf("LAB INSTRUCTOR  : ANIS AHMED\n\n\n\n\n\n");



		printf("Exiting in 5 second...........\n");
		delay(5000);
		exit(0);
		}
		break;
		default :
            {
                printf("\n\n\n");
                printf("\t\t\t\t\aWrong Entry!!Please re-entered correct option");
                delay(3000);
                system("cls");
                mainmenu();

		if(getch())
		mainmenu();
		}
	}
}
void deletebook()
{
    system("cls");

    int i,k=0;
    fp=fopen("BookInfo.txt","r");
    if(fp!=NULL)
    {
    printf("\t\t\t\t\tDELETE SECTION\n");
    printf("\t\t\t\t\t_________________________\n\n\n");
    printf("\t\t\t\t\tEnter ID for delete student details : ");
    scanf("%d",&p);
    ft=fopen("amaze.txt","w");
    for(i=0;i<100;i++)
    {
        fscanf(fp,"%s",info[i].bookname);
        fflush(stdin);
        fscanf(fp,"%d",&info[i].id);
        fflush(stdin);
        fscanf(fp,"%s",info[i].author);
        fflush(stdin);
        fscanf(fp,"%d",&info[i].quantity);
        fscanf(fp,"%f",&info[i].price);
        fscanf(fp,"&d",&info[i].rackno);
            if(info[i].id!=p && info[i].id!='\0')
        {
            fprintf(ft,"%s ",info[i].bookname);
            fprintf(ft,"%d ",info[i].id);
            fprintf(ft,"%s ",info[i].author);
            fprintf(ft,"%d ",info[i].quantity);
            fprintf(ft,"%f ",info[i].price);
            fprintf(ft,"%d\n",info[i].rackno);
        }
        if(info[i].id==p)
        k++;
        else
            break;
    }
    fclose(ft);
    fclose(fp);
    remove("BookInfo.txt");
    rename("amaze.txt","BookInfo.txt");
    }
        if(k!=0)
        printf("\n\n\t\tStudent record successfully delete......");
    else
        printf("\n\n\t\tStudent record did not found!!!");
        printf("\nTry another search?(Y/N)");
        switch(getch())
        {
        case 'y':
        case 'Y':deletebook();
        break;
        case 'n':
        case 'N':
        system("cls");
        mainmenu();

        }
}
void booklist()
{
    system("cls");
    printf("\n\n\t\t\t\t\tBOOK LIST\n");
    printf("\t\t\t\t\t______________________________________\n\n\n");
    int flag=0;
    int i;
    fp=fopen("BookInfo.txt","r");
    if(fp!='\0')
    {
    for(i=0;i<100;i++)
    {
        fflush(stdin);
        fscanf(fp,"%s",info[i].bookname);
        fscanf(fp,"%d",&info[i].id);
        fflush(stdin);
        fscanf(fp,"%s",info[i].author);
        fscanf(fp,"%d",&info[i].quantity);
        fscanf(fp,"%f",&info[i].price);
        fscanf(fp,"%d",&info[i].rackno);
        if(info[i].id!='\0')
        {
            printf("\t\t\t\t\tBook Name: %s\n",info[i].bookname);
            printf("\t\t\t\t\tBook ID  : %d\n",info[i].id);
            printf("\t\t\t\t\tAuthor   : %s\n",info[i].author);
            printf("\t\t\t\t\tQuantity : %d\n",info[i].quantity);
            printf("\t\t\t\t\tPrice    : %0.2f\n",info[i].price);
            printf("\t\t\t\t\tRack no  : %d\n\n\n",info[i].rackno);
        }
        else if(info[i].id=='\0'){
            flag=1;
            break;
        }
        if(flag==1)
            printf("No Record Founnd!");
    }


    fclose(fp);
    }
    printf("press 1  to back to MAINMENU or 0 to EXIT : ");
    scanf("%d", &press);
    switch(press)
    {
    case 1:
        system("cls");
        mainmenu();
    case 2:
        closeapp();
    }

}
void searchbook()
{
    {
    system("cls");
    int i,k=0;
    fp=fopen("BookInfo.txt","r");
    if(fp!=NULL)
    {
        printf("\t\t\t\t\tSEARCH SECTION\n");
        printf("\t\t\t\t\t________________________________\n\n\n");
    printf("\t\t\t\t\tEnter ID for search student details : ");
    scanf("%d",&p);
    for(i=0;i<100;i++)
    {
        fscanf(fp,"%s",info[i].bookname);
        fflush(stdin);
        fscanf(fp,"%d",&info[i].id);
        fflush(stdin);
        fscanf(fp,"%s",info[i].author);
        fflush(stdin);
        fscanf(fp,"%d",&info[i].quantity);
        fscanf(fp,"%f",&info[i].price);
        fscanf(fp,"%d",&info[i].rackno);
            if(info[i].id==p)
        {
            k++;
            printf("\n\n\t\t\t\t\tBook Name    : %s\n",info[i].bookname);
            printf("\t\t\t\t\tBook ID      : %d\n",info[i].id);
            printf("\t\t\t\t\tAuthor       : %s\n",info[i].author);
            printf("\t\t\t\t\tQuantity     : %d\n",info[i].quantity);
            printf("\t\t\t\t\tPrice        : %f\n",info[i].price);
            printf("\t\t\t\t\tRack no      : %d\n\n",info[i].rackno);
            break;
        }
    }
    fclose(fp);
    }
    if(k==0)
        printf("\n\n\t\t\t\t\t\aBook record did not found!!!\n\n");
    printf("\t\t\tTry another search?(Y/N)");
    printf("\n\n\t\t\tpress 1  to back to MAINMENU or 0 to EXIT : ");
        switch(getch())
        {
        case 'y':
        case 'Y':searchbook();
        break;
        case 'n':
        case 'N':
        system("cls");
        mainmenu();
         case 1:
        system("cls");
        mainmenu();
    case 0:
        closeapp();
        }
        scanf("%d", &press);
    switch(press)
    {
    case 1:
        system("cls");
        mainmenu();
    case 0:
        closeapp();
       }

    }
}
void closeapp()
{
    exit(0);
}
