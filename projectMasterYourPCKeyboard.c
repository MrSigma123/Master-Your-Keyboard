// ANNOTATION : I've made an assumptioin to jut use standard libraries!
/*
This program was inspired by:
- "Mistrz klawiatury II" program
- keybr.com website
- typing.com website
*/
/* 
POLECENIE:
1. Trener pisania na klawiaturze
Program wczytuje bazę zdań z pliku,
każde zdanie w osobnej linii.
Następnie wyświetla użytkownikowi jedno zdanie
i każe je przepisać.
Użytkownik wpisuje tekst,
jednak nie widzi wpisanego tekstu na ekranie.
Po naciśnięciu "enter" program wyświetla
wpisane przez użytkownika zdanie,
wyraźnie pokazuje błędy oraz pokazuje
procentową ilość błędów
(za dobre uznajemy właściwe litery
na właściwych pozycjach).
Do tego program pokazuje czas,
jaki upłynął od naciśnięcia
pierwszego klawisza zdania do ostatniego.
*/
/*
Necessary functionalities:
- read a database from a file (DONE)
    *(ready file, chosed by the user[by path] or typed to the new file by the user)
        every sentence have to be printed in new line
        and than get compared to the string entered by the user
- input the string (whole sentence) by the user (DONE)
    the text has to be invisible (hidden) while typing (VARIATION - because of using standard libs)
        after pressing ENTER program will print previously typed sentence
            program will show errors (mark them with red color)
            and also will show percenage of correct symbols
            (right character on the right place)
- time functionality(DONE)
    check the time from typing the first symbol to the ENTER (sent. confirmation)
ADDITIONAL FUNCTIONALITIES
- MENU
    which modes I need to create an interesting, clear and easy to use MENU? // 
    0. Info with choices (add links to menu)
    1. Training mode (almost ready, just add two files)
    2. Creating new file to practice (easy)
    3. Leaderboard (lists)
    4. About the author (additional page)
- leaderboard
    to the file named leaderbr.txt input the Name, Score(percentage) and Time
    (so you have to ask the user to enter the name before doing anything)
    then after completing the test and showing the results several positions from
    leaderboard will be shown, and if the score will be higher than on the leaderboard
    special message will be printed and in dependence of the given place
    also appropriate message will be printed (1. 2. 3. and etc will be printed)
    and the Names, Scores and Percentages will be read from the leaderboard file
        there will be always adding the name to the leaderboard by comparing
        the Score values or Percentage values, if the result will be still higher
        than compared value we will seek to the moment if we will find the smaller value
        than the text cursor will be reverserd to the beginning of the line,
        there will be added new line character the coursor will be moved back by
        one character (newline character) and then the name, score and percentage
        will be added to the file. File will be saved and closed and we will proceed
        to the next moment of program workflow
*/
// after program completion we will save those instructions to the readme.txt file
/*
You might consider adding two languages functionality POL and ENG
*/
// this program purpose is to allow it's user
// to tran the typing skill on personal computer keyboard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <curses.h> // doesn't work
#include <time.h> // to count the time
// here we will add libraries, which will be necessary to
// implement all needed program's functionalities
void clearScreen(void);
void printLogo(void);
void printWelcomeMessage(void);
int choosingTheFile(void);
void openAndWorkOnFile(int choice);
void timeDelay(int miliseconds);
void clearScreen(void){
    printf("\e[H\e[2J\e[3J");   // an alternative of printf("\e[1;1H\e[2J");
    // wchich works exactly the same as cls() or clear() functions
}
void printLogo(void){
    clearScreen();
    printf("ver. 1.01\n\n\n\n");
    /* COLOR DATABASE PALLETE
    printf("\033[0;31m"); // print red layer
    printf("\033[0;32m"); // print green layer
    printf("\033[0;33m"); // print yellow layer
    printf("\033[0;34m"); // print blue layer
    printf("\033[0;35m"); // print purple layer
    printf("\033[0;36m"); // print cyan layer
    printf("\033[0;37m"); // print white layer
    */
    //fgetc(stdin); // to make fulscreen mode
    timeDelay(500);
    printf("\033[0;31m88   88                  \t\033[0;31m88      88                 \033[0;34m88\n");
    timeDelay(100);
    printf("\033[0;31m88  88                   \t\033[0;31m888    888                 \033[0;34m88\n");
    timeDelay(100);
    printf("\033[0;31m88 88   \033[0;32m 88888  \033[0;33m88    88 \t\033[0;31m8888  8888 \033[0;32m 88888  \033[0;33m 88888 \033[0;34m88888 \033[0;35m 88888  \033[0;36m88  888\n");
    timeDelay(100);
    printf("\033[0;31m8888    \033[0;32m88   88 \033[0;33m 88  88  \t\033[0;31m88 8888 88 \033[0;32m     88 \033[0;33m88     \033[0;34m 88   \033[0;35m88   88 \033[0;36m8888\n");
    timeDelay(100);
    printf("\033[0;31m88 88   \033[0;32m8888888 \033[0;33m  8888   \t\033[0;31m88  88  88 \033[0;32m 888888 \033[0;33m 8888  \033[0;34m 88   \033[0;35m8888888 \033[0;36m88\n");
    timeDelay(100);
    printf("\033[0;31m88  88  \033[0;32m88      \033[0;33m   88    \t\033[0;31m88      88 \033[0;32m88   88 \033[0;33m    88 \033[0;34m 88   \033[0;35m88      \033[0;36m88\n");
    timeDelay(100);
    printf("\033[0;31m88   88 \033[0;32m 88888  \033[0;33m  88     \t\033[0;31m88      88 \033[0;32m 888888 \033[0;33m88888  \033[0;34m  888 \033[0;35m 88888  \033[0;36m88\n");
    timeDelay(100);
    printf("\033[0;33m                 88\n");
    timeDelay(100);
    printf("\033[0;33m                88\n");
    timeDelay(1000);
    printf("\033[0;37m"); // set color of the text to white as default
    printf("\t\n\n\t\t\t      by Karol Czolpinski");
    printf("\007"); // make a sound
    printf("\n\n\t\t\t    PRESS ENTER TO CONTINUE");
    getchar();
    fflush(stdin);
    clearScreen();
}
void printWelcomeMessage(void){
    printf("\007");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t    Welcome!\n");
    printf("\n     Did you ever wanted to improve your typing skills on computer keyboard?\n");
    printf("\t          If yes, then you came to the right place! ^^\n");
    printf("\t       This program was exacly designed for that purpose!\n\n");
    printf("\t\t      PRESSS ENTER TO START YOUR TRAINING");
    getchar();
    fflush(stdin);
    clearScreen();
}
int choosingTheFile(void){
    int choice;
    printf("\007");
    printf("\n\n\n\n\n\n\n");
    printf("\t You can choose one from three files to practice your skills:\n\n");
    printf("\t\t   1. \"Robinson Crusoe\" by Daniel Defoe\n");
    printf("\t2. \"The Adventures of Sherlock Holmes\" by Arthur Conan Doyle\n");
    printf("\t    3. \"Around the World in Eighty Days\" by Jules Verne\n");
    printf("\t\t    (You can type 0 to exit the program)\n\n");
    printf("\t\tPlease enter the number and confirm with ENTER\n");
    printf("\t\t\t\tMY CHOICE: ");
    scanf("%d", &choice);
    if (choice == 0)
        return 0;
    while (choice > 3 || choice < 0){ // for any choice other than 1 or 2 or 3
        clearScreen();
        printf("\007");
        printf("\n\n\n\n\n\n\n");
        printf("\t\tSorry, I don't understand, can you try again?\n");
        printf("\t You can choose one from three files to practice your skills:\n\n");
        printf("\t\t   1. \"Robinson Crusoe\" by Daniel Defoe\n");
        printf("\t2. \"The Adventures of Sherlock Holmes\" by Arthur Conan Doyle\n");
        printf("\t    3. \"Around the World in Eighty Days\" by Jules Verne\n");
        printf("\t\t    (You can type 0 to exit the program)\n\n");
        printf("\t\tPlease enter the number and confirm with ENTER\n");
        printf("\t\t\t\tMY CHOICE: ");
        fflush(stdin);
        scanf("%d", &choice);
    }
    clearScreen();
    fflush(stdin);
    return choice;
}
void openAndWorkOnFile(int choosedFile){
    int i;                                  // loop variable
    char stringFromFile[250];               // to store long sentences from file
    char stringFromInput[250];              // to store long sentences from input
    char character;                         // to store compared characters
    int totalCharacterCounter = 0;          // to store all the charcters in the text
    int typedCharacterCounter = 0;          // to store all characters (from the file)
    int correctCharacterCounter = 0;        // to store correctly written characters
    int errorCounter = 0;                   // to store incorrectly typed words
    int exceedingCharacterCounter = 0;      // to store characters, which exceed string from file
    int omittedCharactersCounter = 0;       // to store number of omitted characters
    int eofFlag = 0;                        // determines the presence of EOF in the file
    float timeTotal;                        // to measure time from displaying text to the ESC + ENTER
    // int miliseconds;                        // to store converted miliseconds from total time
    int seconds;                            // to store amount of the seconds from total time
    int minutes;                            // to store number of minutes from total time
    FILE *fp;
    if (choosedFile == 1){
        printf("\t\t  You are training on \033[0;36m\"Robinson Crusoe\" Ch.1\n\033[0;37m");
        printf("\t(You can always press ESC and than ENTER in any time to stop)\n");
        printf("     (If you will press ESC key before typing any new sentence character)\n");
        printf("\t\t   (the untyped characters won't be counted)\n\n");
        fp = fopen("/Users/karolczolpinski/VSCode/CFiles/SchoolStuff/projectMasterYourPCKeyboard/textFiles/Robinson_Crusoe_Ch1.txt", "r");
        // it's better to give direct filename path // previous instruction (fp = fopen("Robinson_Crusoe_Ch1.txt", "r"); )
        /* FOR TESTS to make sure the file was opened successfully
        if (fp != NULL)
            printf("success!\n");
        else
            printf("error\n");
        */
    }
    else if (choosedFile == 2){
        printf("\t\t  You are training on \033[0;36m\"Sherlock Holmes\" Ch.1\n\033[0;37m");
        printf("\t(You can always press ESC and than ENTER in any time to stop)\n");
        printf("     (If you will press ESC key before typing any new sentence character)\n");
        printf("\t\t   (the untyped characters won't be counted)\n\n");
        fp = fopen("/Users/karolczolpinski/VSCode/CFiles/SchoolStuff/projectMasterYourPCKeyboard/textFiles/Sherlock_Holmes_Ch1.txt", "r");
    }
    else{ // if choosedFile == 3
        printf("\t  You are training on \033[0;36m\"Around The World In Eighty Days\" Ch.1\n\033[0;37m");
        printf("\t(You can always press ESC and than ENTER in any time to stop)\n");
        printf("     (If you will press ESC key before typing any new sentence character)\n");
        printf("\t\t   (the untyped characters won't be counted)\n\n");
        fp = fopen("/Users/karolczolpinski/VSCode/CFiles/SchoolStuff/projectMasterYourPCKeyboard/textFiles/Around_The_World_In_Eighty_Days_Ch1.txt", "r");
    }
    //time_t start = time(NULL);
    time_t start = time(NULL);
    while (1){ // infinite condition
    // not necessary previous statement in for loop (character != '.' && character != '?' && character != '!')
    for (i = 0; 1 ; i++){ 
        character = fgetc(fp);
        if (character == '\n') // replaces newline characters with space characters
            break;
        if (feof(fp)){ // breaks the loop if EOF is detected
            eofFlag = 1; // EOF present
            break;
        }
        fputc(character, stdout);
        stringFromFile[i] = character;
        totalCharacterCounter++;
    }
    stringFromFile[i] = '\0'; // add '\0' character to indicate end of the string
    // go back to the beginning of the line (could be just printf("\r")')
    for (i = strlen(stringFromFile); i > 0; i--)
        printf("\b");
    // setting default empty input string
    strcpy(stringFromInput, "\0");
    // making letters black to make the text invisible (this way we don't need <conio.h>)
    printf("\033[0;30m");
    // characters input to the terminal
    for (i = 0; i < 249; i++){ // max bufor size in case of many exceeding characters
        character = fgetc(stdin);
        if (character == '\n')
            break;
        if (character == '\e') // ESC key == '\033'
            break;
        stringFromInput[i] = character;
    }
    printf("\007");
    fflush(stdin);
    // similarly, adding \0 to the end to indicate end of the string
    stringFromInput[i] = '\0';
    // compare input and file strings and show errors on the screen (by marking them with red color)
    printf("%c[1A\r", 033);
    // print not typed file string characters with white font
    // (in case if some last characters of the string were not pressed)
    printf("\033[0;37m");
    for (i = 0; i < strlen(stringFromFile); i++)
        printf("%c", stringFromFile[i]);
    // move the cursor back
    while (i-- >= 0)
        printf("\b");
    // than mask all correctly 
    for (i = 0; i < strlen(stringFromInput); i++){
        // masking correct characters to green color
        if (stringFromInput[i] == stringFromFile[i]){
            if (stringFromInput[i] == ' ')
                stringFromInput[i] = '_';
            printf("\033[0;32m");
            printf("%c", stringFromInput[i]);
            correctCharacterCounter++;
        }
        else{ // masking incorrect characters to red color
            if (stringFromInput[i] == ' ')
                stringFromInput[i] = '_';
            printf("\033[0;31m");
            printf("%c", stringFromInput[i]);
            errorCounter++;
        }
    }
    // print with yellow color the characters which exceed the file string
    if (strlen(stringFromInput) > strlen(stringFromFile)){
        for (i = (strlen(stringFromInput) - strlen(stringFromFile)); i > 0; i--){
            printf("\b");
            exceedingCharacterCounter++;
        }
        printf("\033[0;33m");
        while(stringFromInput[strlen(stringFromFile) + i] != '\0')
            printf("%c", stringFromInput[strlen(stringFromInput) - exceedingCharacterCounter + i++]);
    }
    // if the input string is shorter than the string from the file count omitted characters
    if (strlen(stringFromInput) < strlen(stringFromFile))
        if (stringFromInput[0] != '\0')
            omittedCharactersCounter += (strlen(stringFromFile) - strlen(stringFromInput));
    printf("\n");
    printf("\033[0;37m"); // set default text color to the white
    if (character == '\e'){
        typedCharacterCounter -= (strlen(stringFromFile) - strlen(stringFromInput) - exceedingCharacterCounter);
        break;
    }
    if (eofFlag == 1)
        break;
    if (character == '\n')
        character = ' '; // to replace '\n' with space character
    // fgetc(fp); // was used with previous condition (info above)
    }
    time_t end = time(NULL);
    timeTotal = (float)(end - start);// / CLOCKS_PER_SEC; // clock() doesn't return proper values
    // miliseconds = (timeTotal - (int)timeTotal) * 1000;
    seconds = (int)timeTotal % 60;
    minutes = (int)(timeTotal / 60); // approximate to int
    typedCharacterCounter = correctCharacterCounter + errorCounter;
    // print summary message with results
    printf("\n\t\t\t  HERE ARE YOUR RESULTS:\n\n");
    printf("\t\t\t    Total characters == \033[0;36m%d\n", totalCharacterCounter);
    printf("\033[0;37m");
    printf("\t\t\t    Input characters == \033[0;35m%d\n", typedCharacterCounter);
    printf("\033[0;37m");
    printf("\t\t\t   Correct charcters == \033[0;32m%d\n", correctCharacterCounter);
    printf("\033[0;37m");
    printf("\t\t\t     Wrong chracters == \033[0;31m%d\n", errorCounter);
    printf("\033[0;37m");
    printf("\t\t\t  Omitted characters == \033[0;37m%d\n", omittedCharactersCounter);
    printf("\033[0;37m");
    printf("\t\t\tExceeding characters == \033[0;33m%d\n", exceedingCharacterCounter);
    printf("\033[0;37m");
    printf("\t\t\t        Total errors == \033[0;31m%d\n", errorCounter +
        omittedCharactersCounter + exceedingCharacterCounter);
    printf("\033[0;37m");
    // time tests instructions
    // printf("Time from the text display to ESC + ENTER: %f\n", timeTotal);
    // printf("Miliseconds amount == %d\n", miliseconds);
    // printf("Seconds amount == %d\n", seconds);
    // printf("Minutes amount == %d\n", minutes);
    // conditions to print additional 0 to format the time display
    printf("\n\t\t                  ");
    if (minutes < 10)
        printf("0");
    printf("%dm:", minutes);
    if (seconds < 10)
        printf("0");
    printf("%ds\n", seconds);
    //printf(".%dms\n", miliseconds);
    // CODE USED FOR TESTING COMARISON
    /*
    printf("%s\n", stringFromFile);
    printf("%s\n", stringFromInput);
    for (i = 0; i < strlen(stringFromFile); i++){
        if (stringFromFile[i] == stringFromInput[i])
            printf("%d is equal!\n", i);
    }
    // print string characters
    for (i = 0; i < strlen(stringFromFile); i++)
    {
        printf("file el%d is %c\n", i, stringFromFile[i]);
        printf("input el%d is %c\n", i, stringFromInput[i]);
    }
    printf("%c%c", stringFromFile[0], stringFromInput[0]);
    printf("strlenFile %lu\n", strlen(stringFromFile));
    printf("strlenInput %lu\n", strlen(stringFromInput));
    printf("Result of comparison = %d\n", strcmp(stringFromInput, stringFromFile));
    if (strcmp(stringFromInput, stringFromFile) == 0)
        printf("Hey! The strings are the same! Bravo!!\n");
    */
    fclose(fp);
}
void timeDelay(int miliseconds){
    fflush(stdin);
    clock_t start_time = clock();
    while((clock() - start_time) * 1000 / CLOCKS_PER_SEC < miliseconds);
}
int main(void)
{
    printLogo();
    printWelcomeMessage();
    int practiceTextChoice = choosingTheFile();
    if (practiceTextChoice == 0)
        return 0;
    openAndWorkOnFile(practiceTextChoice);
    return 0;
}
// kbhit(); read input without printing it to the screen - doesn't work on ARM

