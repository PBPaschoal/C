#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Get numbers from user
	int x = get_int("x: ");
	int y = get_int("y: ");
	
	// Divide x by y
	float z = (float) x / (float) y; // convert to float (casts)
	printf("%f\n", z);
}