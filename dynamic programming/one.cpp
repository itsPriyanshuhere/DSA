// no of unique characters in a string 

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int count = 0;
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j])
            {
                count++;
                break;
            }
        }
    }
    cout << "No of unique characters in a string: " << str.length() - count;
    return 0;
}