// #include <stdio.h>
// #include <string.h>

// void checkGrammar(char prods[][256], int p) {
//     for (int i = 0; i < p; i++) {
//         char line[256];
//         strcpy(line, prods[i]);

//         char A = line[0];
//         char *rhs = strstr(line, "->");
//         if (!rhs) continue;
//         rhs += 2;

//         int left = 0, right = 0, fact = 0;
//         int seen[256] = {0};

//         char *alt = rhs;
//         while (*alt) {
//             while (*alt == ' ' || *alt == '\t') alt++;
//             if (*alt == 0) break;

//             char *end = strchr(alt, '|');
//             int len = end ? (int)(end - alt) : (int)strlen(alt);

//             int s = 0;
//             while (s < len && (alt[s] == ' ' || alt[s] == '\t')) s++;
//             if (s < len) {
//                 char f = alt[s];
//                 if (f == A) left = 1;
//                 if (seen[(unsigned char)f]) fact = 1;
//                 seen[(unsigned char)f] = 1;
//             }

//             int e = len - 1;
//             while (e >= 0 && (alt[e] == ' ' || alt[e] == '\t')) e--;
//             if (e >= 0) {
//                 char last = alt[e];
//                 if (last == A) right = 1;
//             }

//             if (!end) break;
//             alt = end + 1;
//         }

//         printf("\n%c:\n", A);
//         printf("left recursion: %s\n", left ? "YES" : "NO");
//         printf("right recursion: %s\n", right ? "YES" : "NO");
//         printf("left factoring: %s\n", fact ? "YES" : "NO");
//     }
// }

// int main() {
//     int n, i;
//     char nt[100][32], line[256];

//     printf("non terminals count: ");
//     scanf("%d", &n);
//     printf("non terminals: ");
//     for (i = 0; i < n; i++) scanf("%31s", nt[i]);

//     int t;
//     printf("terminals count: ");
//     scanf("%d", &t);
//     printf("terminals: ");
//     for (i = 0; i < t; i++) scanf("%31s", line);

//     int p;
//     printf("productions count: ");
//     scanf("%d", &p);
//     getchar();

//     char prods[100][256];
//     for (i = 0; i < p; i++) {
//         printf("production %d: ", i + 1);
//         fgets(prods[i], sizeof(prods[i]), stdin);
//         prods[i][strcspn(prods[i], "\r\n")] = 0;
//     }

//     checkGrammar(prods, p);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

void checkGrammar(char prods[][256], int p) {
    for (int i = 0; i < p; i++) {
        char line[256];
        strcpy(line, prods[i]);

        while (line[0] == ' ' || line[0] == '\t') memmove(line, line + 1, strlen(line));
        char A = line[0];

        char *rhs = strstr(line, "->");
        if (!rhs) continue;
        rhs += 2;

        int left = 0, right = 0, lfact = 0, rfact = 0;
        int seenL[256] = {0}, seenR[256] = {0};

        char *alt = rhs;
        while (*alt) {
            while (*alt == ' ' || *alt == '\t') alt++;
            if (*alt == 0) break;

            char *end = strchr(alt, '|');
            int len = end ? (int)(end - alt) : (int)strlen(alt);

            int s = 0;
            while (s < len && (alt[s] == ' ' || alt[s] == '\t')) s++;
            if (s < len) {
                unsigned char f = (unsigned char)alt[s];
                if ((char)f == A) left = 1;
                if (seenL[f]) lfact = 1;
                seenL[f] = 1;
            }

            int e = len - 1;
            while (e >= 0 && (alt[e] == ' ' || alt[e] == '\t')) e--;
            if (e >= 0) {
                unsigned char last = (unsigned char)alt[e];
                if ((char)last == A) right = 1;
                if (seenR[last]) rfact = 1;
                seenR[last] = 1;
            }

            if (!end) break;
            alt = end + 1;
        }

        printf("\n%c:\n", A);
        printf("left recursion: %s\n", left ? "YES" : "NO");
        printf("right recursion: %s\n", right ? "YES" : "NO");
        printf("left factoring: %s\n", lfact ? "YES" : "NO");
        printf("right factoring: %s\n", rfact ? "YES" : "NO");
    }
}

int main() {
    int n, i;
    char tmp[256];

    printf("non terminals count: ");
    scanf("%d", &n);
    printf("non terminals: ");
    for (i = 0; i < n; i++) scanf("%255s", tmp);

    int t;
    printf("terminals count: ");
    scanf("%d", &t);
    printf("terminals: ");
    for (i = 0; i < t; i++) scanf("%255s", tmp);

    int p;
    printf("productions count: ");
    scanf("%d", &p);
    getchar();

    char prods[200][256];
    for (i = 0; i < p; i++) {
        printf("production %d: ", i + 1);
        fgets(prods[i], sizeof(prods[i]), stdin);
        prods[i][strcspn(prods[i], "\r\n")] = 0;
    }

    checkGrammar(prods, p);
    return 0;
}
