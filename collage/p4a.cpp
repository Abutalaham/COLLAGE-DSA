#include <stdio.h>
#include <ctype.h>

char st[50]; int top=-1;
void push(char c){ st[++top]=c; }
char pop(){ return st[top--]; }
int p(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/'||c=='%') return 2;
    if(c=='+'||c=='-') return 1;
    return 0;
}

int main(){
    char in[50], post[50], c; int i,j=0;
    gets(in);
    for(i=0; in[i]; i++){
        c=in[i];
        if(isalnum(c)) post[j++]=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(st[top]!='(') post[j++]=pop(); pop(); }
        else{
            while(top!=-1 && p(st[top])>=p(c)) post[j++]=pop();
            push(c);
        }
    }
    while(top!=-1) post[j++]=pop();
    post[j]='\0';
    printf("%s",post);
    return 0;
}

