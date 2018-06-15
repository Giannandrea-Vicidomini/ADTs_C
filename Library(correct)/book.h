typedef struct book* Book;

Book newBook(const char* code,const char* author,const char* title,const int copies);
Book cloneBook(const Book b);
int getCopies(const Book b);
int addCopies(const Book b,const int copies);
int removeCopies(const Book b,const int copies);
int outputBook(const Book b);
char* getISBN(const Book b);
int destroyBook(const Book b);