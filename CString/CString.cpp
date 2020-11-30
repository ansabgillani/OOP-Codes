#include<iostream>
#include"CString.h"
using namespace std;
CString::CString()
{
	data = nullptr;
	size = 0;
}
CString::CString(const char c)
{
	data = new char[2]{ c,'\0' };
	size = 2;
}
CString::CString(const char *s)
{
	size = getLength(s);
	size = size + 1;
	data = new char[size];
	copyString(data, s);
}
CString::CString(const CString &obj)
{
	size = obj.size;
	data = new char[obj.size];
	copyString(data, obj.data);
}
int CString::getLength(const char * s) const
{
	int i = 0;
	while (s[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
void CString::copyString(char *destination, const char * source) const
{
	int i = 0;
	for (i = 0; source[i] != '\0'; i = i + 1)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';
}
CString::~CString()
{
	if (data)
	{
		delete[] data;
	}
	data = nullptr;
	size = 0;
}
void CString::input()
{
	if (data)
	{
		int sizeCounter = 0;
		char c;
		c = cin.get();
		while (c != '\n')
		{
			if (sizeCounter == size - 1)
				reSize(size * 2);
			data[sizeCounter] = c;
			sizeCounter = sizeCounter + 1;
			c = cin.get();
		}
		shrink();
	}
}
char & CString::at(int index)
{
	if (isValidIndex(index))
		return data[index];
	else
		exit(0);
}
const char & CString::at(int index) const
{
	if (isValidIndex(index))
		return data[index];
	else
		exit(0);
}
bool CString::isValidIndex(int index) const
{
	return (index >= 0 && index < getLength() + 1);
}
void CString::shrink()
{
	if (data)
	{
		reSize(getLength() + 1);
	}
	else
		exit(0);
}
bool CString::isEmpty() const
{
	return (size == 0);
}
int CString::getLength() const
{
	if (data)
	{
		int len = getLength(data);
		return len;
	}
	else
		return 0;
}
void CString::display() const
{
	if (data)
		cout << data;
}
int CString::find(CString * subStr, int start) const
{
	if (data && subStr->data && start >= 0 && start < getLength())
	{
		int i, count = 0;
		for (i = start; data[i] != '\0'; i = i + 1)
		{
			if (data[i] == subStr->data[0])
			{
				int j = 1;
				while (subStr->data[j] != '\0' && data[i + j] != subStr->data[j])
				{
					j = j + 1;
				}
				if (subStr->data[j] == '\0')
				{
					count = count + 1;
				}
			}
		}
	}
	else
		return -1;
}
void CString::insert(int index, CString * subStr)
{
	int i = 0, j = 0;
	if (subStr->data && index >= 0 && index < getLength() + 1)
	{
		reSize(getLength() + subStr->getLength());
		for (i = 0; i < subStr->data[i] != '\0'; i = i + 1)
		{
			int len = getLength();
			for (j = len + 1; j > index; j--)
			{
				data[j] = data[j - 1];
			}
			data[index] = subStr->data[i];
			index = index + 1;
		}
		data[getLength()] = '\0';
	}
	else
		exit(0);
}
void CString::remove(int index, int count)
{
	int i = 0, j = 0;
	if (data && isValidIndex(index) && count < getLength() + 1)
	{
		while (count != 0)
		{
			for (j = index; j < getLength(); j = j + 1)
			{
				data[j] = data[j + 1];
			}
			count = count - 1;
		}
		shrink();
	}
	else
		exit(0);
}
int CString::replace(CString old, CString newSubStr)
{
	if (data && newSubStr.data)
	{
		int i, count = 0;
		for (i = 0; data[i] != '\0'; i = i + 1)
		{
			if (data[i] == old.data[0])
			{
				int j = 1;
				while (old.data[j] != '\0' && data[i + j] == old.data[j])
				{
					j = j + 1;
				}
				if (old.data[j] == '\0')
				{
					remove(i, old.getLength());
					insert(i, &newSubStr);
					count = count + 1;
				}
			}
		}
		return count;
	}
	else
		exit(0);
}
bool CString::isAlpha(const char c) const
{
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}
bool CString::isWhiteSpace(const char c) const
{
	return (c == ' ' || c == '\t' || c >= '\n' || c <= '\v' || c <= '\f' || c <= '\r');
}
void CString::trimLeft()
{
	if (data)
	{
		int i = 0;
		while (!isAlpha(data[i]) && data[i] != '\0')
		{
			i = i + 1;
		}
		remove(0, i);
	}
	else
		exit(0);
}
void CString::trimRight()
{
	if (data)
	{
		int i = size - 2;
		while (!isAlpha(data[i]) && i >= 0)
		{
			if (isWhiteSpace(data[i]))
			{
				remove(i);
			}
			i--;
		}
	}
	else
		exit(0);
}
void CString::trim()
{
	trimLeft();
	trimRight();
}
void CString::makeUpper()
{
	if (data)
	{
		for (int i = 0; data[i] != '\0'; i = i + 1)
		{
			if (data[i] >= 97 && data[i] <= 122)
			{
				data[i] = data[i] - 32;
			}
		}
	}
	else
		exit(0);
}
void CString::makeLower()
{
	if (data)
	{
		for (int i = 0; data[i] != '\0'; i = i + 1)
		{
			if (data[i] >= 65 && data[i] <= 90)
			{
				data[i] = data[i] + 32;
			}
		}
	}
	else
		exit(0);
}
void CString::reverse()
{
	if (data)
	{
		int len = size - 1;
		int index = len / 2;
		for (int i = 0; i < index; i = i + 1)
		{
			char temp;
			temp = data[i];
			data[i] = data[len - 1];
			data[len - 1] = temp;
			len = len - 1;
		}
	}
	else
		exit(0);
}
void CString::reSize(int newSize)
{
	newSize = newSize + 1;
	char * newData = new char[newSize];
	int i = 0;
	for (i = 0; i < getLength() && i < newSize - 1; i = i + 1)
	{
		newData[i] = data[i];
	}
	newData[i] = '\0';
	delete[] data;
	data = newData;
	size = newSize;
}
int CString::compare(CString & s2) const
{
	if (data && s2.data)
	{
		int i = 0;
		if (size == s2.size)
		{
			while (data[i] != '\0' && s2.data[i] != '\0')
			{
				if (data[i] != s2.data[i])
				{
					if (data[i] > s2.data[i])
					{
						return -1;
					}
					else if (data[i] < s2.data[i])
					{
						return 1;
					}
				}
				else
				{
					i = i + 1;
				}
			}
			return 0;
		}
		else if (size < s2.size)
			return 1;
		else
			return -1;
	}
	else
		exit(0);
}
CString CString::left(int count)
{
	if (count < getLength() + 1)
	{
		CString left;
		char * leftChar = new char[count + 1];
		int i;
		for (i = 0; i < count; i = i + 1)
		{
			leftChar[i] = data[i];
		}
		leftChar[i] = '\0';
		left.data = leftChar;
		left.size = count + 1;
		leftChar = nullptr;
		return left;
	}
	else
		exit(0);
}
CString CString::right(int count)
{
	if (count < getLength() + 1)
	{
		CString right;
		char * rightChar = new char[count + 1];
		int i, j = 0;
		for (i = getLength() - count; i < getLength(); i = i + 1)
		{
			rightChar[j] = data[i];
			j = j + 1;
		}
		rightChar[j] = '\0';
		right.data = rightChar;
		right.size = count + 1;
		rightChar = nullptr;
		return right;
	}
	else
		exit(0);
}
int CString::toInteger() const
{
	int i = 0, num = 0;
	while (data[i] != '\0')
	{
		if (data[i]<48 || data[i]>57)
			i = i + 1;
		else
		{
			num = num * 10 + ((int)data[i] - 48);
			i = i + 1;
		}
	}
	if (data[0] == '-')
		return -num;
	else
		return num;
}
float CString::toFloat() const
{
	int i = 0;
	float num = 0;
	while (data[i] != '.')
	{
		if (data[i]<48 || data[i]>57)
			i = i + 1;
		else
		{
			num = num * 10 + ((int)data[i] - 48);
			i = i + 1;
		}
	}
	int p = 1;
	while (data[i] != '\0')
	{
		if (data[i]<48 || data[i]>57)
			i = i + 1;
		else
		{
			num = num + ((int)data[i] - 48) / power(10, p);
			i = i + 1;
			p = p + 1;
		}
	}
	if (data[0] == '-')
		return -num;
	else
		return num;
}
float CString::power(int base, int exp) const
{
	float pow = 1;
	while (exp > 0)
	{
		pow = pow*base;
		exp--;
	}
	return pow;
}
CString CString::concat(CString s2) const
{
	CString add(data);
	add.concatEqual(s2);
	return add;
}
void CString::concatEqual(CString s2)
{
	if (size < (size + s2.size))
		reSize(getLength() + s2.getLength());
	int len = getLength();
	for (int i = 0; s2.data[i] != '\0'; i = i + 1)
	{
		data[len + i] = s2.data[i];
	}
	data[size - 1] = '\0';
}
CString CString::tokenize(CString delim)
{
	CString token;
	int i = 0;
	int pos = findCharacter(delim.data, data);
	if (pos != -1)
	{
		char * t = new char[pos + 1];
		int l;
		for (l = 0; l < pos; l = l + 1)
		{
			t[l] = data[l];
		}
		t[l] = '\0';
		token.data = t;
		token.size = l + 1;
		t = nullptr;
		int k = 0;
		int j = l + 1;
		while (data[j] != '\0')
		{
			data[k] = data[j];
			j = j + 1;
			k = k + 1;
		}
		data[k] = '\0';
		size = k + 1;
	}
	else
		exit(0);
	return token;
}
int CString::findCharacter(char *characters, char* token)
{
	int pos = -1, i = 0;
	while (token[i] != '\0' && pos == -1)
	{
		int j = 0;
		while (characters[j] != '\0' && token[i] != characters[j])
		{
			j = j + 1;
		}
		if (characters[j] != '\0')
			pos = i;
		i = i + 1;
	}
	return pos;
}