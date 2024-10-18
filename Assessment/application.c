//  Create an application that can perform all string related operations....

#include <stdio.h>
#include <string.h>
#include <ctype.h>


void reverseString(char str[]){
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++)
    {
        char temp =str[i];
        str[i] = str[length - i -1];
        str[length - i -1] = temp;
    }
    
    
}

void concanetString(char str1[], char str2[]){
    strcat(str1, str2);
}


int isPalindrome(char str[]){
    int length = strlen(str);
    for (int i = 0; i < length /2 ; i++)
    {
        if (str[i] != str[length - i - 1]){
            return 0;
        }
    }
    
}

// Function to copy a string
void copyString(char destination[], char source[]) {
    strcpy(destination, source);
}

int StringLength(char str[]){
    return strlen(str);
}

void charFrequency(char str[]) {
    int frequency[256] = {0};

    for (int i = 0; i < strlen(str); i++) {
        frequency[str[i]]++;
    }

    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0 && isprint(i)) {
            printf("'%c': %d\n", i, frequency[i]);
        }
    }
}


void countVowelsConsonants(char str[]) {
    int vowels = 0, consonants = 0;

    for (int i = 0; i < strlen(str); i++) {
        char ch = tolower(str[i]);
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
}

void countSpacesDigits(char str[]) {
    int spaces = 0, digits = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            spaces++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }

    printf("Spaces: %d\nDigits: %d\n", spaces, digits);
}

int main(){
    char input[100];
   do
   {
    printf("\nMain Menu\n");
    printf("\t1. Reverse a String\n");
    printf("\t2. Concatenet String\n");
    printf("\t3. Check for Palindromw\n");
    printf("\t4. Copy a String\n");
    printf("\t5. Calculate String Length\n");
    printf("\t6. Find character frequency\n");
    printf("\t7. Count vowels and consonants\n");
    printf("\t8. Count spaces and digits\n");
    printf("\t9. Exit\n");

    int choice;
    printf("Enter Your Choice:");
    scanf("%d",&choice);

    switch (choice){
          case 1:
                printf("Enter a string: ");
                scanf("%s",input);
                reverseString(input);
                printf("Reversed string: %s\n", input);
                break;
            case 2:
                printf("Enter the first string: ");
                scanf("%s", input);
                char secondString[50];
                printf("Enter the second string: ");
                scanf("%s", secondString);
                concanetString(input, secondString);
                printf("Concatenated string: %s\n", input);
                break;
            case 3:
                printf("Enter a string: ");
                scanf("%s", input);
                if (isPalindrome(input)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 4:
                printf("Enter a string to copy: ");
                scanf("%s", input);
                char copiedString[50];
                copyString(copiedString, input);
                printf("Copied string: %s\n", copiedString);
                break;
            case 5:
                printf("Enter a string: ");
                scanf("%s", input);
                printf("Length of the string: %d\n", StringLength(input));
                break;
            case 6:
                printf("Enter a string: ");
                scanf("%s", input);
                charFrequency(input);
                break;
            case 7:
                printf("Enter a string: ");
                scanf("%s", input);
                countVowelsConsonants(input);
                break;
            case 8:
                printf("Enter a string: ");
                scanf("%s", input);
                countSpacesDigits(input);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        char continueChoice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continueChoice);

        if (continueChoice != 'y' && continueChoice != 'Y') {
            printf("Exiting program. Goodbye!\n");
            return 0;
        }


    
   } while (1);
   
    return 0;
}