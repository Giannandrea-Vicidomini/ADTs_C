typedef struct lib* Library;

Library newLibrary(const int size);
int addBook(const Library l,const Book b,char* const ISBN);
Book searchBook(const Library l,char* const ISBN);
int addBookCopies(const Library l,char* const ISBN,const int amount);
int removeBookCopies(const Library l,char* const ISBN,const int amount);
int showLibrary(const Library l);
int noCopiesList(const Library l);
int destroyLibrary(Library* const lptr);