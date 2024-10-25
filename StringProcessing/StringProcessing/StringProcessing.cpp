// Griffin Dunlap
// String Processing Assignment
// 9/6/2024

#include <iostream>
#include <string>

using namespace std;

// Calling the functions for the main function

void remove(string& text);
void display(string text);

// Function for getting the value from the user
int main()
{
    // Variables
    string text;

    // Getting input from user
    cout << "Enter your html text here: \n";
    getline(cin, text);

    remove(text);
    display(text);
}

// Function for removing HTML tags
void remove(string& text) // For this function I used stack overflow for some help and similar problems were solved using the '&', I don't fully recall if we used this in class yet or not so I wanted to clarify in case I needed to change this or talk to you about it.
{
    for (int a = 0; a < text.length(); a++)
    {
        if (text[a] == '<')
        {
            for (int b = 0; b < text.length(); b++)
            {
                if (text[b] == '>')
                {
                    text.erase(a, b-a+1);
                    break;
                }
            }
        }
    }
}

// Function for outputing the updated string
void display(string text) //This function seemed a bit lack-luster to me also so if there's an issue please let me know and I'll try to adjust or fix it.
{
    cout << "\n\n" << text;
}