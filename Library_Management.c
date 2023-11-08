#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE sizeof(int)
typedef enum
{
    BOOK_NOT_FOUND,
    BOOK_FOUND
}Status_t;
typedef struct
{
    float Price;
    int id ;
    int Publication_Year;
    int Number_Of_Copies;
    char Book_Title[MAX_SIZE];
    char Auther_Name[MAX_SIZE];

}Book_t;
void Add_Book(Book_t Book_1[100], int *Id);
void Print_Book(Book_t Book_1[100],int *Id);
void Borrow_Book(Book_t Book_1[100], int *id, int book_id);
void Delete_Book(Book_t Book_1[100], int Delete, int *Id);
void Buy_Book(Book_t Book_1[100], int *id, int No_Of_Books_Buy, int book_id);
Book_t Book_1[100]={'\0'};

int main()
{
int Choose = 0;
int No_Of_Books = 0 ;
int Id = 0;
int No_Of_Books_Buy = 0 ;
int Delete = 0;

while(1)
{


    printf("****** Library Management System ******\n");
    printf("1: Add New Book\n");
    printf("2: Print Book List\n");
    printf("3: Borrow Book \n");    // No of copies --
    printf("4: Delete Book \n");
    printf("5: Buy Book \n");       // No of copies ++
    printf("6: Exit \n");

    printf("\nChoose option From (1 to 6) = ");
    scanf("%i", &Choose);

    switch(Choose)
    {
        case 1 :
            Add_Book(Book_1, &Id);

            break;
        case 2 :
            Print_Book(Book_1, &Id);
            break;
        case 3 :
            printf("Enter books id that you borrow :");
            scanf("%i", &No_Of_Books);
            Borrow_Book(Book_1, &Id, No_Of_Books);
            break;
        case 4 :

            printf("Enter Id of the book to delete :");
            scanf("%i", &Delete);
            Delete_Book(Book_1 , Delete,&Id);
            break;
        case 5 :
            printf("Enter books id that you buy :");
            scanf("%i", &No_Of_Books);
            printf("Enter No Of copies :");
            scanf("%i", &No_Of_Books_Buy);
            Buy_Book(Book_1 , &Id, No_Of_Books_Buy, No_Of_Books);
            break;
        case 6 :
            exit(1);
            break;
        default :
            printf("Invalid Choice !!\n\n");
    }
    printf("Press Any Key To Continue :\n\n");
    getch();
}

    return 0;
}
/* ----------------------------------------------------------------- */
void Add_Book(Book_t Book_1[100], int *Id)
{
    if(*Id == 100)
    {
        printf("Library is full \n");
    }
    else
    {
        printf("Enter ID : ");
        scanf("%i", &Book_1[*Id].id);
        fflush(stdin);
        printf("Enter book name : ");
        fflush(stdin);
        gets((Book_1[*Id].Book_Title));
        //scanf("%s", Book_1[*Id].Book_Title);


        printf("Enter author name : ");
        fflush(stdin);
        gets((Book_1[*Id].Auther_Name));
        //scanf("%s", Book_1[*Id].Auther_Name);

        printf("Enter number of copies : ");
        fflush(stdin);
        scanf("%i",&Book_1[*Id].Number_Of_Copies);


        printf("Enter Publication Year : ");
        fflush(stdin);
        scanf("%i",&Book_1[*Id].Publication_Year);

        printf("Enter Price : ");
        fflush(stdin);
        scanf("%f",&Book_1[*Id].Price);
        (*Id)++;
        printf("\n\n");
    }
}
/* ----------------------------------------------------------------- */
void Print_Book(Book_t Book_1[100],int *Id)
{

    for(int x = 0; x < *Id; x++)
    {
        printf("Book ID     = %i\n", Book_1[x].id);
        printf("Book name   = %s\n", Book_1[x].Book_Title);
        printf("Author name = %s\n", Book_1[x].Auther_Name);
        printf("Number of copies = %i\n", Book_1[x].Number_Of_Copies);
        printf("Publication Year = %i\n",Book_1[x].Publication_Year);
        printf("Price = %0.2f\n",Book_1[x].Price);
        printf("\n\n");
    }
}
/* ----------------------------------------------------------------- */
void Delete_Book(Book_t Book_1[100], int Delete, int *Id)
{
    for (int Index = Delete - 1 ; Index < *Id ; Index++)
    {
        Book_1[Index] = Book_1[Index + 1] ;
		
    }
    printf("The book is deleted from system successfully\n");
}
/* ----------------------------------------------------------------- */
void Borrow_Book(Book_t Book_1[100], int *Id, int book_id)
{

    for(int x = 0; x < *Id; x++)
    {
        if(Book_1[x].id == book_id)
        {
            if(Book_1[x].Number_Of_Copies == 0)
            {
                printf("There is no copies now, Please come after two weeks\n");
            }
            else
            {
                Book_1[x].Number_Of_Copies -= 1;
                printf("Number Of Copies Decreased Successfully\n");
            }
        }
        else
        {
            printf("Invalid book id \n");
        }
    }
}
/* ----------------------------------------------------------------- */
void Buy_Book(Book_t Book_1[100], int *Id, int No_Of_Books_Buy, int book_id)
{
    for(int x = 0; x < *Id ; x++)
    {
        if(Book_1[x].id == book_id)
        {
            Book_1[x].Number_Of_Copies += No_Of_Books_Buy;
        }
    }
}
