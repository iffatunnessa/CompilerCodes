#include<bits/stdc++.h>

using namespace std;

int f =0;
char str[20];

void X(int i, int l){
    if (str[i] == 'b') {
        i++;
        if (str[i] == 'b') {
            i++;
            f=1;
            X(i,l);
            return;
        }
        else if (str[i] == 'c') {
            i++;
            f=1;
            X(i,l);
            return;
        }
        else{
            f=0; return;
        }
    }
    else{
        f=0; return;
    }
}

void A(int i, int l) {
    if(l%2==0){
        if (str[i] == 'a') {
            i++;
            X(i,l);
            if (str[l-1] == 'd') {
                i++;
                f=1;return;
            }
            else{
                f=0;return;
            }
        }
    }
}

int main(){
    int n, l;
    cout << "Enter the number of iteration:";
    cin >> n;
    for(int j=0; j<n ; j++){
        cin >> str;
        l = strlen(str);

        A(0, l);

        if(f==1) cout << "Accepted\n";
        else{ cout << "Not accepted\n";}
        f=0;
    }
}
