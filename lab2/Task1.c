 #include <stdio.h>
#include <string.h>
#include <ctype.h>

int kw_rec(char lex[20]);

FILE *p1,*p2;

int main(void)
{
    char c,lex[20];
    int i;

    p1 = fopen("scanned.txt", "r");
    p2 = fopen("tokens.txt","w");

    if(!p1)
        printf("\nFile can't be opened!");
    else
    {
        c = fgetc(p1);
        while(c != EOF)
        {
            i=0;
            while(c!=' ' && c!=EOF)
            {
                lex[i]=c;
                ++i;
                c=fgetc(p1);
            }
            lex[i]='\0';

            if (kw_rec(lex))
            {
                i=0;
                while(lex[i] != '\0')
                {
                    fputc(lex[i], p2);
                    i++;
                }
                fputc(' ', p2);
            }

            c=fgetc(p1);
        }


    }

    fclose(p1);
    fclose(p2);



    p2 = fopen("tokens.txt","r");
    while((c=fgetc(p2))!=EOF)
        printf("%c",c);
    fclose(p2);
    printf("\n\n");

    return 0;
}

int kw_rec(char lex[20])
{
    int i,s;

    if(!strcmp(lex,"int"))
        s=1;
    else if(!strcmp(lex,"char"))
        s=1;
    else if(!strcmp(lex,"float"))
        s=1;
    else if(!strcmp(lex,"double"))
        s=1;
    else if(!strcmp(lex,"void"))
        s=1;
    else if(!strcmp(lex,"if"))
        s=1;
    else if(!strcmp(lex,"else"))
        s=1;
    else
        s=0;

    return s;

}



