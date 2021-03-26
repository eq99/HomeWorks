#include <stdio.h>
#include <math.h>

void find_factor(int num){
    for(int i= sqrt(num); i > 0; --i){
        if((num % i) == 0){
            printf("%d %d ", i, num/i);
        }
    }
}

int main(){
    find_factor(36);
}