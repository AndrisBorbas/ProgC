// C function showing how to do time delay 
#include <stdio.h> 
// To use time library of C 
#include <time.h> 

/// <summary>
/// The thread sleeps for the given milliseconds
/// </summary>
/// <param name="number_of_milli_seconds">The number of milliseconds you want to wait</param>
/// <returns>The actual number of milliseconds waited</returns>
int delay (int number_of_milli_seconds){
	// Stroing start time 
	clock_t start_time = clock();

	// looping till required time is not acheived 
	while (clock() < start_time + number_of_milli_seconds)
		;
	return clock();
}