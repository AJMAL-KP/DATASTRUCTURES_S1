#include <stdio.h>

int n;

void set_union(int b1[], int b2[], int u[], int n) {
    printf("Union: { ");
    for(int i = 0; i < n; i++){
        if(b1[i] || b2[i])  
            printf("%d ", u[i]);
    }
    printf("}\n");
}

void set_intersection(int b1[], int b2[], int u[], int n) {
    printf("Intersection: { ");
    for(int i = 0; i < n; i++){
        if(b1[i] && b2[i]) 
            printf("%d ", u[i]);
    }
    printf("}\n");
}

void set_difference(int b1[], int b2[], int u[], int n) {
    printf("Difference (Set1 - Set2): { ");
    for(int i = 0; i < n; i++){
        if(b1[i] && !b2[i])  
            printf("%d ", u[i]);
    }
    printf("}\n");
}

int main() {
    int i, j, x;

    
    printf("Enter the number of elements in Universal set: ");
    scanf("%d", &n);

    int u[n];

    
    printf("Enter the elements of Universal set one by one:\n");
    for(i = 0; i < n; ) {
        int flag = 0;
        scanf("%d", &x);

        for(j = 0; j < i; j++) {
            if(u[j] == x) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            u[i] = x;
            i++;
        } else {
            printf("%d already present in universal set..!!\n", x);
        }
    }

    
    printf("Universal set is: { ");
    for(i = 0; i < n; i++){
        printf("%d", u[i]);
        if(i != n-1) printf(", ");
    }
    printf(" }\n");

    
    int b1[n], b2[n];
    printf("Enter the first bitstring (0/1 for each element): ");
    for(i = 0; i < n; i++)
        scanf("%d", &b1[i]);

    printf("Enter the second bitstring (0/1 for each element): ");
    for(i = 0; i < n; i++)
        scanf("%d", &b2[i]);

    
    printf("Set 1: { ");
    for(i = 0; i < n; i++){
        if(b1[i] == 1) printf("%d ", u[i]);
    }
    printf("}\n");

    
    printf("Set 2: { ");
    for(i = 0; i < n; i++){
        if(b2[i] == 1) printf("%d ", u[i]);
    }
    printf("}\n");

    
    set_union(b1, b2, u, n);
    set_intersection(b1, b2, u, n);
    set_difference(b1, b2, u, n);

    return 0;
}
