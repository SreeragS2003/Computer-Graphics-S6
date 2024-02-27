#include <stdio.h>
#include <stdlib.h>

int arr[40][40] = {0};

void drawCircle(int xc, int yc, int x, int y) 
{ 
    arr[xc + x][yc + y] = 1;
    arr[xc - x][yc + y] = 1;
    arr[xc + x][yc - y] = 1;
    arr[xc - x][yc - y] = 1;
    arr[xc + y][yc + x] = 1;
    arr[xc - y][yc + x] = 1;
    arr[xc + y][yc - x] = 1;
    arr[xc - y][yc - x] = 1;
} 

void circle(int xc, int yc, int r) 
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
            p += 4 * (x - y) + 10; 
        } 
        else
            p += 4 * x + 6; 
        drawCircle(xc, yc, x, y); 
    } 
} 

int main() 
{ 
    circle(20, 20, 10);
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) 
            printf("%c", arr[i][j] ? '.' : ' ');
        printf("\n");
    }
    return 0;
}
