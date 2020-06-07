#include<stdio.h>

int main(){
    FILE *p1, *p2;
    char c;
    //char str[100];
    int i=1;

    p1 = fopen("input.c", "r");
    p2 = fopen("output.txt", "w");

    if(!p1) printf("File cannot be open");
    else{
        fprintf(p2,"1:");
        while((c = fgetc(p1)) !=EOF){


            fputc(c,p2);

            if(c =='\n'){
               fprintf(p2,"%d:", ++i);
            }
        }
        //fprintf(p2,"\b\b");
    }

    fclose(p1);
    fclose(p2);

    p2 = fopen("output.txt", "r");
    while( (c = fgetc(p2)) !=EOF){
        printf("%c", c);
    }

    fclose(p2);
}
