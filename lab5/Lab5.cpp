#include<stdio.h>
#include<string.h>

void S(void);
void A(void);
void B(void);
char str[10];
int f=0;
int i=0;
int l;

int main(void) {

	printf("\nCFG:\n");
	printf("\n\tS -> b | AB\n\tA -> a | aA\n\tB -> b\n");
	printf("\nEnter a string to parse: ");
	scanf("%s", str);

	l = strlen(str);
    if (l>=1)  S();
    else
		printf("\nInvalid String\n");

    if (l == i && f )
		printf("\nValid String\n");
	else
		printf("\nInvalid String\n");

    return 0;
}

void S() {
	if (str[i] == 'b'){
                i++;
                f=1;
                return;
    }
    else {
	  A();
	  if (f) { B(); return;}
    }
}

void A() {
	if (str[i] == 'a') {
		i++;
		f=1;
	}
	else {f=0; return;}
    if (i<l-1) A();
}

void B() {
	if (str[i] == 'b') {
		i++;
		f=1;
		return;
	}
	else {f=0; return;}
}
