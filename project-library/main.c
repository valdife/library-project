#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    struct element *next;
    unsigned long val;
} ListElement;


ListElement *first;

typedef struct book {
    char title[100];
    int relaseYear;
    float price;
    char author1[100];
    char author2[100];
    char author3[100];
} Book;


int main()
{

    return 0;
}
