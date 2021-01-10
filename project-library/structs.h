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

typedef struct authorElem {
    struct authorElem *next;
    char val[100];
} authorElem;

void appendList(listElement *list, Book newBook) {
    listElement *pt, *newEl;
    pt = list;
    while (pt->next != NULL)
        pt = pt->next;
    newEl = (listElement*) malloc (sizeof(listElement));
    newEl->val = newBook;
    newEl->next = NULL;
    pt->next = newEl;
}

void appendAuthorList(authorElem *list, char author[100]) {
    authorElem *pt, *newEl;
    pt = list;
    while (pt->next != NULL)
        pt = pt->next;
    newEl = (authorElem*) malloc (sizeof(authorElem));
    strcpy(newEl->val, author);
    newEl->next = NULL;
    pt->next = newEl;
}
