#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "library.h"

int main(void)
{
    Library lib=newLibrary(50);
    Book a,b,c,d;
    a=newBook("001","mammt","fuck",12);
    b=newBook("002","garuda","your",7);
    c=newBook("003","loyd","dead",0);
    d=newBook("004","gwyn","momma",0);

    addBook(lib,a,getISBN(a));
    addBook(lib,b,getISBN(b));
    addBook(lib,c,getISBN(c));
    addBook(lib,d,getISBN(d));
    showLibrary(lib);

    addBookCopies(lib,"002",3);
    removeBookCopies(lib,"001",15);

    showLibrary(lib);

    Book temp=searchBook(lib,"004");
    if(temp!=NULL)
    {
        puts("The book you sought for is:");
        outputBook(temp);
        puts("");
    }

    noCopiesList(lib);

    destroyLibrary(&lib);
    return 0;
}