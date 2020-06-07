#include<stdio.h>

int main(){
    FILE *p1, *p2;
    char c;

    p1 = fopen("input.c", "r");
    p2 = fopen("parenthesis.txt", "w");

    if(!p1) printf("File cannot be open");
    else{
        while( (c = fgetc(p1)) !=EOF){
            if((c == '(') || (c == ')'))
                fputc(c,p2);

        }
    }

    fclose(p1);
    fclose(p2);

    p2 = fopen("parenthesis.txt", "r");
    while( (c = fgetc(p1)) !=EOF){
        printf("%c", c);
    }

    fclose(p2);
}
