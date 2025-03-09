#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct train_resevation
{
    char train_name[30];
    int train_no;
    char timing[10];
};

struct passenger
{
    char name[50];
    int age;
    char gen[5];
    int seat_no;
};
struct train_resevation train[50];
struct passenger pas[50];
int count, flag = 0;
//*************************************************************************
//THIS IS A PROTOTYPE OF ALL THE FUNCTION USED IN THIS PROGRAM.
//*************************************************************************
void menu();
void addtrain();
void availabletrain();
void search();
void bookticket();
void cancelticket();
void detail();
//**************************************************************************
//THIS IS THE MAIN FUNCTION OF THE PROGRAM WHERE ALL FUNCTION WILL CALL
//**************************************************************************
void menu()
{
    printf("\n****************RAILWAY RESERVATION SYSTEM*************************\n");
    printf("1.CHECK AVAILABLE TRAIN\n");
    printf("2.SEARCH TRAIN\n");
    printf("3.BOOK TICKET\n");
    printf("4.CANCEL TICKET\n");
    printf("5.PASSENGER DETAILS\n");
    printf("6.EXIT\n");
    printf("***********************************************************************\n\n");
}
int main()
{
    int n;
    printf("***********\n");
    printf("* 1.ADMIN *\n");
    printf("* 2.USER  *\n");
    printf("***********\n\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &n);
    if (n == 1)
        addtrain();
    else if(n==2)
    {
        do
        {
            menu();
            int choice;
            printf("ENTER YOUR CHOICE\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                availabletrain();
                break;
            case 2:
                search();
                break;
            case 3:
                bookticket();
                break;
            case 4:
                cancelticket();
                break;
            case 5:
                detail();
                break;
            case 6:
                exit(0);
            default:
                printf("INVALID INPUT\n");
            }

        } while (1);
    }
    else
    printf("INVALID INPUT.");
}
//*******************************************************************************************************
void addtrain()
{
    printf("PLEASE ADD TRAIN DETAILS\n");
    printf("HOW MANY TRAINS YOU WANT TO ENTER: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        printf("\nENTER DETAILS OF TRAIN %d.\n ", i + 1);
        printf("ENTER TRAIN NAME: ");
        scanf("%s", train[i].train_name);
        printf("ENTER TRAIN NUMBER: ");
        scanf("%d", &train[i].train_no);
        printf("ENTER TRAIN TIMING(HH:MM): ");
        scanf("%s", train[i].timing);
    }
    main();
}
//***************************************************************************************************
void availabletrain()
{
    if (count > 0)
    {
        printf("%-15s%-10s%-6s\n", "TRAIN NAME", "TRAIN NO", "TRAIN TIMING");
        for (int i = 0; i < count; i++)
        {
            printf("%-15s%-10d%-6s\n", train[i].train_name, train[i].train_no, train[i].timing);
        }
    }
    else
        printf("NO TRAIN AVAILABLE.\n");
}
//****************************************************************************************************
void search()
{
    char temp[20];
    if (count > 0)
    {
        printf("ENTER TRAIN NAME TO SEARCH: ");
        scanf("%s", temp);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(train[i].train_name, temp) == 0)
            {
                printf("TRAIN NAME: %s\n", temp);
                printf("TRAIN NO: %d\n", train[i].train_no);
                printf("TRAIN TIMING: %s\n", train[i].timing);
                return;
            }   
        }
        printf("TRAIN NOT FOUND\n");
    }
    else
        printf("THERE IS NO TRAIN AVAILABLE.\n");
}
//******************************************************************************************************
void bookticket()
{
    if (count > 0)
    {
        char temp[20];
        printf("ENTER TRAIN NAME TO BOOK TICKET: ");
        scanf("%s", temp);
        for (int i = 0; i < count; i++)
        {
            if (strstr(train[i].train_name, temp))
            {
                int choice;
                printf("1.AC TIER\n");
                printf("2.SLEEPER\n");
                printf("3.GENERAL\n");
                printf("ENTER YOUR CHOICE: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("\nADD DETAILS OF PASSENGER\n");
                    printf("ENTER PASSENGER NAME: ");
                    scanf("%s", pas[flag].name);
                    printf("ENTER AGE: ");
                    scanf("%d", &pas[flag].age);
                    printf("ENTER GENDER(M/F): ");
                    scanf("%s", pas[flag].gen);
                    pas[flag].seat_no = flag + 1;
                    printf("YOUR SEAT NO.:%d\n", pas[flag].seat_no);
                    flag++;
                    printf("TOTAL BILL: Rs2000\n");
                    printf("YOUR TICKET HAS BEEN BOOKED SUCESSFULLY;\n");
                    break;
                case 2:
                    printf("ENTER PASSENGER NAME: ");
                    scanf("%s", pas[flag].name);
                    printf("ENTER AGE: ");
                    scanf("%d", &pas[flag].age);
                    printf("ENTER GENDER(M/F): ");
                    scanf("%s", pas[flag].gen);
                    pas[flag].seat_no = flag + 1;
                    printf("YOUR SEAT NO.:%d\n", pas[flag].seat_no);
                    flag++;
                    printf("TOTAL BILL: Rs800\n");
                    printf("YOUR TICKET HAS BEEN BOOKED SUCESSFULLY;\n");
                    break;
                case 3:
                    printf("\nADD DETAILS OF PASSENGER\n");
                    printf("ENTER PASSENGER NAME: ");
                    scanf("%s", pas[flag].name);
                    printf("ENTER AGE: ");
                    scanf("%d", &pas[flag].age);
                    printf("ENTER GENDER(M/F): ");
                    scanf("%s", pas[flag].gen);
                    pas[flag].seat_no = flag + 1;
                    printf("YOUR SEAT NO.:%d\n\n", pas[flag].seat_no);
                    flag++;
                    printf("TOTAL BILL: Rs350\n");
                    printf("YOUR TICKET HAS BEEN BOOKED SUCESSFULLY;\n");
                    break;
                default:
                    printf("INVALID INPUT");
                }
            }
        }
    }
    else
        printf("TRAIN NOT AVAILABLE.\n");
}
//******************************************************************************************************
void cancelticket()
{
    if (flag > 0)
    {
        int c;
        printf("ENTER SEAT NUMBER TO CANCEL YOUR TICKET: ");
        scanf("%d", &c);
        for (int i = 0; i < flag; i++)
        {
            if (pas[i].seat_no == c)
            {
                for (int j = i; j < flag - 1; j++)
                {
                    pas[j] = pas[j + 1];
                    --pas[j].seat_no;
                }
                flag--;
            }
        }
        printf("\nTICKET CANCELLED SUCESSFULLY\n");
    }
    else
        printf("YOU DIDN'T BOOK A TICKET.\n");
}
//******************************************************************************************************
void detail()
{
    if (flag > 0)
    {
        printf("%-10s%-10s%-10s%-10s\n", "NAME", "AGE", "GENDER", "SEAT NO");
        for (int i = 0; i < flag; i++)
        {
            printf("%-10s%-10d%-10s%-10d\n", pas[i].name, pas[i].age, pas[i].gen, pas[i].seat_no);
        }
    }
    else
        printf("PASSENGER DETAIL IS EMPTY\n");
}
