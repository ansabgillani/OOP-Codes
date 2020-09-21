#include "QuotationDBApplication.h"
#include "QuotationDBOperations.h"


void quotationDBApplication() {
char * * quoteList=0;
char * * authorList=0;
int numOfQuotations = 0;
int capacity = 10;
createQuotationDatabase(&quoteList, &authorList, capacity);
addQuotation(&quoteList, authorList, &numOfQuotations, &capacity,"Love Pakistan","Nayar Ali");
addQuotation(&quoteList, authorList, &numOfQuotations, &capacity,"Love Pakistan","Nayar Ali");
addQuotation(&quoteList, authorList, &numOfQuotations, &capacity,"Be Honest","Asif");
addQuotation(&quoteList, authorList, &numOfQuotations, &capacity,"Work Work and Work","Quad e Azam");
}


