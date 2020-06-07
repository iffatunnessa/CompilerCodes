#include<bits/stdc++.h>

using namespace std;

void E(int i, int l);
void T(int i, int l);
void F(int i, int l);

int f=0;
char str[20];

void E(int i, int l) {
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
        f=1;return;
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
        E(i,l);
        if(str[i] == ')'){
            f=1; return;
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


        E(0, l);

        if(f==1) cout << "Accepted\n";
        else{ cout << "Not accepted\n";}
        f=0;
    }
}
