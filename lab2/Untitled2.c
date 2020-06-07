#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *input,*output;

int kw_rec(char lex[20]);
int id_rec(char lex[20]);
int sp_rec(char lex[20]);
int op_rec(char lex[20]);
int p_rec(char lex[20]);
int num_rec(char lex[20]);

int main(void) {

    char c,lex[20];
    int i;

    input = fopen("scannednew.txt", "r");
    output = fopen("scanned2.txt", "w");

    if(!input) {
        printf("\nFile can't be opened!");
    } else {
        while((c=fgetc(input))!=EOF) {
            if(!isalnum(c) && c!=' ' && c!='_' && c!='.' && c!= '$') {
                fputc(' ', output);
            }
            fputc(c, output);
            if(c=='>' || c=='<'|| c=='=' || c=='!') {
                char ch;
                if((ch=fgetc(input))=='=') {
                    fputc(ch, output);
                    if(!isalnum(ch) && ch!=' ' && ch!='_' && ch!='.') {
                        fputc(' ', output);
                    }
                } else {
                    fputc(' ', output);
                    fputc(ch, output);
                    if(!isalnum(ch) && ch!=' ' && ch!='_' && ch!='.') {
                        fputc(' ', output);
                    }
                }
            } else if(!isalnum(c) && c!=' ' && c!='_' && c!='.') {
                fputc(' ', output);
            }
        }
    }

    fclose(input);
    fclose(output);


    input = fopen("scanned2.txt", "r");
    output = fopen("tokens.txt","w");

    if(!input) {
        printf("\nFile can't be opened!");
    } else {

        c = fgetc(input);

        while(c != EOF) {

            i=0;

            while(c!=' ' && c!=EOF) {
                lex[i]=c;
                i++;
                c=fgetc(input);
            }

            lex[i]='\0';

            if (kw_rec(lex)) {

                i=0;

                fprintf(output,"[kw ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else if(id_rec(lex)) {

                i=0;

                fprintf(output,"[id ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else if(sid_rec(lex)) {

                i=0;

                fprintf(output,"[sid ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else if(sp_rec(lex)) {

                i=0;

                fprintf(output,"[sep ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else if(op_rec(lex)) {

                i=0;

                fprintf(output,"[op ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else if(p_rec(lex)) {

                i=0;

                fprintf(output,"[par ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else if(num_rec(lex)) {

                i=0;

                fprintf(output,"[num ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");

            } else {

                i=0;

                fprintf(output,"[unkn ");

                while(lex[i] != '\0') {
                    fputc(lex[i], output);
                    i++;
                }

                fprintf(output,"] ");
            }

            c=fgetc(input);
        }
    }

    fclose(input);
    fclose(output);

    output = fopen("tokens.txt","r");

    while((c=fgetc(output))!=EOF) {
        printf("%c",c);
    }

    fclose(output);

    printf("\n");

    return 0;
}

int kw_rec(char lex[20]) {

    if(!strcmp(lex,"int") ||
            !strcmp(lex,"char") ||
            !strcmp(lex,"float") ||
            !strcmp(lex,"double") ||
            !strcmp(lex,"void") ||
            !strcmp(lex,"if") ||
            !strcmp(lex,"else")) {
        return 1;
    } else {
        return 0;
    }
}

int id_rec(char lex[20]) {

    int s=0,i;

    if(isalpha(lex[0]) || lex[0]=='_') {

        s=1;

        for(i=1; i<strlen(lex); i++) {
            if(!isalnum(lex[i]) && lex[i]!='_') {
                s=0;
                break;
            }
        }
    }

    return s;
}

int sid_rec(char lex[20]) {

    int s=0,i;

    if(isalpha(lex[0]) || lex[0]=='_') {

        s=1;

        for(i=1; i<strlen(lex); i++) {
            if(!isalnum(lex[i]) && lex[i]!='_' && lex[strlen(lex)-1] != '$') {
                s=0;
                break;
            }
        }
    }

    return s;
}

int sp_rec(char lex[20]) {

    if(!strcmp(lex,",") ||
            !strcmp(lex,";") ||
            !strcmp(lex,"'")) {
        return 1;
    } else {
        return 0;
    }
}

int op_rec(char lex[20]) {

    if(!strcmp(lex,"+") ||
            !strcmp(lex,"-") ||
            !strcmp(lex,"*") ||
            !strcmp(lex,"/") ||
            !strcmp(lex,"=") ||
            !strcmp(lex,"<") ||
            !strcmp(lex,">") ||
            !strcmp(lex,"<=") ||
            !strcmp(lex,">=") ||
            !strcmp(lex,"!")) {
        return 1;
    } else {
        return 0;
    }
}

int p_rec(char lex[20]) {

    if(!strcmp(lex,"(") ||
            !strcmp(lex,")") ||
            !strcmp(lex,"{") ||
            !strcmp(lex,"}") ||
            !strcmp(lex,"[") ||
            !strcmp(lex,"]")) {
        return 1;
    } else {
        return 0;
    }
}

int num_rec(char lex[20]){

    int i=0, l, s;

    if(isdigit(lex[i])) {
        s=1;
        i++;
    } else if(lex[i]=='.') {
        s=2;
        i++;
    } else{
        s=0;
    }

    l=strlen(lex);

    if(s==1) {
        for(; i<l; i++) {
            if(isdigit(lex[i])){
                s=1;
            }
            else if(lex[i]=='.') {
                s=2;
                i++;
                break;
            } else {
                s=0;
                break;
            }
        }
    }
    if(s==2) {
        if(isdigit(lex[i])) {
            s=3;
            i++;
        } else {
            s=0;
        }
    }
    if(s==3) {
        for(; i<l; i++) {
            if(isdigit(lex[i])) {
                s=3;
            } else {
                s=0;
                break;
            }
        }
    }

    if(s==3) {
        s=1;
    }

    return s;
}




