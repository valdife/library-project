#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

listElement *library;
authorElem *authors;
Book buffBook;

void bubbleSort(int tab[], int size) {
    int tempVal, i, j, changed;
    for (i = 0; i < size - 1; i++) {
        if (tab[i] == 0)
            break;
        changed = 0;
        for (j = 0; j < size - 1 - i; j++) {
            if (tab[j+1] == 0)
                break;
            if (tab[j] > tab[j+1]) {
                tempVal = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tempVal;
                changed = 1;
            }
        }
        if (!changed) break;
    }
}

int isExist(int tab[], int examined, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (tab[i] == 0) break;
        if (tab[i] == examined) return 1;
    }
    return 0;
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
    listElement *pt = list;
    while (pt != NULL) {
        printf("Tytul: %s\nRok wydania: %d  Cena: %.2f \nAutor1: %s   Autor2: %s   Autor3: %s\n\n",
                pt->val.title, pt->val.relaseYear, pt->val.price, pt->val.author1, pt->val.author2, pt->val.author3);
        fprintf(fp, "Tytul: %s\nRok wydania: %d  Cena: %.2f \nAutor1:%s   Autor2:%s   Autor3: %s\n\n",
                 pt->val.title, pt->val.relaseYear, pt->val.price, pt->val.author1, pt->val.author2, pt->val.author3);
        pt = pt->next;
    }
    fclose(fp);
}
// (b).
void printOldestBookPrice(listElement *list) {
    FILE *fp = fopen("b.txt", "w");
    listElement *pt = list;
    int earliestRelaseYear = 3000, oldestsCount = 1, bookRelYear;
    float price = 0.0, bookPrice;

    while (pt != NULL) {
        bookRelYear = pt->val.relaseYear;
        bookPrice = pt->val.price;
        if (bookRelYear == earliestRelaseYear) {
            oldestsCount++;
            price += bookPrice;
        }
        if (bookRelYear < earliestRelaseYear) {
            earliestRelaseYear = bookRelYear;
            price = bookPrice;
            oldestsCount = 1;
        }
        pt = pt->next;
    }
    price /= oldestsCount;
    if (oldestsCount != 1) {
        printf("Srednia cen najstarszych (rok wydania: %d) ksiazek w bibliotece: %.2f \n", earliestRelaseYear, price);
        fprintf(fp, "Srednia cen najstarszych (rok wydania: %d) ksiazek w bibliotece: %.2f \n", earliestRelaseYear, price);
    }
    else {
        printf("Cena najstarszej (rok wydania: %d) ksiazki w bibliotece: %f \n", earliestRelaseYear, price);
        fprintf(fp, "Srednia cen najstarszych (rok wydania: %d) ksiazek w bibliotece: %.2f \n", earliestRelaseYear, price);
    }
    fclose(fp);
}
// (c).
void printBooksOfAuthor(listElement *list, char author[]) {
    int found;
    if(!strcmp(author, "X"))
        printf("Znak X nie jest autorem, wprowadz poprawna nazwe autora. Resetuje program...\n");
    else {
        FILE *fp = fopen("c.txt", "w");
        listElement *pt = list;
        printf("\nPosiadane ksiazki autorstwa %s: \n\t", author);
        fprintf(fp, "Posiadane ksiazki autorstwa %s: \n\t", author);
        while (pt != NULL) {
            if (!strcmp(pt->val.author1, author) || !strcmp(pt->val.author2, author)
            || !strcmp(pt->val.author3, author)) {
                fprintf(fp, "%s, ", pt->val.title);
                printf("%s, ", pt->val.title);
                found = 1;
            }
            pt = pt->next;
        }
        if (!found) printf("Nie znaleziono zadnej ksiazki tego autora w bibliotece!");
        printf("\n");
        fclose(fp);
    }
}
// (d).
void printYearsReport(listElement *list) {
    FILE *fp = fopen("d.txt", "w");
    listElement *pt = list;
    int yearsTab[1000] = {0}, i = 0, j = 0;
    int size = sizeof(yearsTab)/sizeof(int);

    while (pt != NULL) {
        if (!isExist(yearsTab, pt->val.relaseYear, size)) {
            yearsTab[i] = pt->val.relaseYear;
            i++;
        }
        pt = pt->next;
    }
    bubbleSort(yearsTab, size);

    printf("Ksiazki posortowane wedlug rocznika: \n");
    fprintf(fp,"Ksiazki posortowane wedlug rocznika: \n");
    for(j = 0; j < i; j++) {
        pt = list;
        printf("\tRok %d: \n", yearsTab[j]);
        fprintf(fp,"\tRok %d: \n", yearsTab[j]);
        while (pt != NULL) {
            if (pt->val.relaseYear == yearsTab[j]) {
                printf("\t\tTytul: %s\n\t\tAutor nr 1: %s\n\n", pt->val.title, pt->val.author1);
                fprintf(fp,"\t\tTytul: %s\n\t\tAutor nr 1: %s\n\n", pt->val.title, pt->val.author1);
            }
            pt = pt->next;
        }
    }

    fclose(fp);
}
// (e).
void printAllBooksOfAllAuthors(listElement *list) {
    FILE *fp = fopen("e.txt", "w");
    authors = (authorElem*) malloc (sizeof(authorElem));
    listElement *bookPt = list;
    authorElem *authorPt = authors;
    strcpy(authors->val, bookPt->val.author1);
    authors->next = NULL;
    char except[] = "X";
    int flag1, flag2, flag3;
    char author1[100], author2[100], author3[100], authorFromList[100];

    while (bookPt != NULL) {
        flag1 = 1; flag2 = 1; flag3 = 1;
        strcpy(author1, bookPt->val.author1);
        strcpy(author2, bookPt->val.author2);
        strcpy(author3, bookPt->val.author3);
        while (authorPt != NULL) {
            strcpy(authorFromList, authorPt->val);
            if ((strcmp(authorFromList,author1) == 0))
                flag1 = 0;
            if ((strcmp(authorFromList,author2) == 0) || (strcmp(author2,except) == 0))
                flag2 = 0;
            if ((strcmp(authorFromList,author3) == 0) || (strcmp(author3,except) == 0))
                flag3 = 0;
            authorPt = authorPt->next;
        }
        if (flag1)
            appendAuthorList(authors, author1);
        if (flag2)
            appendAuthorList(authors, author2);
        if (flag3)
            appendAuthorList(authors, author3);
        authorPt = authors;
        bookPt = bookPt->next;
    }

    bookPt = list;
    authorPt = authors;

    while (authorPt != NULL) {
        strcpy(authorFromList, authorPt->val);
        printf("Posiadamy nastepujace ksiazki autorstwa %s: \n", authorFromList);
        fprintf(fp, "Posiadamy nastepujace ksiazki autorstwa %s: \n", authorFromList);
        while (bookPt != NULL) {
            strcpy(author1, bookPt->val.author1);
            strcpy(author2, bookPt->val.author2);
            strcpy(author3, bookPt->val.author3);

            if ((strcmp(authorFromList, author1) == 0) || (strcmp(authorFromList, author2) == 0)
                || (strcmp(authorFromList, author3) == 0)) {
                printf("\tTytul ksiazki: %s\n", bookPt->val.title);
                fprintf(fp, "\tTytul ksiazki: %s\n", bookPt->val.title);
            }
            bookPt = bookPt->next;
        }
        bookPt = list;
        authorPt = authorPt->next;
        printf("\n");
    }

    fclose(fp);
}

int main()
{
    int end = 0;
    char option, author[100];
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
        printf("\nWitaj w aplikacji Biblioteka! Oto zestaw dostepnych opcji:\n1. Wyswietl ksiegozbior biblioteki.\n2. Wyswietl cene najstarszej ksiazki (badz sredniejcen najstarszych ksiazek)");
        printf("\n3. Wyswietl dostepne ksiazki wskazanego autora.\n4. Wykonaj raport grupujacy ksiazki wedlug roku ich wydania\n5. Wyswietl wszystkie tytuly z ksiegozbioru pogrupowane wedlug autora.\n6. Wyjdz z programu.\n\n");
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
                printf("Podaj autora szukanych ksiazek: ");
                fflush(stdin);
                scanf("%s", author);
                printBooksOfAuthor(library, author);
                break;
            case '4':
                printYearsReport(library);
                break;
            case '5':
                printAllBooksOfAllAuthors(library);
                break;
            case '6':
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
