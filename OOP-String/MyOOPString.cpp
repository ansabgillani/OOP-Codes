#include<iostream>
using namespace std;

class CString {
private:
    char * data;
    int size;
public:
    CString();
    //Initialize data and set the size to zero
    CString(char ch);
    //Initialize data by character and set the size to 1
    CString(const char * string);
    //Intialize data by the character array and set the size equal to length
    ~CString();
    //Release resources from the data members
    int getSize() {
        return this->size;
    }
    void input() {
        if (size == 0 || data == nullptr)
            resize(10);
        if(getLength()>0)
            remove(0, getLength());
        cin.getline(data,size);
    }
    char & at(int index);
    //Index -> Recieves the index for the string
    //Return Value -> Reference of the aarray location represented by the index
    bool isEmpty();
    //Tells whether the string is empty or not
    bool isFull();
    //Tells whether the string is full or not
    void resize(int newSize);
    //Resizes the data array to the newSize, sets the size to new value 
    int getLength();
    //Returns the length of the string
    void display();
    //Displays the content of the string
    int find(CString & subString, int start = 0);
    //Find the substring in the calling CString object.
    //By default, search starts from index 0
    //Returns the count of occurences found in the calling object
    void insert(int index, CString & subString);
    //Insert the substring at gien index in the calling object
    void remove(int index, int count = 1);
    //Remove the characters starting from index
    //Count represents the number of characters to be removed
    int replace(CString & oldString, CString & newString);
    // Find all the occurences of old substring and  replace it with new substring
    // Return the count of occurrences found in the calling object
    void trimLeft();
    //Removes all the white spaces to the left of the string.
    //Old String = "   start of the string"
    //New String = "start of the string"
    void trimRight();
    //Removes all the white spaces to the right of the string.
    //Old String = "start of the string    "
    //New String = "start of the string"
    void trim();
    //Removes all the white spaces to the left and right of the string.
    //Old String = "   start of the string   "
    //New String = "start of the string"
    void makeUpper();
    //Change all the alphabets to uppercase
    void makeLower();
    //Change all the alphabets to lowercase
    void reverse();
    //Reverse the string stored in data
    int compare(CString & newString);
    //Behaves exactly likes strcmp and compares the caalling object to referenced object
    //Return Values
    //  < 0 - > The first character that does not match has a lower value 
    //          than the referenced object's character
    //    0 - > Both strings are equal
    //  > 0 - > The first character that does not match has a greater value 
    //          than the referenced object's character

}