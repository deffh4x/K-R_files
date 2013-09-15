#include <stdio.h>
#include <ctype.h>

int daymonth[][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int yearday (int year, int month, int day);
void monthyear (int year, int day, int *pMonth, int *pDay);
int getDate (int *year, int *month, int *day);

int main()
{
	int year,month,day,pMonth,pDay,chooseFunc;

	printf("Please enter Y/m/d or Y/d:\n");
	chooseFunc=getDate(&year,&month,&day);
	if (chooseFunc <= 1 ) {
		printf("Invalid date entered.\n");
		return 1;
	}
	if (chooseFunc == 3)
		printf("Entered in Y-m-d format: %d\n", yearday(year,month,day)); 
	if (chooseFunc == 2) {
		monthyear(year,month,&pMonth,&pDay);
		printf("Entered in Y-d format: %d %d\n",pMonth,pDay);
	}
	return 0;
}

int getDate(int *year, int *month, int *day)
{
	int c,i,currentNum;
	int *datePtrs[3] = { year, month, day };
	i=0;

	while ((c=getc(stdin)) != '\n' && i < 3)	
	{
		for (currentNum=0; isdigit(c); c=getc(stdin))
			currentNum = 10 * currentNum + (c - '0');
		if (currentNum !=0)
			*datePtrs[i++] = currentNum;
		if (c == '\n')
			ungetc(c,stdin);
	}
	return i;
}

int yearday (int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daymonth[leap][i];
	return day;
}

void monthyear (int year, int day, int *pMonth, int *pDay)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; day > daymonth[leap][i]; i++)
		day -= daymonth[leap][i];
	*pMonth = i;
	*pDay = day;
}
