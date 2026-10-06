#include <stdio.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    
    if (file == NULL) {
        printf("File পাওয়া যায়নি!\n");
        return 1;
    }

    int n1, n2;

    // Set A পড়া
    fscanf(file, "%d", &n1);
    int A[n1];
    for (int i = 0; i < n1; i++) {
        fscanf(file, "%d", &A[i]);
    }

    // Set B পড়া
    fscanf(file, "%d", &n2);
    int B[n2];
    for (int i = 0; i < n2; i++) {
        fscanf(file, "%d", &B[i]);
    }

    fclose(file);

    // A - B হিসাব করা
    printf("A - B = {");
    int first = 1;

    for (int i = 0; i < n1; i++) {
        int found = 0;
        
        // A[i] উপাদানটি B তে আছে কি না চেক করা
        for (int j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }

        // B তে না থাকলে প্রিন্ট করা
        if (found == 0) {
            if (!first) printf(", ");
            printf("%d", A[i]);
            first = 0;
        }
    }
    printf("}\n");

    return 0;
}