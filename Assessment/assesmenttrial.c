#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void reverseString(char str[]);
void concatenateStrings(char str1[], char str2[]);
int isPalindrome(char str[]);
void copyString(char str1[], char str2[]);
int stringLength(char str[]);
void characterFrequency(char str[], char ch);
void countVowelsAndConsonants(char str[]);
void countSpacesAndDigits(char str[]);

int main() {
    int choice;
    char str1[100], str2[100], ch;
    char continueChoice;

    do {
    
        printf("\n Main menu\n");
        printf("\t1. Reverse a string\n");
        printf("\t2. Concatenation\n");
        printf("\t3. Palindrome\n");
        printf("\t4. Copy a string\n");
        printf("\t5. Length of the string\n");
        printf("\t6. Frequency of  character in a string\n");
        printf("\t7. Find number of vowels and consonants\n");
        printf("\t8. Find number of blank spaces and digits\n");
        printf("\t9. Exit\n");

        // Take the user's choice as input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Reverse a string
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);  // Read a string with spaces
                reverseString(str1);
                break;
            
            case 2:
                // Concatenate two strings
                printf("Enter first string: ");
                scanf(" %[^\n]", str1);
                printf("Enter second string: ");
                scanf(" %[^\n]", str2);
                concatenateStrings(str1, str2);
                break;
            
            case 3:
                // Check if the string is a palindrome
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                if(isPalindrome(str1)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            
            case 4:
                // Copy one string to another
                printf("Enter the source string: ");
                scanf(" %[^\n]", str1);
                copyString(str1, str2);
                printf("Copied string: %s\n", str2);
                break;

            case 5:
                // Find the length of the string
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                printf("Length of the string: %d\n", stringLength(str1));
                break;

            case 6:
                // Find the frequency of a character
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                printf("Enter the character to find frequency: ");
                scanf(" %c", &ch);  // Read a single character
                characterFrequency(str1, ch);
                break;

            case 7:
                // Find the number of vowels and consonants
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                countVowelsAndConsonants(str1);
                break;

            case 8:
                // Find the number of spaces and digits
                printf("Enter a string: ");
                scanf(" %[^\n]", str1);
                countSpacesAndDigits(str1);
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

        // Ask the user if they want to continue
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &continueChoice);

    } while(continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

// Function to reverse a string
void reverseString(char str[]) {
    int len = strlen(str);
    printf("Reversed string: ");
    for(int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}

// Function to concatenate two strings
void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

// Function to check if a string is a palindrome
int isPalindrome(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to copy one string to another
void copyString(char str1[], char str2[]) {
    strcpy(str2, str1);
}

// Function to find the length of a string
int stringLength(char str[]) {
    return strlen(str);
}

// Function to find the frequency of a character in a string
void characterFrequency(char str[], char ch) {
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(tolower(str[i]) == tolower(ch)) {
            count++;
        }
    }
    printf("The frequency of '%c' is: %d\n", ch, count);
}

// Function to count the number of vowels and consonants in a string
void countVowelsAndConsonants(char str[]) {
    int vowels = 0, consonants = 0;
    for(int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        } else if(isalpha(c)) {
            consonants++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

// Function to count the number of spaces and digits in a string
void countSpacesAndDigits(char str[]) {
    int spaces = 0, digits = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(isdigit(str[i])) {
            digits++;
        } else if(isspace(str[i])) {
            spaces++;
        }
    }
    printf("Spaces: %d, Digits: %d\n", spaces, digits);
}
