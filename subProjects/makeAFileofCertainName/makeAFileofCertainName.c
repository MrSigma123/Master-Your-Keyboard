#include <stdio.h>
#include <string.h>

const char* setAFileName(void){
    char filename[25];
    printf("Enter the file name to be created (without extension): ");
    fgets(filename, 25, stdin);
    strcat(filename, ".txt");
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp != NULL)
        printf("File was created successfully!\n");
    else
        printf("File wasn't created, error...\n");
    fclose(fp);
    return filename;
}
void inputContentToFile(fName){
    char input[20];
    FILE *fp;
    fp = fopen(fName, "w");
    printf("Type something and enter it to the file: ");
    fgets(input, 20, stdin);    fprintf(fp, ("%s",input));
    fclose(fp);
}

int main(void){
    char filename[25];
    strcpy(filename, setAFileName());
    inputContentToFile(filename);
    return 0;
}