#include <stdio.h>
#include <stdlib.h>
char arr[100][100] = {' '};

void circleMidpoint(int xCenter,int yCenter,int radius);

void main() {
    // Example usage
    circleMidpoint(50, 50, 20);

    // Printing the array
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void circleMidpoint (int xCenter, int yCenter, int radius){
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    void circlePlotPoints (int, int, int, int);
    // Plot first set of points 
    circlePlotPoints (xCenter,yCenter,x,y);
    while (x < y){
        x++ ;
        if (p<0)
            p+=2*x + 1;
        else{
            y--;
            p+=2*(x-y) + 1;
        }
        circlePlotPoints(xCenter,yCenter,x,y);
    }
}
void circlePlotPoints(int xCenter, int yCenter, int x, int y){
    arr[xCenter + x][yCenter + y]='.';
    arr[xCenter - x][yCenter + y]='.';
    arr[xCenter + x][yCenter - y]='.';
    arr[xCenter - x][yCenter - y]='.';
    arr[xCenter + y][yCenter + x]='.';
    arr[xCenter - y][yCenter + x]='.';
    arr[xCenter + y][yCenter - x]='.';
    arr[xCenter - y][yCenter - x]='.';
}