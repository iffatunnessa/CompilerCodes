#include<stdio.h>
int main()
{
    FILE *p1, *p2;
    char c ,c1;
int n = 8;
    p1 = fopen("input.c", "r");
    p2 = fopen("header.txt", "w");

    if(!p1) printf("File cannot be open");
    else{
        while( (c = fgetc(p1)) !=EOF){
            if(c == '<') continue;
            for(int i = 0; i<n; i++){
                printf("\b");
            }
            printf("%c", c);
            if(c == '>') break;



           /* if(c == '<'){
                   while (c1 = fgetc(p1) != '>')
                        fputc(c1,p2);

            }*/


        }


    }
    fclose(p1);
   /* fclose(p2);

    p2 = fopen("header.txt", "r");
    while( (c = fgetc(p2)) !=EOF){
        printf("%c", c);
    }

    fclose(p2);
*/

}
