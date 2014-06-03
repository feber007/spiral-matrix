#include <stdio.h>
#include <stdlib.h>

void set_matrix(int *m, int size, int offset, int num) {
    int origin = offset + size * offset;
    int partical_size = size - offset * 2;
    int i, j;

    if (partical_size == 0) return;    // 0x0
    else if (partical_size == 1) {     // 1x1
        m[origin] = num;
        return;
    }

    for (j = 0; j < partical_size - 1; j++)
        m[origin + j * size] = num++;
    for (i = 0; i < partical_size - 1; i++)
        m[origin + i + (partical_size - 1) * size] = num++;
    for (j = partical_size - 1; j > 0; j--)
        m[origin + partical_size - 1 + j * size] = num++;
    for (i = partical_size - 1; i > 0; i--)
        m[origin + i] = num++;

    set_matrix(m, size, offset + 1, num);
}

int main() {
    int *m;
    int size;
    int i;

    while (1) {
        printf("Input an integer as matrix size: ");
        scanf("%d", &size);

        m = malloc(size * 4);
        set_matrix(m, size, 0, 1);

        printf("\n-----------------------------------\n");
        printf("Spiral matrix (%d cols, %d rows):\n", size, size);
        for (i = 0; i < size * size; i++) {
            if (i % size == 0)
                printf("\n");

            printf("%3d ", m[i]);
        }
        printf("\n-----------------------------------\n\n");

        free(m);
        m = NULL;
    }
    return 0;
}
