#include <stdio.h>
#include <stdlib.h>

int main(){
    while(1){
        void *memoryPtr = malloc(1024 *100 * 10);
        if(memoryPtr == NULL){
            perror("Memory allocation failed.");
            break;
        }
        //free(memoryPtr);
    }
    return 0;
}