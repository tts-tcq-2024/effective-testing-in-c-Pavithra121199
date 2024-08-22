#include <stdio.h>
#include <assert.h>
#include <string.h>

void printManual(int colorCode, const char* majorColor, const char* minorColor) {
    printf("%d | %s | %s\n", colorCode, majorColor, minorColor);
}

int printColorMap(void (*printManual)(int colorCode, const char* majorColor, const char* minorColor)) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printManual(i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j; 
}


char capturedOutput[1024] = {0};
void printColorCodeManualMock(int colorCode, const char* majorColor, const char* minorColor) {
    char buffer[128];
    sprintf(buffer, "%d | %s | %s\n", colorCode, majorColor, minorColor);
    strcat(capturedOutput, buffer);  
}


void interactionTesting() {
    const char* expectedOutput =
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n"; 
    int result = printColorMap(&printColorCodeManualMock);
    assert(result == 25);         //value test
    assert(strcmp(capturedOutput, expectedOutput) == 0);    //behavior test

int main() {
    interactionTesting();
    printf("All tests passed!\n");
    return 0;
}
