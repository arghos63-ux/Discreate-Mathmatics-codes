#include <stdio.h>

int main() {
    FILE *file = fopen("function.txt", "r");
    if (file == NULL) {
        printf("Error: File open hocche na!\n");
        return 1;
    }
    int n_domain, n_codomain, n_mapping;
    // ১. Domain পড়া
    fscanf(file, "%d", &n_domain);
    int domain[n_domain];
    for (int i = 0; i < n_domain; i++) {
        fscanf(file, "%d", &domain[i]);
    }
    // ২. Codomain পড়া
    fscanf(file, "%d", &n_codomain);
    char codomain[n_codomain];
    for (int i = 0; i < n_codomain; i++) {
        fscanf(file, " %c", &codomain[i]);
    }
    // ৩. Mapping পড়া
    fscanf(file, "%d", &n_mapping);
    char mapping[n_mapping];
    for (int i = 0; i < n_mapping; i++) {
        fscanf(file, " %c", &mapping[i]);
    }
    fclose(file);
    // ৪. One-to-One চেক করা (Mapping এ কোনো ডুপ্লিকেট ক্যারেক্টার আছে কি না)
    int isOneToOne = 1;
    for (int i = 0; i < n_mapping; i++) {
        for (int j = i + 1; j < n_mapping; j++) {
            if (mapping[i] == mapping[j]) {
                isOneToOne = 0;
                break;
            }
        }
        if (isOneToOne == 0) break;
    }

    // ৫. Onto চেক করা (Codomain এর সব উপাদান Mapping এ আছে কি না)
    int isOnto = 1;
    for (int i = 0; i < n_codomain; i++) {
        int found = 0;
        for (int j = 0; j < n_mapping; j++) {
            if (codomain[i] == mapping[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            isOnto = 0;
            break;
        }
    }

    // ৬. ক্লাসিফিকেশন অনুযায়ী রেজাল্ট প্রিন্ট করা
    if (isOneToOne && isOnto) {
        printf("Function is Bijective (One-to-One and Onto)\n");
    } else if (isOneToOne) {
        printf("Function is One-to-One\n");
    } else if (isOnto) {
        printf("Function is Onto\n");
    } else {
        printf("Function is Neither One-to-One nor Onto\n");
    }

    return 0;
}