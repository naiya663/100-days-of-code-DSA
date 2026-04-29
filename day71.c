#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d %d", &m, &q);
    int *table = (int*)malloc(sizeof(int)*m);
    for(int i=0;i<m;i++) table[i]=EMPTY;

    while(q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if(strcmp(op,"INSERT")==0) {
            int h = key % m;
            for(int i=0;i<m;i++) {
                int idx = (h + i*i) % m;
                if(table[idx]==EMPTY) {
                    table[idx]=key;
                    break;
                }
            }
        } else if(strcmp(op,"SEARCH")==0) {
            int h = key % m;
            int found=0;
            for(int i=0;i<m;i++) {
                int idx = (h + i*i) % m;
                if(table[idx]==key) {
                    found=1;
                    break;
                }
                if(table[idx]==EMPTY) break;
            }
            if(found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    free(table);
    return 0;
}