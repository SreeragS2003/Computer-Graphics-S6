#include <stdio.h>
#include <stdlib.h>

char arr[30][30] = {' '};

void linebres(int xa, int ya, int xb, int yb);

void main() {
    // Example usage
    linebres(1, 1, 20,25);

    // Printing the array
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void linebres (int xa, int ya, int xb, int yb)
{
    int dx = abs (xa - xb), dy = abs (ya - yb);
    int p = 2 * dy - dx;
    int twoDy = 2*dy, twoDyDx = 2*(dy - dx);
    int x, y, xEnd;
    // Determine which point to use as start, which as end
    if (xa > xb) {
        x = xb;
        y = yb;
        xEnd = xa;
    }
    else{
        x = xa;
        y = ya;
        xEnd = xb;
    }
    arr[x][y]='.';
    while (x < xEnd){
        x++;
        if (p < 0)
            p += twoDy;
        else{
            y++;
            p += twoDyDx;
        }
        arr[x][y]='.';
    }
}