// 23.12.2022 5:10PM - 8:43PM
// I have written the design of the project and sketch of necessary functions
// writing sketch of the main function

// 24.12.2022 6:13PM - 7:30PM
// I began implementing the preMenu and the core of the quasi GUI
// 1. Constructed first version of the logo

// 7.01.2023 12:13PM - 13:55PM
// I began testing comparing the string from the file with the input string
// (final code for testing string comparison is still present below inside a comment)

// 14 January 1:30AM - 10:00PM
// fixed issues with the strings

// 15 January 1:21AM - 5:00AM
// 1. improved the corectness coloring
// 2. fixed undefined behaviours with scanf while switching the pages from the preMenu
// got an idea to modify the text files
// idea to make some levels of difficulty (i.e)
//  1. easy
//  2. middle
//  3. hard
//  4. crazy

// 15 January 10:00AM - AM 4:00PM
// 1. finally fixed problem with compilation outside IDE
// 2. Fixed problems with masking the correct, incorrect, 
// not typed characters
// 3. adding exceeding characters functionality
// 4. Adding timer functionality
// 5. Formatted text examples (beak of lines)
// PASSED TESTS (working with files and displaying corectness)
// modified an idea of MENU

// 15 January 6:30PM
// 1. code tidy ups (removing unnecessary coments or writing some explanations)
// 2. made some minor tweaks
// preparing implementing menu
// considering dividing some modules to smaller functions

