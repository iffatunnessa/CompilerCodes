#include<stdio.h>

int main(){
    FILE *p1, *p2;
    char c, c1;
    int flag =0;
    p1 = fopen("input.c", "r");
    p2 = fopen("header.txt","w");
     int count =0;

    if(!p1) printf("File cannot be open");
    else{
        while( (c = fgetc(p1)) !=EOF){
            if(c == 'p'){
                fputc(c,p2);
                while( (c1 = fgetc(p1)) && c1 != ';' ){
                    fputc(c1,p2);
                    flag = 1;
                }
                fputc(c1,p2);
                if (flag==1) fprintf(p2,"//print %d", ++count);

            }
            else
                fputc(c,p2);

        }
    }


    fclose(p1);
    fclose(p2);

    p2 = fopen("header.txt", "r");
    while( (c = fgetc(p1)) !=EOF){
        printf("%c", c);
    }

    fclose(p2);
}
