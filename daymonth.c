#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100

/*initialize 2-dimensional array with month/days*/
char daytab[2][13]= {
    { 31,28,31,30,31,30,31,31,30,31,30,31 },
    { 31,29,31,30,31,30,31,31,30,31,30,31 }
};

/*function declarations*/
int dayOfYear(int year, int month, int day);
void monthDay(int year, int day, int *pmonth, int *pday);
void parseDate(char *dateString, size_t *stringLength);

int main() 
{
    int *pmonth, *pyear,*pday; 
    size_t maxLen = MAXLEN;
    char *currLine=malloc(maxLen);

    printf("Please enter either the year,month,day or just year,day:\n");
    parseDate(currLine, &maxLen);
    return 0;
}

void parseDate(char *dateString, size_t *stringLength)
{
    int i=0;
	int len,userDate[3];
    char *bufferStart=dateString;
    char *nextField;
	
	while((len=getline(&dateString, &stringLength, stdin)) && len != -1) {
		while (((nextField = strchr(dateString, ',')) || (nextField = strchr(dateString, '\n'))) && i < 3) 
		{
			*(nextField++) = '\0';
			if(userDate[i++] = atoi(dateString))
				dateString += (nextField - dateString);
			else 
			{
				printf("Invalid value entered\n");
				break;
			}
		}
		/*if (i > 1 && i < 4) {
			if (i == 2)
				monthDay(userDate[0],userDate[1],pmonth,pday);
			if (i == 3)
				dayOfYear(userDate[0],userDate[1],userDate[2]);
		}
		else
			printf("Invalid number of arguments\n");*/

		dateString = bufferStart; //reset buffer
		i=0; //reset date
	}
}
