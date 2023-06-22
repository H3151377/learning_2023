#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to convert characters to uppercase
void convertToUpper(FILE *source, FILE *destination)
{
    int c;
    while ((c = fgetc(source)) != EOF)
    {
        fputc(toupper(c), destination);
    }
}

// Function to convert characters to lowercase
void convertToLower(FILE *source, FILE *destination)
{
    int c;
    while ((c = fgetc(source)) != EOF)
    {
        fputc(tolower(c), destination);
    }
}

// Function to convert characters to sentence case
void convertToSentenceCase(FILE *source, FILE *destination)
{
    int c;
    int sentenceStart = 1; // Indicates if the current character is at the beginning of a sentence

    while ((c = fgetc(source)) != EOF)
    {
        if (sentenceStart && isalpha(c))
        {
            fputc(toupper(c), destination); // Convert the first character of each sentence to uppercase
            sentenceStart = 0;
        }
        else
        {
            fputc(tolower(c), destination); // Convert the rest of the characters to lowercase
            if (c == '.' || c == '!' || c == '?')
                sentenceStart = 1; // Set the flag if a sentence-ending punctuation is encountered
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *sourceFile, *destinationFile;
    int option = 0; // Default option is 0 for normal copy

    if (argc < 3)
    {
        printf("Insufficient arguments!\n");
        printf("Usage: ./cp [option] source_file destination_file\n");
        return 1;
    }

    if (argc > 3)
    {
        option = argv[1][1]; // Option character
        sourceFile = fopen(argv[2], "r");      // Read mode
        destinationFile = fopen(argv[3], "w"); // Write mode
    }
    else
    {
        sourceFile = fopen(argv[1], "r");
        destinationFile = fopen(argv[2], "w");
    }

    if (sourceFile == NULL)
    {
        printf("Failed to open the source file.\n");
        return 1;
    }

    if (destinationFile == NULL)
    {
        printf("Failed to open the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    switch (option)
    {
    case 'u':
        convertToUpper(sourceFile, destinationFile); // Convert source to uppercase
        break;
    case 'l':
        convertToLower(sourceFile, destinationFile); // Convert source to lowercase
        break;
    case 's':
        convertToSentenceCase(sourceFile, destinationFile); // Convert source to sentence case
        break;
    default:
        // Normal copy
        int c;
        while ((c = fgetc(sourceFile)) != EOF)
        {
            fputc(c, destinationFile);
        }
    }

    fclose(sourceFile);
    fclose(destinationFile);
    printf("File copied successfully.\n");

    return 0;
}
