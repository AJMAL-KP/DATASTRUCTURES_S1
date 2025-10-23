// set using bit string
#include <stdio.h>

int main() {
    int num;
    printf("Enter how many elements in the universal set: ");
    scanf("%d", &num);

    int uni[num]; 


    printf("Enter %d elements:\n", num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &uni[i]);
    }


    printf("Universal set: { ");
    for (int i = 0; i < num; i++) {
        printf("%d ", uni[i]);
    }
    printf("}\n");

    
    char b1[num], b2[num];
    printf("Enter first bit string (as an integer): ");
    scanf("%s", b1);
    printf("Enter second bit string (as an integer): ");
    scanf("%s", b2);
/*
  
    printf("Set 1: { ");
    for (int i = 0; i < num; i++) {
        if (b1 & (1 << i)) { 
            printf("%d ", uni[i]);
        }
    }
    printf("}\n");

  
    printf("Set 2: { ");
    for (int i = 0; i < num; i++) {
        if (b2 & (1 << i)) {
            printf("%d ", uni[i]);
        }
    }
    printf("}\n");
    */

    printf("Set 1: { ");
    for (int i = 0; i < num; i++) {
        if (b1[i]==1){
            printf("%d ",uni[i]);
        }
        }
    
    printf("}\n");

    printf("Set 1: { ");
    for (int i = 0; i < num; i++) {
        if (b2[i]==1) { 
            printf("%d ", uni[i]);
        }
    }
    
    printf("}\n");
    return 0;
}

