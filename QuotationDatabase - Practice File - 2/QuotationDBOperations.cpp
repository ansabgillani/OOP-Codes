#include<iostream>
#include"QuotationDBOperations.h"
using namespace std;



void createQuotationDatabase(char * * * quoteList, char * * * authorList, int capacity)
{
	if(quoteList)
	{
		freeQuotationDatabase(quoteList, *authorList, capacity);
	}
	*quoteList = new char *[capacity];
	for (int i = 0; i < capacity; i++)
	{
		*quoteList[i] = new char[100];
	}
	*authorList = new char *[capacity];
	for (int i = 0; i < capacity; i++)
	{
		*authorList[i] = new char[100];
	}
}
void addQuotation(char * * * quoteList, char * * & authorList, int * noq, int *	capacity, char * quote, char * author)
{
	if(!quoteList)
	{
		createQuotationDatabase(quoteList, &authorList, *capacity);
		noq=0;
	}
	if (*noq == *capacity)
	{
		resizeQuotationDatabase(*quoteList, authorList, *noq, *capacity);
	}
	else
	{
		copyString((*quoteList)[*noq], quote);
		copyString(authorList[*noq], author);
		*noq++;
	}
}
void displayAuthorWise(char * * & quoteList, char * * & authorList, int noq, char * author)
{
	if(noq>=0 && quoteList && authorList && author)
	{
		for(int i=0;i<noq;i++)
		{
			bool flag = true;
			for(int j=0;authorList[i][j]!='\0' && author[j]!='\0';j++)
			{
				if(author[j]!=authorList[i][j])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				cout<<"Author: "
				for(int j=0;authorList[i][j]!='0';j++)
				{
					cout<<authorList[i][j];	
				}
				cout<<"\nQuote: ";
				for(int j=0;quoteList[i][j]!='0';j++)
				{
					cout<<quoteList[i][j];	
				}	
			}
		}		
	}		
}
void displayQuotation(char * * & quoteList, char * * & authorList, int noq, char * quote)
{
	if(noq>=0 && quoteList && authorList && author)
	{
		for(int i=0;i<noq;i++)
		{
			bool flag = true;
			for(int j=0;quoteList[i][j]!='\0' && quote[j]!='\0';j++)
			{
				if(quote[j]!=quoteList[i][j])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				cout<<"Author: "
				for(int j=0;authorList[i][j]!='0';j++)
				{
					cout<<authorList[i][j];	
				}
				cout<<"\nQuote: ";
				for(int j=0;quoteList[i][j]!='0';j++)
				{
					cout<<quoteList[i][j];	
				}
				break;	
			}
		}		
	}		
}

}
void removeQuotation(char * * & quoteList, char * * & authorList, int &	noq, char *quote)
{
	if(noq>=0 && quoteList && authorList && author)
	{
		for(int i=0;i<noq;i++)
		{
			bool flag = true;
			for(int j=0;quoteList[i][j]!='\0' && quote[j]!='\0';j++)
			{
				if(quote[j]!=quoteList[i][j])
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				delete[] quoteList[i];
				delete[]  authorList[i];
				quoteList[i] = quoteList[noq - 1];
				authorList[i] = authorList[noq - 1];
				quoteList[noq-1] = '\0'
				authorList[noq-1] = '\0'
				noq--;
				break;	
			}
		}		
	}		

}
void freeQuotationDatabase(char * * * quoteList, char * * & authorList, int cap)
{
	if (quoteList && quthorList)
	{
		for (int i = 0; i < cap; i++)
		{
			delete[] (*quoteList)[i];
		}
		delete[] *quoteList;
		*quoteList = nullptr;
		for (int i = 0; i < cap; i++)
		{
			delete[] authorList[i];
		}
		delete[] authorList;
		authorList = nullptr;
	}
}
void resizeQuotationDatabase(char * * & quoteList, char * * & authorList, int noq, int & capacity)
{
	char **newQuoteList;
	char **newAuthorList;
	int newCapacity = capacity + capacity;
	createQuotationDatabase(&newQuoteList, &newAuthorList, newCapacity);
	for (int i = 0; i < noq ; i++)
	{
		copyString(newQuoteList[i], quoteList[i]);
		copyString(newAuthorList[i], authorList[i]);
	}
	freeQuotationDatabase(&quoteList, authorList, capacity);
	capacity = newCapacity;
	quoteList = newQuoteList;
	authorList = newAuthorList;
}
void copyString(char * destination, char * source)
{
	int i = 0;
	for (i = 0; source[i]!='\0'; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}
int compare(char * a, char * b)
{
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0')
	{
		if (a[i] != b[i])
		{
			if (a[i] > b[i])
			{
				return -1;
			}
			else if (a[i] < b[i])
			{
				return 1;
			}
		}
		else
		{
			i++;
		}
	}
	return 0;
}