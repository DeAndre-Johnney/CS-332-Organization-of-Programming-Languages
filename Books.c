#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct Book{
    char name[MAX_SIZE];
    char authorName[MAX_SIZE];
    int yearReleased;
    struct Book *nextBook;
}Book;

void getData(struct Book *book){
    printf("Enter the name of the book: ");
    scanf("%s", book->name);
    printf("\nEnter the author's name: ");
    scanf("%s", book->authorName);
    printf("\nEnter the year the book was released: ");
    scanf("%d", &book->yearReleased);
    book->nextBook = NULL;
    printf("\nThe values have been updated in this address: %p", book);
}

void outputData(struct Book * book){
    printf("\nBook name: %s \t\tAuthor name: %s \t\tAddress: %p", book->name, book->authorName, book);
}

// Book *createBook(char[] title, char[] authName, int year){
//     Book *newBook = (Book *)malloc(sizeof(Book));
//     newBook->name = title;
//     newBook->authorName = authName;
//     newBook->yearReleased = year;
//     newBook->nextBook = NULL;
//     return newBook;
// }

int main(){
    struct Book header;
    int bookEnter;
    printf("How many books do you want to enter? ");
    scanf("%d", &bookEnter);
    Book *tail;
    for(int i =0; i < bookEnter; i++){
        if(i == 0){
            getData(&header);
            tail =  &header;
        }else{
            // struct Book temp;
            Book *temp = (Book *)malloc(sizeof(Book));

            getData(temp);
            tail->nextBook = temp;
            tail = tail->nextBook;
        }
    }

    //display books
    struct Book *navigator = header.nextBook;
    for(int j = 0; j < bookEnter; j++){
        if(j ==0)
        {
            outputData(&header);
        }
        else
        {
            outputData(navigator);
            navigator = navigator->nextBook;
        }
    }
}