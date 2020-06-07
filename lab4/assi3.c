#include<stdio.h>
#include<stdlib.h>

struct symbol{
    int aValue;
    char name[20];
    char type[5];
    char datatype[10];
    char scope[5];

}sym[10];

int main(void){
    FILE *p1, *p2;
    char c,c1,lex[20];
    int i=0, j=0;
    int value = 0;
    p1 = fopen("scanned.txt", "r");
    p2 = fopen("new.txt", "w");

    if(!p1) {
        printf("\nFile can't be opened!");
    }
    else{
        while((c = fgetc(p1)) !=EOF){
            if(c == '['){
                c1 = fgetc(p1);
                fputc(c,p2);
                if(c1!= 'i'){
                    while(c != ' '){
                        c = c1;
                        c1 = fgetc(p1);
                    }
                    while(c != ']'){
                        c = c1;
                        c1 = fgetc(p1);
                        fputc(c,p2);
                    }
                }
                else if(c1 == 'i'){
                    while(c != ']'){
                        c = c1;
                        c1 = fgetc(p1);
                        fputc(c,p2);
                    }
                }

            }

        }
    }
    fclose(p1);
    fclose(p2);



    p2 = fopen("new.txt","r");
    while((c=fgetc(p2))!=EOF)
        printf("%c",c);
    fclose(p2);
    printf("\n\n");

    p1 = fopen("new.txt", "r");

    if(!p1) {
        printf("\nFile can't be opened!");
    }
    else{
        while((c = fgetc(p1)) !=EOF){
            if(c == '['){
                c1 = fgetc(p1);
                int k = 0;
                while(c1 != ']'){

                    sym[0].datatype[k] = c;
                    k++;
                    c = c1;
                    c1 = fgetc(p1);
                    printf("%c",sym[0].datatype[k]);
                }
            }
            else if(c1 == 'i'){
                c = c1;
                c1 = fgetc(p1);
                sym[j].aValue = value++;
                while(c1 != ']'){
                    int k = 0;
                    sym[j].name[k] = c;
                    k++;
                    c = c1;
                    c1 = fgetc(p1);
                }
            }
                else{
                    c = c1;
                    c1 = fgetc(p1);
                }

        j++;
        }
    }
    fclose(p1);
    int r;
    for(r=0;i<sizeof(sym);i++){
        printf("%d", sym[r].aValue);
    }

    printf("\n\n");

    return 0;
}