// 19 January 1:30AM
// added time functionality (in seconds)
// got idea to format the time in minutes, seconds and miliseconds
// ADD LINKED LISTS (LEADERBOARD)

// 19 January 3:45PM
// added time functionality (measuring from displaying the text
// to the last keystroke (ESC -> ENTER)
// formatted the layout of the summary message and time display
// fixed some issues with the values of the summary text
// added coloring summary values

// TO DO! (updated and deleted after completion)

// add percentage of errors at the end
// count the time from the first typed character to the last
// ADDITIONAL: create the formmula to make leaderboard
// and implement lined lists to store
// PARAMETERS:
// NAME (string), CORECTNESS(float in %), CPM(int), TIME(min, sec, ms))

// Defining an array of structs to work on a lists
// NAME (array of chars + '\0')
// SCORE COUNTER == ((correctChar-exceedingCharacter/allChar) in % ) / tiime);
// CPM ((correctChar) / Time (in seconds)) * 60
// CORRECTNESS == (correctChar/allChar) * 100.0\%
// TIME in minutes, seconds and miliseconds

// Choose to the tests not too long strings

// Add WPM and CPM and timer from first key keypress to the ESC character

// Implement MENU (as planned above)
// add very hard random letters and characters strings generated in a file
// add empty file to be modifiable to input any strings the useer might want
// practice on