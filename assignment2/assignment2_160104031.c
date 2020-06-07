#include<stdio.h>
#include<string.h>
#include<ctype.h>

int kw_rec(char lex[20]);
int id_rec(char lex[20]);
int paran_rec(char lex[20]);
int op_rec(char lex[20]);
int num_rec(char lex[20]);
int sep_rec(char lex[20]);

FILE *p1,*p2;

int main(void){
    char c,lex[20];
    int i;
    p1 = fopen("scanned.txt", "r");
    p2 = fopen("new.txt", "w");

    if(!p1) {
        printf("\nFile can't be opened!");
    }
    else{
        while((c = fgetc(p1)) !=EOF){
            if(!isalnum(c) && c!=' ' && c!= '.' && c!= '_'){
                fputc(' ',p2);
            }
            fputc(c,p2);
            if(c == '>' || c == '<' || c == '=' || c =='!'){
                char c1;
                if((c1 = fgetc(p2) == '=')){
                    fputc(c1,p2);
                    if(!isalnum(c1) && c1!=' ' && c1!='_' && c1!='.') {
                        fputc(' ', p2);
                    }
                }
                else{
                    fputc(' ',p2);
                    fputc(c1, p2);
                    if(!isalnum(c1) && c1!=' ' && c1!='_' && c1!='.') {
                        fputc(' ',p2);
                    }
                }
            }
            else if(!isalnum(c) && c!=' ' && c!='_' && c!='.') {
                fputc(' ',p2);
            }
        }

    }
    fclose(p1);
    fclose(p2);

    p1 = fopen("new.txt", "r");
    p2 = fopen("new1.txt", "w");

    if(!p1) {
        printf("\nFile can't be opened!");
    } else {
        while((c=fgetc(p1))!=EOF) {
            if(c==' '||c=='\t') {
                fputc(' ', p2);
                while((c=fgetc(p1))==' ');
                if(c!=EOF) {
                    fputc(c, p2);
                }
            } else {
                fputc(c, p2);
            }
        }
    }
    fclose(p1);
    fclose(p2);

    p1 = fopen("new1.txt", "r");
    p2 = fopen("tokens.txt", "w");

    if(!p1) {
        printf("\nFile can't be opened!");
    }
    else{
        c = fgetc(p1);
        while(c != EOF)
        {
            i=0;
            while(c!=' ' && c!=EOF){
                lex[i]=c;
                ++i;
                c=fgetc(p1);
            }
            lex[i]='\0';

            if (kw_rec(lex)){
                i=0;
                fprintf(p2,"[kw ");
                while(lex[i] != '\0')
                {
                    fputc(lex[i], p2);
                    i++;
                }
                fprintf(p2,"]");
            }

            else if (op_rec(lex)){
                i=0;
                fprintf(p2,"[op ");
                while(lex[i] != '\0')
                {
                    fputc(lex[i], p2);
                    i++;
                }
                fprintf(p2,"]");
            }
            else if (sep_rec(lex)){
                i=0;
                fprintf(p2,"[sep ");
                while(lex[i] != '\0')
                {
                    fputc(lex[i],p2);
                    i++;
                }
                fprintf(p2,"]");
            }
            else if (paran_rec(lex)){
                i=0;
                fprintf(p2,"[par ");
                while(lex[i] != '\0')
                {
                    fputc(lex[i],p2);
                    i++;
                }
                fprintf(p2,"]");
            }
            else if (num_rec(lex)){
                i=0;
                fprintf(p2,"[num ");
                while(lex[i] != '\0')
                {
                    fputc(lex[i], p2);
                    i++;
                }
                fprintf(p2," ]");
            }
            else if (id_rec(lex)){
                i=0;
                fprintf(p2,"[id ");
                while(lex[i] != '\0')
                {
                    fputc(lex[i], p2);
                    i++;
                }
                fprintf(p2,"]");
            }
            else {
                i=0;
                fprintf(p2,"[unkn ");
                while(lex[i] != '\0') {
                    fputc(lex[i], p2);
                    i++;
                }
                fprintf(p2,"]");
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

int kw_rec(char lex[20]){
    int i, s;
    if(!strcmp(lex,"char")) s = 1;
    else if(!strcmp(lex,"int")) s = 1;
    else if(!strcmp(lex,"float")) s = 1;
    else if(!strcmp(lex,"if")) s = 1;
    else if(!strcmp(lex,"else")) s = 1;
    else if(!strcmp(lex,"double")) s = 1;
    else if(!strcmp(lex,"void")) s = 1;
    else s = 0;
    return s;
}

int id_rec(char lex[20]){
    int i,s = 0;
    if((isalpha(lex[0])) || lex[0] == '_'){
        s = 1;
        for(i = 1; i<strlen(lex); i++){
            if(!isalnum(lex[i]) && lex[i] != '_'){
                s = 0;
                break;
            }
        }
    }
    return s;
}

int paran_rec(char lex[20]){
    int i, s;
    if(!strcmp(lex,"[")) s = 1;
    else if(!strcmp(lex,"]")) s = 1;
    else if(!strcmp(lex,"{")) s = 1;
    else if(!strcmp(lex,"}")) s = 1;
    else if(!strcmp(lex,"(")) s = 1;
    else if(!strcmp(lex,")")) s = 1;
    else s = 0;
    return s;
}

int num_rec(char lex[20]){
    int i=0, l, s;
    if(isdigit(lex[i])){
        s=1;
        i++;
    }
    else if(lex[i]=='.'){
        s=2;
        i++;
    }
    else{
        s=0;
    }

    l=strlen(lex);

    if(s==1){
        for(; i<l; i++) {
            if(isdigit(lex[i])){
                s=1;
            }else if(lex[i]=='.') {
                s=2;
                i++;
                break;
            }else {
                s=0;
                break;
            }
        }
    }
    if(s==2){
        if(isdigit(lex[i])) {
            s=3;
            i++;
        }else{
            s=0;
        }
    }
    if(s==3){
        for(; i<l; i++) {
            if(isdigit(lex[i])) {
                s=3;
            }
            else{
                s=0;
                break;
            }
        }
    }
    if(s==3){
        s=1;
    }
    return s;
}

int sep_rec(char lex[20]){
    int i, s;
    if(!strcmp(lex,";")) s = 1;
    else if(!strcmp(lex,"'")) s = 1;
    else if(!strcmp(lex,",")) s = 1;
    else s = 0;
    return s;
}

int op_rec(char lex[20]){
    int i, s;
    if(!strcmp(lex,"=")) s = 1;
    else if(!strcmp(lex,"+")) s = 1;
    else if(!strcmp(lex,"=")) s = 1;
    else if(!strcmp(lex,">")) s = 1;
    else if(!strcmp(lex,"<")) s = 1;
    else if(!strcmp(lex,"*")) s = 1;
    else if(!strcmp(lex,"/")) s = 1;
    else if(!strcmp(lex,"<=")) s = 1;
    else if(!strcmp(lex,">=")) s = 1;
    else if(!strcmp(lex,"==")) s = 1;
    else if(!strcmp(lex,"!")) s = 1;
    else if(!strcmp(lex,"^")) s = 1;
    else s = 0;
    return s;
}
