#include <stdio.h>
#include <stdlib.h>

struct recnode{
    int length;
    int breadth;
    int area;
};
//swap &a, &b
void swap(struct recnode *a, struct recnode *b) { 
  struct recnode t = *a; 
  *a = *b; 
  *b = t; 
} 
struct recnode *array[10];
struct recnode* Newnode(int l, int b){
    int area = l*b;
    struct recnode *nn = (struct recnode*)malloc(sizeof(struct recnode));
    nn->length = l;
    nn->breadth = b;
    nn->area = area;
    return nn;
}
int find_min(void){
    int i;
    int var = array[0]->area;
    for(i=0;i<2;i++){
        if(array[i]->area < var){
            var = array[i]->area;
        }
    }
    return var;
}
int find_sum_area(void){
    int i;
    int var = 0;
    for(i=0;i<10;i++){
        var = array[i]->area + var;
    }
    return var;
}
int find_sum_length(void){
    int i;
    int var = 0;
    for(i=0;i<10;i++){
        var = array[i]->length + var;
    }
    return var;
}
int find_sum_breadth(void){
    int i;
    int var = 0;
    for(i=0;i<10;i++){
        var = array[i]->breadth + var;
    }
    return var;
}
void sort_by_area(void){
    int i, j, min_idx;
    for (i = 0; i < 10 - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < 10; j++)
            if (array[j]->area < array[min_idx]->area)
                min_idx = j;
        swap(array[min_idx], array[i]);
    }
}
int find_avg_length(void){
    int i;
    int var = 0;
    for(i=0;i<10;i++){
        var = array[i]->length + var;
    }
    return var/10;
}
int find_avg_breadth(void){
    int i;
    int var = 0;
    for(i=0;i<10;i++){
        var = array[i]->breadth + var;
    }
    return var/10;
}
int find_avg_area(void){
    int i;
    int var = 0;
    for(i=0;i<10;i++){
        var = array[i]->area + var;
    }
    return var/10;
}
void sort_by_width(void){
    int i, j, min_idx;
    for (i = 0; i < 10 - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < 10; j++)
            if (array[j]->breadth < array[min_idx]->breadth)
                min_idx = j;
        swap(array[min_idx], array[i]);
    }
}
int L2_X_B2(void){
    int soa = find_sum_area();
    int lxb = find_sum_breadth()*find_sum_length();
    if(lxb<soa){
        printf("l2 * b2 smaller than sum of area");
    }
    if(lxb == soa){
        printf("l2 * b2 == sum of area");
    }
    else{
        printf("l2 * b2 greater than sum of area");
    }
}
void print(void){
    int i;
    for(i=0;i<10;i++){
        printf("for node %i\n", i);
        printf("length = %i\n", array[i]->length);
        printf("breadth = %i\n", array[i]->breadth);
        printf("area = %i\n\n", array[i]->area); 
    }
}
int main(void){
    array[0] = Newnode(1, 50);
    array[1] = Newnode(2, 3);
    array[2] = Newnode(3, 4);
    array[3] = Newnode(4, 5);
    array[4] = Newnode(5, 6);
    array[5] = Newnode(6, 7);
    array[6] = Newnode(7, 8);
    array[7] = Newnode(8, 9);
    array[8] = Newnode(9, 10);
    array[9] = Newnode(10, 11);

    int sum_of_area = find_sum_area();
    sort_by_area();
    sort_by_width();
    int var = find_min();
}

    
