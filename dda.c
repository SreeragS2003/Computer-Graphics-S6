#include <stdio.h>
#include <stdlib.h>

char arr[30][30] = {' '};

void lineDDA(int xa, int ya, int xb, int yb);

void main() {
    // Example usage
    lineDDA(1, 1, 20,25);

    // Printing the array
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < 30; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void lineDDA(int xa, int ya, int xb, int yb) {
    int dx = xb - xa, dy = yb - ya, steps, k;
    float xIncrement, yIncrement, x = xa, y = ya;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xIncrement = (float)dx / steps;
    yIncrement = (float)dy / steps;
    arr[(int)x][(int)y] = '.';

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        arr[(int)x][(int)y] = '.';
    }
}