#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "library.h"

int main(void)
{
	Library lib=newLibrary();

    item a,b,c,d,e;
    a=newItem("001","peppe","be",12,0);
   	b=newItem("002","peppe","what",7,0);
    c=newItem("003","loyd","you",0,0);
    d=newItem("004","gwyn","want",0,0);
	e=newItem("005","peppe","phegit",7,0);
    addBook(lib,a);
    addBook(lib,b);
    addBook(lib,c);
    addBook(lib,d);
	addBook(lib,e);
    showLibrary(lib);
    	
    puts("loan added\n");
    loanBook(lib,getISBN(c));
    loanBook(lib,getISBN(b));
    showLibrary(lib);
	puts("loan removed\n");
    returnBook(lib,getISBN(c));
    returnBook(lib,getISBN(b));
    showLibrary(lib);	 
	
    showAuthorBooks(lib,"peppe");
	return 0;
}
