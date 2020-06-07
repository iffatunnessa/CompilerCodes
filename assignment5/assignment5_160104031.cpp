#include<bits/stdc++.h>

using namespace std;

void SE(int i, int l);
void T(int i, int l);
void F(int i, int l);

void ST(int i, int l);
void A(int i, int l);
void E(int i, int l);
void Ex(int i, int l);
void D(int i, int l);
void Ex1(int i, int l);
void L(int i, int l);
void R(int i, int l);

int f=0;
char str[20];

void SE(int i, int l) {
    T(i,l);
    if(f==1){
        i++;
        if(str[i] == '+' ){
            i++;
            T(i,l);
            return;
        }
        else if(str[i] == '-' ){
            i++;
            T(i,l);
            return;
        }
        return;
    }

    else{
        f=0;return;
    }
}

void T(int i, int l) {
    F(i,l);
    if(f==1){
        i++;
        if(str[i] == '*' ){
            i++;
            F(i,l);
            return;
        }
        else if(str[i] == '/' ){
            i++;
            F(i,l);
            return;
        }
        return;
    }
    else{
        f=0;return;
    }
}

void F(int i, int l) {
    f=0;
    if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e') && !isalnum(str[i+1])){
            i++;
            F(i,l);
            f=1;
            return;
    }
    else if(isdigit(str[i]) && !isalnum(str[i+1])){
        i++;
        F(i,l);
        f=1;
        return;
    }
    else if (str[i] == '(') {
        i++;
        SE(i,l);
        if(str[i] == ')'){
            f=1; return;
        }
    }
    else{
        f=0;return;
    }
}

void St(int i, int l){
    if(str[i]== 'i'){
        i++;
        if(str[i]== 'd') {i--; A(i,l);}
        else if(str[i]=='f') {i--; D(i,l);}
    }
    else if(str[i]=='w') L(i,l);
    else if(str[i]=='f') L(i,l);
}

void A(int i, int l){
    if(str[i]== 'i'){
        i++;
        if(str[i]== 'd'){
            i++;
            if(str[i]=='='){
                i++;
                E(i,l);
            }
        }
    }
}

void E(int i,int l){
    SE(i,l);
    i++;
    Ex(i,l);
}

void Ex(int i,int l){
    if(str[i] == '=' || str[i] == '!' || str[i] == '>' || str[i] == '<' ){
        i++;
        if(str[i] == '='){
            i++;
            SE(i,l);
        }
    }
    else if( str[i] == '>' || str[i] == '<' ){
        i++;
        SE(i,l);
    }

}

void D(int i, int l){
    if(str[i]== 'i'){
        i++;
        if(str[i]== 'f'){
            i++;
            if(str[i]=='('){
                i++;
                E(i,l);
                i++;
                if(str[i]==')'){
                    i++;
                    SE(i,l);
                    if(str[i]=='('){
                        i++;
                        Ex1(i,l);
                        if(str[i]==')'){
                            f=1; return;
                        }
                    }
                }
            }
        }
    }
    else{
        f=0;return;
    }
}

void Ex1(int i, int l){
    if(str[i]=='e'){
        i++;
        if(str[i]=='l'){
            i++;
            if(str[i]=='s'){
                i++;
                if(str[i]=='e'){
                    i++;
                    St(i,l);
                }
            }
        }
    }

}

void L(int i, int l){
    if(str[i]=='w'){
        i++;
        if(str[i]=='h'){
            i++;
            if(str[i]=='i'){
                i++;
                if(str[i]=='l'){
                    i++;
                    if(str[i]=='e'){
                        i++;
                        if(str[i]=='('){
                            i++;
                            E(i,l);
                            i++;
                            if(str[i]==')'){
                                St(i,l);
                            }
                        }
                    }
                }
            }
        }
    }

    else if(str[i]=='f'){
        i++;
        if(str[i]=='o'){
            i++;
            if(str[i]=='r'){
                i++;
                if(str[i]=='('){
                    i++;
                    A(i,l);
                    i++;
                    if(str[i]==';'){
                        i++;
                        E(i,l);
                        i++;
                        if(str[i]==';'){
                            i++;
                            A(i,l);
                            i++;
                            if(str[i]==')'){
                                i++;
                                St(i,l);
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        f=0;return;
    }
}

int main(){
    int n, l;
    cout << "Enter the number of iteration:";
    cin >> n;
    for(int j=0; j<n ; j++){
        cin >> str;
        l = strlen(str);
        St(0, l);
        if(f==1) cout << "Accepted\n";
        else{ cout << "Not accepted\n";}
        f=0;
    }
}
