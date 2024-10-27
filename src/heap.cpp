#include "heap.h"

Color getDistinctHeapColor(int index, int totalSize) {
    float hue = (float)index / totalSize * 360.0f;  // Assign each heap level a distinct hue
    return ColorFromHSV(hue, 0.9f, 0.9f);  // Full saturation, high brightness for distinct colors
}

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        numArrayAccesses += 2;

        // Play sound after swap
        float pitch = mapHeightToPitch(arr[largest], WINDOW_HEIGHT);
        SetSoundPitch(tickSound, pitch);
        PlaySound(tickSound);

        // Visualize the array
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the heap levels with distinct colors
        for (int i = 0; i < NUM_BARS; i++) {
            Color barColor = getDistinctHeapColor(i, NUM_BARS);
            DrawRectangle(i * BAR_WIDTH, WINDOW_HEIGHT - arr[i], BAR_WIDTH - 1, arr[i], barColor);
        }

        DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
        DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
        EndDrawing();

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        numArrayAccesses += 2;

        // Play sound after swap
        float pitch = mapHeightToPitch(arr[0], WINDOW_HEIGHT);
        SetSoundPitch(tickSound, pitch);
        PlaySound(tickSound);

        // Visualize the heap
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the heap levels with distinct colors
        for (int j = 0; j < NUM_BARS; j++) {
            Color barColor = getDistinctHeapColor(j, NUM_BARS);
            DrawRectangle(j * BAR_WIDTH, WINDOW_HEIGHT - arr[j], BAR_WIDTH - 1, arr[j], barColor);
        }

        DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
        DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
        EndDrawing();

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}
