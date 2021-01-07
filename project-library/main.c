#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book {
    char title[100];
    int relaseYear;
    float price;
    char author1[100];
    char author2[100];
    char author3[100];
} Book;

typedef struct element {
    struct element *next;
    Book val;
} listElement;

listElement *library;
Book buffBook;


void appendList(listElement *list, Book newBook) {
    listElement *wsk, *newEl;
    wsk = list;
    while (wsk->next != NULL)
        wsk = wsk->next;
    newEl = (listElement*) malloc (sizeof(listElement));
    newEl->val = newBook;
    newEl->next = NULL;
    wsk->next = newEl;
}

void clearBuffBook() {
    strcpy(buffBook.title, "");
    buffBook.relaseYear = -1;
    buffBook.price = -1.1;
    strcpy(buffBook.author1, "");
    strcpy(buffBook.author2, "");
    strcpy(buffBook.author3, "");
}

// (a).
void printList(listElement *list) {
    FILE *fp = fopen("a.txt", "w");
    listElement *wsk = list;
    while (wsk != NULL) {
        printf("Tytul: %s\nRok wydania: %d  Cena: %.2f \nAutor1: %s Autor2: %s Autor3: %s\n\n",
                wsk->val.title, wsk->val.relaseYear, wsk->val.price, wsk->val.author1, wsk->val.author2, wsk->val.author3);
        fprintf(fp, "Tytul: %s\nRok wydania: %d  Cena: %.2f \nAutor1: %s Autor2: %s Autor3: %s\n\n",
                 wsk->val.title, wsk->val.relaseYear, wsk->val.price, wsk->val.author1, wsk->val.author2, wsk->val.author3);
        wsk = wsk->next;
    }
    fclose(fp);
}

void printOldestBookPrice(listElement *list) {

}

//strcmp(TEKST1,TEKST2) - zwraca 0 jak sa takie same, cos innego jak nie

int main()
{
    int end = 0;
    char option;
    FILE *fp1 = fopen("database.txt", "r");
    if (fp1 == NULL) {
        printf("Plik sie nie otworzyl.");
        return 1;
    }
    fscanf(fp1, "%s %d %f %s %s %s", buffBook.title, &buffBook.relaseYear,
        &buffBook.price, buffBook.author1, buffBook.author2, buffBook.author3);

    library = (listElement*) malloc (sizeof(listElement));
    library->val = buffBook;
    library->next = NULL;
    clearBuffBook();

    while(fscanf(fp1, "%s %d %f %s %s %s", buffBook.title, &buffBook.relaseYear,
                  &buffBook.price, buffBook.author1, buffBook.author2, buffBook.author3) != EOF) {
        appendList(library, buffBook);
        clearBuffBook();
    }
    while(!end) {
        printf("\nWitaj w aplikacji Biblioteka! Oto zestaw dostepnych opcji:\n1. Wypisz ksiegozbior biblioteki.\n2. Wypisz cene najstarszej ksiazki (badz sredniejcen najstarszych ksiazek)\n3. Wyjdz z programu.\n\n");
        fflush(stdin);
        scanf("%c", &option);
        switch(option) {
            case '1':
                printList(library);
                break;
            case '2':
                printOldestBookPrice(library);
                break;
            case '3':
                end = 1;
                break;
            default:
                printf("Nie ma opcji o podanym numerze, sprobuj ponownie.");
                break;
        }
    }
    fclose(fp1);
    return 0;
}
