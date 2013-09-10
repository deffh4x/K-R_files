#include <stdio.h>

#define MAXLEN 100

/*initialize 2-dimensional array with month/days*/
char daytab[2][13]= {
    { 31,28,31,30,31,30,31,31,30,31,30,31 },
    { 31,29,31,30,31,30,31,31,30,31,30,31 }
};

/*function declarations*/
int dayOfYear(int year, int month, int day);
void monthDay(int year, int day, int *pmonth, int *pday);
void parseDate(char *dateString, int stringLength);

int main() 
{
    int *pmonth, *pyear,len;
    int userDate[3];
    int i=0;
    size_t maxLen = MAXLEN;
    char *currLine=malloc(maxLen);
    char *nextField;

    printf("Please enter either the year,month,day or just year,day:\n");
    while((len=getline(&currLine, &maxLen, stdin)) && len != -1) {
        while (((nextField = strchr(currLine, ',')) || (nextField = strchr(currLine, '\n'))) && i < 3) {
            *nextField = '\0';
            userDate[i++] = atoi(currLine);
            currLine += (nextField - currLine) + 1;
        }
        currLine -= len; //reset buffer position
        i=0; //reset date
    } 
    return 0;
}
