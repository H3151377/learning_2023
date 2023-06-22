#include <stdio.h>

FILE *openFile(const char *fileName, const char *mode)
{
    FILE *file = fopen(fileName, mode);
    if (file == NULL)
    {
        printf("Unable to open the file or file not found: %s\n", fileName);
        return NULL;
    }
    return file;
}

void closeFile(FILE *file)
{
    if (file != NULL)
    {
        fclose(file);
    }
}

void copyFile(const char *sourceFileName, const char *destinationFileName)
{
    FILE *sourceFile = openFile(sourceFileName, "rb");
    if (sourceFile == NULL)
    {
        return;
    }

    FILE *destinationFile = openFile(destinationFileName, "wb");
    if (destinationFile == NULL)
    {
        closeFile(sourceFile);
        return;
    }

    int ch;
    while ((ch = fgetc(sourceFile)) != EOF)
    {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    closeFile(sourceFile);
    closeFile(destinationFile);
}

int main()
{
    char sourceFileName[100], destinationFileName[100];

    printf("Enter the source file name: ");
    scanf("%99s", sourceFileName);

    printf("Enter the destination file name: ");
    scanf("%99s", destinationFileName);

    copyFile(sourceFileName, destinationFileName);

    return 0;
}
