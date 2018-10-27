// C function showing how to do time delay
#include <stdio.h>
// To use time library of C
#include <time.h>

int delay(int number_of_milliseconds) {
	// Stroing start time
	clock_t start_time = clock();

	// looping till required time is not acheived
	while (clock() < start_time + number_of_milliseconds)
		;
	return clock();
}
