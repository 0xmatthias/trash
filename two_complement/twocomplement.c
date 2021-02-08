#include <stdlib.h>
#include <stdio.h>

#define LENGTH 8
#define NOHEAP

/* Datentyp fuer binaere Zahlen beliebiger Laenge. */
typedef char Twocomplement[LENGTH];

static void copy_long(Twocomplement* tc, long * val, int write);
static void tc_set(Twocomplement* tc, char val, long length);
static long tc_long_length();

/* Gibt die Binaere Zahl tc aus. */
void printTC(Twocomplement* tc)
{
	char * tc_arr = *tc;

	for (long i = (LENGTH - 1); i >= 0; i--){
		printf("%d", tc_arr[i]);
	}

	printf("\n");
}

/* Konvertiert ein Twocomplimient in einen long. */
long to_long(Twocomplement* tc)
{
	long number = 0;
	copy_long(tc, &number, 0);
	return number;
}

/* Berechnet das Zweierkoompliment von der Twocomplement Zahl. */
void two_complement(Twocomplement* tc)
{
	char * tc_arr = *tc;

	int overflow = 1;
	for(long i=0; i < LENGTH; i++){
		/*
		tc_arr[i]= tc_arr[i] ^ 1;// Ihr Code hier...

		if (overflow){
			tc_arr[i] = tc_arr[i] ^ 1;

			if (tc_arr[i] != 0){
				overflow = 0;
			}
		}*/

		if (!overflow){
			tc_arr[i] = tc_arr[i] ^ 1;
		} else {
			overflow = !tc_arr[i];
		}
	}
}

static void copy_long(Twocomplement* tc, long * val, int write)
{
	long length = tc_long_length();
	char * tc_arr = *tc;

	if (write){
		for (long i = 0; i < length; i++){
			tc_arr[i] = (*val >> i) & 1;
		}
	} else {
		*val = 0;
		int is_neg = 0;

		if (tc_arr[LENGTH - 1]){
			is_neg = 1;
			two_complement(tc);
		}

		for (long i = 0; i < length; i++){
			long b = tc_arr[i] << i;
			*val = *val | b;
		}

		if (is_neg){
			*val = *val *(-1);
			two_complement(tc);
		}
	}
}

// see memset for more details
static void tc_set(Twocomplement* tc, char val, long length)
{
	char * tc_arr = *tc;

	for (long i = 0; i < length; i++){
		tc_arr[i] = val;
	}
}

static long tc_long_length()
{
	long length = LENGTH;

	if (LENGTH > 8*sizeof(long)) {
		fprintf(stderr, "WARNING LENGTH > sizeof(long), invariant violated\n");
		length = 8*sizeof(long);
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

	tc_set(number, 0, LENGTH);

	int is_neg = 0;

	if (x < 0){
		is_neg = 1;
		x = x * (-1);
	}

	copy_long(number, &x, 1);

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


