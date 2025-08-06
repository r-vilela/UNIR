#include <stdio.h>

int power(int a, int b){
    int i, temp;
    temp=a;
    for(i=0;i<b-1;i++){
        a*=temp;
    }

    return a;
}

int main(){
    int a=0,b=0,c=0,i;


    for(i=0;i<(power(2,3));i++){
        //printf("resto de 1: %d\n", !(i%1));
        //printf("resto de 2: %d\n", !(i%2));
        if(!(i%4)){
            if(a){
                a=0;
            }else{
                a=1;
            }
        }
        if(!(i%2)){
            if(b){
                b=0;
            }else{
                b=1;
            }
        }
        if(!(i%1)){
            if(c){
                c=0;
            }else{
                c=1;
            }
        }
        printf("%d %d %d | %d\n",a,b,c, !(a&&b)||c);
    }

    return 0;
}
