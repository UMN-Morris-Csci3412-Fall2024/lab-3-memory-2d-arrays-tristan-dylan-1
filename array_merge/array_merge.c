#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdbool.h>

// Checks if the value is unique
bool is_unique(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return false;
        }
    }
    return true;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
    int unique_capacity = 1000;
    int* unique_values = (int *)malloc(sizeof(int) * 1000);
    int unique_count = 0;
    // Iterate through the loops
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            int value = values[i][j];
            // Check for uniqueness
            if (is_unique(unique_values, unique_count, value)) {
                // Add to unique_values
                if (unique_count >= unique_capacity) {
                    unique_capacity *= 2;
                    unique_values = (int*)realloc(unique_values, sizeof(int) * unique_capacity);
                }
                unique_values[unique_count++] = value;
            }
        }
    }
    // Allocate memory for the result array
    int* result = (int*)malloc(sizeof(int) * (unique_count + 1));
    result[0] = unique_count;
    for (int i = 0; i < unique_count; i++) {
        result[i + 1] = unique_values[i];
    }

    // Sort the result array
    mergesort(unique_count, result + 1);

    // Free the memory
    free(unique_values);

    return result;
}
