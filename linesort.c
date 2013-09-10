#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /*max lines to sort*/
#define MAXLEN 1000 /*max length of any input line*/

char *lineptr[MAXLINES]; /*pointers to char pointers (text lines)*/
char *sortedlines[MAXLINES];

/*function prototypes*/
int readlines(char *linelist[], int maxlines);
void writelines(char *linelist[], int nlines);
int getline(char *, int);
void qsort(char *linelist[], int left, int right);

main()
{
	int numlines; /*number of input lines to read*/

	if ((numlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, numlines-1);
		writelines(lineptr, numlines);
		return 0;
	}
	else {
		printf("error: intput too big to sort\n");
		return 1;
	}
}

int readlines(char *linelist[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines=0;
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; /*delete newline*/
			strcpy(p, line); /*obtain pointer to first char of the line*/
			linelist[nlines++] = p; /*push pointer to line into the pointer array*/
		}
	return nlines;
}
void writelines(char *linelist[], int nlines)
{
	int i;
	for(i=0;i<nlines;i++)
		printf("%s\n",*(linelist++));
}
int getline(char *s, int lim)
{
	int c, i;
	i=0;
	while(--lim > 0 && (c=getchar()) != EOF && c !='\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}	
void qsort(char *linelist[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) /*do nothing if fewer than two elements*/
		return;
	swap(linelist, left, (left+right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if(strcmp(linelist[i],linelist[left]) < 0)
			swap(linelist, ++last, i);
	swap(linelist, left, last);
	qsort(linelist, left, last-1);
	qsort(linelist, last+1, right);
}
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
