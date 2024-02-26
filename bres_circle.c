#include <stdio.h>
#include <stdlib.h>
char arr[100][100] = {' '};

void drawCircle(int xc, int yc, int x, int y);
void circleBres(int xc, int yc, int r);
void main() 
{ 
    // Example usage
    circleBres(50, 50, 20);

    // Printing the array
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}
void drawCircle(int xc, int yc, int x, int y) 
{ 
    arr[xc+x][yc+y]='.';
    arr[xc-x][yc+y]='.';
    arr[xc+x][yc-y]='.';
    arr[xc-x][yc-y]='.';
    arr[xc+y][yc+x]='.';
    arr[xc-y][yc+x]='.';
    arr[xc+y][yc-x]='.';
    arr[xc-y][yc-x]='.';
} 
  

void circleBres(int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int p = 3 - 2 * r; 
    drawCircle(xc, yc, x, y); 
    while (y >= x) 
    {
        x++; 
        if (p > 0) 
        { 
            y--;  
            p+=4*(x - y) + 10; 
        } 
        else
            p+=4*x + 6; 
        drawCircle(xc, yc, x, y); 
    } 
} 

