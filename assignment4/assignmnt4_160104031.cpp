#include<bits/stdc++.h>

using namespace std;

int main(){

    FILE *p1, *p2;
    char c ,c1,c2;
    int count = 1;

    p1 = fopen("input4_160104031.c", "r");
    p2 = fopen("output4_160104031.txt", "w");

    if(!p1) printf("File cannot be open");
    else{
        fprintf(p2,"%d ", count);
        while((c = fgetc(p1)) !=EOF){
            if(c == '\n'){
                fputc(c,p2);
                fprintf(p2,"%d ", ++count);

            }
            else if(c == '/'){
                if(c1 = fgetc(p1) == '*'){
                    while(c1 !='/'){
                        c = c1;
                        c1 = fgetc(p1);
                    }
                }
                else{
                    fputc(c,p2);
                }
            }
            else{ fputc(c,p2); }
        }
    }
    fclose(p1); fclose(p2);
    p1 = fopen("output4_160104031.txt", "r");
    int line = 1, line1 = 0;
    int t1 = 0, t2 = 0;
    char tempchar, temp[10], temp1[10];
    stack<char> paran , checkif;
    if(!p1) printf("File cannot be open");
    else{
        while((c = fgetc(p1)) !=EOF){
            if(c == '\n'){line++; }
            if(c == '(' || c == ')' || c == '{' ||c == '}' ||c == '[' ||c == ']'){
                if( c == '(' || c == '{' || c == '[' ){
                    paran.push(c);
                }
                else if(c == ')'){
                    if(paran.empty()) { cout << "Misplaced ) at line " << line<<endl; }
                    else{
                        char p = paran.top();
                        if(p != '(') { cout << "Misplaced ) at line " << line<<endl; }
                        else{ paran.pop(); }
                    }
                }
                 else if(c == '}'){
                    if(paran.empty()) { cout << "Misplaced } at line " << line <<endl; }
                    else{
                        char p = paran.top();
                        if(p != '{') { cout << "Misplaced } at line " << line<<endl; }
                        else{ paran.pop(); }
                    }
                }
                 else if(c == ']'){
                    if(paran.empty()) { cout << "Misplaced ] at line " << line<<endl; }
                    else{
                        char p = paran.top();
                        if(p != '(') { cout << "Misplaced ] at line " << line<<endl; }
                        else{ paran.pop(); }
                    }
                }
            }
            //token duplication:for separation etc.
            if(c == tempchar){
                if(c != '=' && !isalnum(c) && c != '(' && c != ')' && c != '{' && c != '}' && c != '[' && c != ']'){
                    cout << "Duplication of tokens at line " << line << endl;
                }
            }
            tempchar = c;
            if(c == ' ' || c == '{' || c == '}' || c == '(' || c == ')' || c == '\n'){
                if(!strcmp(temp,"if")){checkif.push('i');}
                if(!strcmp(temp, "else")){
                    if(checkif.empty()){ cout << "Unmatched if else at line " << line << endl; }
                    else{
                       checkif.pop();
                    }
                }

                if(t1 > 0){
                    if(!strcmp(temp,temp1)){cout << "Duplication of tokens at line " << line << endl;}
                }
                memset(temp1, 0, sizeof temp1);
                for(int i=0; i<strlen(temp); i++){
                    temp1[i] = temp[i];
                }
                memset(temp, 0, sizeof temp);
                t1 = 0;
            }
            else{
                temp[t1++] = c;
            }
        }
    }
    fclose(p1);
    if(!paran.empty()){ cout << "Unbalanced braces " <<endl; }


}
