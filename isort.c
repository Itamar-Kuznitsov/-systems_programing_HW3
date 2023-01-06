#include <stdio.h>

#define array_size 50

// Function that make one shift to the right in array: 
int shift_element(int* arr, int i){
    int first = *(arr);
    int second = *(arr+1);
    int j = 0;

    while(j<i){
        *(arr+j+1) = first;
        first = second;
        second = *(arr+j+2);
        
        j++;
    }
    return 0;
}

// Function that implement insertion sort algorithm: (dont have to be by shift_element)
int insertion_sort(int* arr, int len){
    int i, key, j;
    for (i = 1; i < len; i++) {
        key = *(arr+i);
        j = i - 1;

        while (j >= 0 && *(arr+j) > key) {
            *(arr+j+1) = *(arr+j);
            j = j - 1;
        }
        *(arr+j+1) = key;
    }
    return 0;
}


// running the program:
int main(){
    // array of integers & temporery var
    int raw_arr[array_size] = {0};
    int tmp;
    int i;

    // 50 times receive integer from user and add it to raw_arr 
    for(i=0; i<array_size; i++){
        scanf("%d", &tmp);
        *(raw_arr+ i) = tmp;  

    }
    // function call 
    insertion_sort(raw_arr, array_size);

    for(i=0; i<array_size-1; i++){
        printf("%d,",*(raw_arr+ i));
    }
    printf("%d\n",*(raw_arr+ array_size-1));

    return 0;
}