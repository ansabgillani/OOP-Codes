#ifndef QUOTATION_DB_OPERATIONS_H
#define QUOTATION_DB_OPERATIONS_H



void createQuotationDatabase (char * * * quoteList, char * * * authorList, int capacity);
void addQuotation(char * * * quoteList, char * * & authorList, int * noq, int * capacity, char * qt, char * at);
void displayAuthorWise (char * * & quoteList, char * * & authorList, int noq, char * at);
void displayQuotation (char * * & quoteList, char * * & authorList, int noq, char * qt);
void removeQuotation (char * * & quoteList, char * * & authorList, int & noq, char *);
void freeQuotationDatabase (char * * * quoteList, char * * & authorList, int cap);


#endif