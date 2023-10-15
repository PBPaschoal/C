#include <stdio.h>

void meow(void){ // Creating my own function
	printf("Meow\n");
}

int main(void) {
	for (int i = 0; i <= 50; i++){
		meow(); // Calling the meow function
	}
}