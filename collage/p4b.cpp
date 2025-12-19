#include <stdio.h>
#include <math.h>

int st[20], top=-1;
void push(int x){ st[++top]=x; }
int pop(){ return st[top--]; }

int main(){
    char p[20], c; int i,a,b;
    scanf("%s",p);
    for(i=0;p[i];i++){
        c=p[i];
        if(c>='0'&&c<='9') push(c-'0');
        else{
            b=pop(); a=pop();
            if(c=='+') push(a+b);
            else if(c=='-') push(a-b);
            else if(c=='*') push(a*b);
            else if(c=='/') push(a/b);
            else if(c=='%') push(a%b);
            else if(c=='^') push(pow(a,b));
        }
    }
    printf("%d",pop());
    return 0;
}

