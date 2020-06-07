#include<stdio.h>

int main(){

    FILE *p1, *p2;
    char c ,c1,c2;

    p1 = fopen("input1_160104031.c", "r");
    p2 = fopen("output.txt", "w");

    if(!p1) printf("File cannot be open");
    else{
        while((c = fgetc(p1)) !=EOF){
            if(c == '/'){
                if(c1 = fgetc(p1) == '*'){
                    while ( c != '*'){
                        c = c1;
                        c1 = fgetc(p1);
                    }
                }

                else{
                    while ( c != '\n'){
                        c = c1;
                        c1 = fgetc(p1);
                    }
                }
            }
            else if(c!='\n' && c!='\t'){
                if(c == ' '){
                    while ( c != ' '){
                        c = c1;
                        c1 = fgetc(p1);
                    }
                }
                else{
                    fputc(c,p2);
                }
            }
        }
    }
    fclose(p1);
    fclose(p2);


    p1 = fopen("input1_160104031.c", "r");
    while( (c = fgetc(p1)) !=EOF){
        printf("%c", c);
    }
    fclose(p1);
    printf("\n\nOutput:\n");

    p2 = fopen("output.txt", "r");
    while( (c = fgetc(p2)) !=EOF){
        printf("%c", c);
    }
    printf("\n");
    fclose(p2);
}
