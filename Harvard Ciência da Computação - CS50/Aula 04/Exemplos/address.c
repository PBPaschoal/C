#include <stdio.h>

int main(void){
	int n = 50;
	int *p = &n;

	char *s = "HI!";

	printf("%p\n", p);

	printf("%c\n", *s);

	printf("%c\n", s[0]);
	printf("%c\n", s[1]);
	printf("%c\n", s[2]);

	printf("%c\n", *(s+3));
	printf("%c\n", *(s+10000));
}