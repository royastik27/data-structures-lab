/**
* A Program to Replace Every Occurance of a Word in a String With Another
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

string INSERT(string TEXT, int position, string PATTERN)
{
    return TEXT.substr(0, position) + PATTERN + TEXT.substr(position, TEXT.length() - position);
}

string DELETE(string TEXT, int position, int length)
{
    return TEXT.substr(0, position) + TEXT.substr(position+length, TEXT.length() - position- length);
}

int INDEX(string TEXT, string PATTERN)
{
    int i, j;

    for(i = 0; i < TEXT.length() - PATTERN.length() + 1; ++i)
    {
        for(j = 0; j < PATTERN.length(); ++j)
            if(TEXT[i+j] != PATTERN[j])
                break;

        if(j == PATTERN.length())
            return i;
    }

    return -1;
}

string REPLACE(string TEXT, string PATTERN1, string PATTERN2)
{
    int idx = INDEX(TEXT, PATTERN1);
    TEXT = DELETE(TEXT, idx, PATTERN1.length());
    TEXT = INSERT(TEXT, idx, PATTERN2);

    return TEXT;
}

int main()
{
    string TEXT, PREV, NEW;

    cout << "Enter a line of text: ";
    getline(cin, TEXT);

    cout << "Enter a word to replace: ";
    cin >> PREV;

    cout << "Enter the new word: ";
    cin >> NEW;

    int idx = INDEX(TEXT, PREV);

    while(idx != -1)
    {
        TEXT = REPLACE(TEXT, PREV, NEW);
        idx = INDEX(TEXT, PREV);
    }

    cout << "Replaced String: " << TEXT << '\n';

    return 0;
}
