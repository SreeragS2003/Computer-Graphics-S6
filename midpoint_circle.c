#include <stdio.h>
#include <stdlib.h>

int arr[40][40] = {0};

void circlePoints (int, int, int, int);

void circle (int xCen, int yCen, int radius){
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    circlePoints (xCen,yCen,x,y);
    while (x < y){
        x++ ;
        if (p<0)
            p+=2*x + 1;
        else{
            y--;
            p+=2*(x-y) + 1;
        }
        circlePoints(xCen,yCen,x,y);
    }
}

void circlePoints(int xCen, int yCen, int x, int y){
    arr[xCen + x][yCen + y]=1;
    arr[xCen - x][yCen + y]=1;
    arr[xCen + x][yCen - y]=1;
    arr[xCen - x][yCen - y]=1;
    arr[xCen + y][yCen + x]=1;
    arr[xCen - y][yCen + x]=1;
    arr[xCen + y][yCen - x]=1;
    arr[xCen - y][yCen - x]=1;
}

void main() {
    circle(20, 20, 10);
    for (int i = 0; i <40; i++) {
        for (int j = 0; j < 40; j++) {
            printf("%c", arr[i][j] ? '.' : ' ');
        }
        printf("\n");
    }
}
