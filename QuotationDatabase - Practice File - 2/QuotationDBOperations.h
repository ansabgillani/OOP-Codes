#ifndef QUOTE_DB_OPPERATIONS_H
#define QUOTE_DB_OPPERATIONS_H

void createQuotationDatabase(char * * * quoteList, char * * * authorList, int capacity);
void addQuotation(char * * * quoteList, char * * & authorList, int * noq, int * capacity, char * quote, char * author);
void displayAuthorWise(char * * & quoteList, char * * & authorList, int noq, char * author);
void displayQuotation(char * * & quoteList, char * * & authorList, int noq, char * quotet);
void removeQuotation(char * * & quoteList, char * * & authorList, int & noq, char *quote);
void freeQuotationDatabase(char * * * quoteList, char * * & authorList, int cap);
void resizeQuotationDatabase(char * * & quoteList, char * * & authorList, int noq, int & Capacity);
void copyString(char * destination, char * source);

#endif