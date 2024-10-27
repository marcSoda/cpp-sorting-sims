#include "quick.h"

// Function to partition the array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivot element is the last one
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        numComparisons++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
            numArrayAccesses += 2;

            // Play sound after swap
            float pitch = mapHeightToPitch(arr[i], WINDOW_HEIGHT);
            SetSoundPitch(tickSound, pitch);
            PlaySound(tickSound);

            // Visualize the array after each swap
            BeginDrawing();
            ClearBackground(BLACK);

            // Draw the array elements
            for (int k = 0; k < NUM_BARS; k++) {
                Color barColor = WHITE;
                if (k == i) barColor = BLUE;           // Highlight the smaller element
                else if (k == j) barColor = RED;       // Highlight the current element being compared
                else if (k == high) barColor = GREEN;  // Highlight the pivot element
                DrawRectangle(k * BAR_WIDTH, WINDOW_HEIGHT - arr[k], BAR_WIDTH - 1, arr[k], barColor);
            }

            // Display statistics
            DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
            DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
            EndDrawing();
        }
    }

    std::swap(arr[i + 1], arr[high]);
    numArrayAccesses += 2;

    // Play sound after placing the pivot
    float pitch = mapHeightToPitch(arr[i + 1], WINDOW_HEIGHT);
    SetSoundPitch(tickSound, pitch);
    PlaySound(tickSound);

    // Visualize the array after placing the pivot
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw the array elements
    for (int k = 0; k < NUM_BARS; k++) {
        Color barColor = WHITE;
        if (k == i + 1) barColor = GREEN;  // Pivot element after swap
        DrawRectangle(k * BAR_WIDTH, WINDOW_HEIGHT - arr[k], BAR_WIDTH - 1, arr[k], barColor);
    }

    // Display statistics
    DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
    DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
    EndDrawing();

    return i + 1;
}

// Quick Sort function (recursive)
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
