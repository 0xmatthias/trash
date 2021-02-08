#include <stdlib.h>
#include <stdio.h>

#define LENGTH 8
#define NOHEAP

/* Datentyp fuer binaere Zahlen beliebiger Laenge. */
typedef char Twocomplement[LENGTH];

static void copy_long(char * dst, char  * src, long length);
static void tc_set(char * tc, char val, long length);
static long tc_long_length();

/* Gibt die Binaere Zahl tc aus. */
void printTC(Twocomplement* tc)
{
	char * tc_arr = *tc;

	for (long i = (LENGTH - 1); i >= 0; i--){
		char val = tc_arr[i];

		for (int j = 0; j < 8*sizeof(char); j++){
			printf("%d", (val >> j) & (0x01));
		}
	}

	printf("\n");
}

/* Konvertiert ein Twocomplimient in einen long. */
long to_long(Twocomplement* tc)
{
	long number = 0;
	copy_long((char *) &number, (char *) tc, tc_long_length());
	return number;
}

/* Berechnet das Zweierkoompliment von der Twocomplement Zahl. */
void two_complement(Twocomplement* tc)
{
	char * tc_arr = *tc;

	int overflow = 1;
	for(long i=0; i < LENGTH; i++){
		tc_arr[i]= ~tc_arr[i];// Ihr Code hier...

		if (overflow){
			tc_arr[i] = tc_arr[i] + 1;

			if (tc_arr[i] != 0){
				overflow = 0;
			}
		}
	}
}

// see memcpy for more details
static void copy_long(char * dst, char  * src, long length)
{
	for (long i = 0; i < length; i++){
		dst[i] = src[i];
	}
}

// see memset for more details
static void tc_set(char * tc, char val, long length)
{
	for (long i = 0; i < length; i++){
		tc[i] = val;
	}
}

static long tc_long_length()
{
	long length = LENGTH;

	if (LENGTH > sizeof(long)) {
		fprintf(stderr, "WARNING LENGTH > sizeof(long), invariant violated\n");
		length = sizeof(long);
	}

	return length;
}

/* Erzeugt ein neues Twocompliment mit dem Wert x auf dem Heap. */
Twocomplement* newTC(long x)
{

	Twocomplement * number = (Twocomplement *) malloc(sizeof(Twocomplement));
	if (!number) {
		return NULL;
	}

	tc_set((char *) number, 0, LENGTH);

	int is_neg = 0;

	if (x < 0){
		is_neg = 1;
		x = x * (-1);
	}

	copy_long((char *) number, (char *) &x, tc_long_length());

	if (is_neg){
		two_complement(number);
	}

	return number;
}

/* Testet die obrigen Funktionen. */
int main(void)
{
	#ifdef NOHEAP
		printf("Version mit lokalen Variablen auf dem Stack.\n");
		Twocomplement fuenf  = {1,0,1};
		Twocomplement sieben = {1,1,1};
		Twocomplement* a = &fuenf;
		Twocomplement* b = &sieben;
	#else
		printf("Version mit globalen Variablen auf dem Heap.\n");
		Twocomplement* a = newTC(5);
		Twocomplement* b = newTC(-7);
	#endif
	
	printf("Die Zahlen sind:  a = %2ld = ", to_long(a));
	printTC(a);
	printf(",   b = %2ld = ",to_long(b));
	printTC(b);
	printf(".\n");

	two_complement(a);
	two_complement(b);
	printf("Zweierkomplement: a = %2ld = ", to_long(a));
	printTC(a);
	printf(",   b = %2ld = ", to_long(b));
	printTC(b);
	printf(".\n");
	
	#ifndef NOHEAP
		free(a);
		free(b);
	#endif
}


