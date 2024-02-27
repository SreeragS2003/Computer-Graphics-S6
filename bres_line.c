#include <stdio.h>
#include <stdlib.h>

char arr[30][30] = {' '};

void linebres(int xa, int ya, int xb, int yb);

int main() {
    int x1, y1, x2, y2;

    printf("Enter coordinates of first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter coordinates of second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    linebres(x1, y1, x2, y2);

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void linebres(int xa, int ya, int xb, int yb) {
    int dx = abs(xa - xb), dy = abs(ya - yb);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyDx = 2 * (dy - dx);
    int x, y, xEnd;

    if (xa > xb) {
        x = xb;
        y = yb;
        xEnd = xa;
    } else {
        x = xa;
        y = ya;
        xEnd = xb;
    }

    arr[x][y] = '.';
    while (x < xEnd) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y++;
            p += twoDyDx;
        }
        arr[x][y] = '.';
    }
    printf("Coordinates of marked points:\n");
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            if (arr[i][j] == '.')
                printf("x = %d, y = %d\n", i, j);
        }
    }
}
