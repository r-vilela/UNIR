#include <stdio.h>
#include <stdlib.h>

int stringArray(){
    char bag[][20] = {"sword", "potion", "monster blood", "bones"};

    printf("Size of the vector %d\nSize of the Element %d\n",sizeof(bag),sizeof(bag[0]));

    printf("List items on the bag \n");
    for(int i = 0; i < sizeof(bag)/sizeof(bag[0]); i++){
        printf("Item: %s\n", bag[i]);
    }

    return 0;
}

int multiplyVector(){
    int a[10];
    int b[10];
    int c;

    printf("Digit a number: ");
    scanf("%d", &c);

    printf("Digit the number of a vector with a size of 10\n");
    for (int i = 0; i < sizeof(a)/sizeof(int); i++){
        int val;
        scanf("%d", &val);

        a[i] = val;
    }

    for (int i = 0; i < sizeof(a)/sizeof(int); i++){
        b[i] = a[i] * c;
    }

    for (int i = 0; i < sizeof(b)/sizeof(int); i++){
        printf("%d X %d = %d\n", a[i], c, b[i]);
    }


    return 0;
}

int main(){
    int arr[10];
    int med = 0;

    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        int val;
        scanf("%d", &val);

        arr[i] = val;
    }

    for(int i = 0; i <= sizeof(arr)/sizeof(int); i++){
        med += arr[i]/10;
    }



    return 0;
}
