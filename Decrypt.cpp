/**
 * @file Decrypt.cpp
 * @brief 
 * @author Sohel Tarir
 * @version 1.0
 * @date 2013-12-09
 */
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string Decrypt(string sText, string sKey)
{
    map <char, int> COUNT_MAP;
    map <char, char> KEY_MAP;
    int nTmp = 0;
    char cTmp;
    int nPos = sKey.length() - 1;
    for (int i = sText.length() - 1; i > -1; i--)
    {
        if (COUNT_MAP.find(sText[i]) == COUNT_MAP.end())
            COUNT_MAP[sText[i]] = 1;
        else
            COUNT_MAP[sText[i]]++;
        if (KEY_MAP.find(sText[i]) == KEY_MAP.end())
        {
            nTmp = sKey.length() - sText.length() + i;
            KEY_MAP[sText[i]] = sKey.at(nPos);
            nPos--;
        }
    }

    for (int i = 0; i < sText.length() - 1; i++)
    {
        for (int j = 0; j < sText.length() - i - 1; j++)
        {
            if (COUNT_MAP[sText[j]] > COUNT_MAP[sText[j+1]])
            {
                cTmp = KEY_MAP[sText[j]];
                KEY_MAP[sText[j]] = KEY_MAP[sText[j+1]];
                KEY_MAP[sText[j+1]] = cTmp;
            }
        }
    }

    for (int i = 0; i < sText.length(); i++)
    {
        cTmp = sText[i];
        sText.replace(i, 1, 1, KEY_MAP[cTmp]);
    }
    string sOutput = sText;
    return sOutput;
}

int main()
{
    string sText, sKey, sOutput;
    cout << "Enter the Encryption Key:" << endl;
    getline(cin, sKey);
    cout << "Enter the Encrypted Text:" << endl;
    getline(cin, sText);
    sOutput = Decrypt(sText, sKey);
    cout << "The decrypted text is:" << endl;
    cout << sOutput << endl;
    return 0;
}
