#pragma once
#ifndef CSTRING_H
#define CSTRING_H
class CString
{
private:
	char * data;
	int size;
	int getLength(const char * s) const;
	bool isAlpha(const char c) const;
	bool isWhiteSpace(const char c) const;
	void copyString(char *destination, const char * source) const;
	bool isValidIndex(int index) const;
	float power(int base, int exp) const;
	int findCharacter(char *c, char* token);
public:
	CString();
	CString(const char c);
	CString(const char *);
	CString(const CString &);
	~CString();
	void input();
	void shrink();
	char & at(int index);
	const char & at(int index) const;
	bool isEmpty() const;
	int getLength() const;
	void display() const;
	int find(CString * subStr, int start = 0) const;
	void insert(int index, CString * subStr);
	void remove(int index, int count = 1);
	int replace(CString old, CString newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int);
	int compare(CString & s2) const;
	CString left(int count);
	CString right(int count);
	int toInteger() const;
	float toFloat() const;
	CString concat(CString s2) const;
	void concatEqual(CString s2);
	CString tokenize(CString delim);
};
#endif // !CSTRING_H
