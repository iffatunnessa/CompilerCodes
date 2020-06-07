#include<bits/stdc++.h>

using namespace std;

int f =0;
char str[20];

void B(int i, int l){
    if (str[l-1] == 'a') {
        f=1;
        return;
    }
    else if (str[l-1] == 'b') {
        f=1;
        return;
    }
    else{
        f=0; return;
    }
}

void A(int i, int l){
    if (str[i] == 'b') {
        i++;
        A(i,l);
        return;
    }
    else if (str[l-1] == 'b') {
        f=1;
        return;
    }
    else{
        f=0; return;
    }
}

void E(int i, int l) {
    if (str[i] == 'a') {
        i++;
        A(i,l);
        return;
    }
    else if (str[i] == 'b') {
        i++;
        A(i,l);
        B(i,l);
        return;
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
    }
}
