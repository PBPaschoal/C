#include <stdio.h>

// Prototype
void meow(void);

int main(void){
	for(int i = 0; i < 3; i++){
		meow();
	}
}

void meow(void){
	printf("meow\n");
}