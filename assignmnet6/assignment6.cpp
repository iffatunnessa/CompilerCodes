#include<bits/stdc++.h>
#include<vector>
using namespace std;
char S[5]={'S','a','X','d','\0'};
char X[4]={'X','Y','Z','\0'};
char Y[5]={'Y','b','|','E','\0'};
char Z[6]={'Z','c','X','|','E','\0'};

vector<char>firstS;
vector<char>firstX;
vector<char>firstY;
vector<char>firstZ;

vector<char>followS;
vector<char>followX;
vector<char>followY;
vector<char>followZ;

struct par{
    vector<char>x[20];
    char y;
}p;

void typeFirst(char x, char y);
void findfollow(char A[]);

void findFirst(char A[]){
    if(A[1]!='|' && (A[1]>='A' && A[1]<='Z')){
        if(A[1]== 'Y'){
            for(int i = 1;i<firstY.size();i++){
                firstX.push_back(firstY[i]);
            }
        }
        if(A[2]== 'Z'){
            for(int i = 1;i<firstZ.size();i++){
                firstX.push_back(firstZ[i]);
            }
        }

    }
    else if(A[1]!='|' && (A[1]>='a' && A[1]<='z')){
        typeFirst(A[0],A[1]);
    }

    for(int i = 0; i<strlen(A)-1;i++){
            if(A[i] == '|'){
                if(A[0]== 'Y')
                    firstY.push_back('E');
                else if(A[0]== 'Z')
                    firstZ.push_back('E');
                else{
                    break;
                }
        }
    }
}
void typeFirst(char x, char y){
    if(firstS[0]==x){
        firstS.push_back(y);
    }
    else if(firstX[0]==x){
        firstX.push_back(y);

    }
    else if(firstY[0]==x){
        firstY.push_back(y);
    }
    else if(firstZ[0]==x){
        firstZ.push_back(y);
    }
}

void typeFollow(char x,char y){
    if(followS[0]==x){
        followS.push_back(y);
    }
    else if(followX[0]==x){
        followX.push_back(y);

    }
    else if(followY[0]==x){
        followY.push_back(y);
    }
    else if(followZ[0]==x){
        followZ.push_back(y);
    }

}
void followNT(char x){
    if(followY[0]==x){
        followY.push_back(firstZ[1]);
        followY.push_back(followX[1]);
    }
    else if(followZ[0]==x){
        followZ.push_back(followX[1]);
    }
}

void findfollow(char A[]){
    int j;
    if(A[0]=='S') followS.push_back('$');
    int i=strlen(A)-1;
    j = strlen(A)-2;
    if(A[i]>='a' && A[i]<='z'){
        typeFollow(A[i-1],A[i]);
    }
    else if((A[i]>='A' && A[i]<='Z') || (A[j]>='A' && A[j]<='Z')){
        followNT(A[i]);
        followNT(A[j]);
    }
}
void addIntoParse(vector<char>A){
    for(int i =0; i<A.size(); i++){
        if(A[i]=='a'){
            cout <<A[i]<< "\tS->aXd\n";
        }
        if(A[i]=='b'){
            cout <<A[i]<< "\tY->b\n";
        }
        if(A[i]=='c'){
            cout <<A[i]<< "\tZ->cX\n";
        }
        if(A[i]=='E'){
            if(A[0] == 'Y'){
                cout <<"c" << "\tY->E\n";
                cout <<"d" << "\tY->E\n";
            }
            else if(A[0] == 'Z'){
                cout <<"c" << "\tZ->E\n";
                cout <<"d" << "\tZ->E\n";
            }
            else if(A[0] == 'X'){
                cout <<"b" << "\tX->YZ\n";
                cout <<"c" << "\tX->YZ\n";
                cout <<"d" << "\tX->YZ\n";
            }
        }
    }

}

int main(){

    firstS.push_back('S');
    firstX.push_back('X');
    firstY.push_back('Y');
    firstZ.push_back('Z');

    followS.push_back('S');
    followX.push_back('X');
    followY.push_back('Y');
    followZ.push_back('Z');

    findFirst(Y);
    findFirst(Z);
    findFirst(S);
    findFirst(X);

    findfollow(S);
    findfollow(X);
    findfollow(Z);
    findfollow(Y);

    cout<<"Firsts:\n";
    cout<< firstS[0]<<": {";
    for(int i = 1; i<firstS.size();i++)
        cout<<firstS[i]<<",";
    cout <<"\b}\n";

    cout<< firstX[0]<<": {";
    for(int i = 1; i<firstX.size();i++)
        cout<<firstX[i]<<",";
    cout <<"\b}\n";

    cout<< firstY[0]<<": {";
    for(int i = 1; i<firstY.size();i++)
        cout<<firstY[i]<<",";
    cout <<"\b}\n";

    cout<< firstZ[0]<<": {";
    for(int i = 1; i<firstZ.size();i++)
        cout<<firstZ[i]<<",";
    cout <<"\b}\n";

    cout<<"\nFollows:\n";
    cout<< followS[0]<<": {";
    for(int i = 1; i<followS.size();i++)
        cout<<followS[i]<<",";
    cout <<"\b}\n";

    cout<< followX[0]<<": {";
    for(int i = 1; i<followX.size();i++)
        cout<<followX[i]<<",";
    cout <<"\b}\n";

    cout<< followY[0]<<": {";
    for(int i = 1; i<followY.size();i++)
        cout<<followY[i]<<",";
    cout <<"\b}\n";

    cout<< followZ[0]<<": {";
    for(int i = 1; i<followZ.size();i++)
        cout<<followZ[i]<<",";
    cout <<"\b}\n";

    addIntoParse(firstS);
    addIntoParse(firstX);
    addIntoParse(firstY);
    addIntoParse(firstZ);

}
