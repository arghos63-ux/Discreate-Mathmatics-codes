#include <stdio.h>

int main() {
    FILE *file = fopen("onto.txt", "r");

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
        fscanf(file, " %c", &codomain[i]); // %c এর আগে স্পেস দেওয়া হয়েছে হোয়াইটস্পেস এড়িয়ে যেতে
    }

    // ৩. Mapping পড়া
    fscanf(file, "%d", &n_mapping);
    char mapping[n_mapping];
    for (int i = 0; i < n_mapping; i++) {
        fscanf(file, " %c", &mapping[i]);
    }

    fclose(file);

    // ৪. Codomain-এর প্রতিটি উপাদান Mapping-এ আছে কি না চেক করা
    int isOnto = 1; // ধরে নিলাম Onto

    for (int i = 0; i < n_codomain; i++) {
        int found = 0;
        
        for (int j = 0; j < n_mapping; j++) {
            if (codomain[i] == mapping[j]) {
                found = 1; // Codomain-এর উপাদানটি Mapping-এ পাওয়া গেছে
                break;
            }
        }

        // যদি Codomain-এর কোনো একটি উপাদানও Mapping-এ না পাওয়া যায়
        if (found == 0) {
            isOnto = 0; // Onto হবে না
            break;
        }
    }

    // ৫. ফলাফল প্রিন্ট করা
    if (isOnto == 1) {
        printf("Function is Onto\n");
    } else {
        printf("Function is Not Onto\n");
    }

    return 0;
}