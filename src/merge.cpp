#include "merge.h"

std::vector<int> arrayCopy(NUM_BARS);
int leftPos = 0, rightPos = 0, insertPos = 0;

void merge(std::vector<int>& arr, int lStart, int mid, int rEnd) {
    arrayCopy = arr;
    leftPos = lStart;
    rightPos = mid;
    insertPos = lStart;

    while (leftPos <= mid - 1 && rightPos <= rEnd) {
        numComparisons++;
        if (arrayCopy[leftPos] <= arrayCopy[rightPos]) {
            arr[insertPos] = arrayCopy[leftPos];
            leftPos++;
        } else {
            arr[insertPos] = arrayCopy[rightPos];
            rightPos++;
        }
        insertPos++;
        numArrayAccesses += 2;

        float pitch = mapHeightToPitch(arr[insertPos - 1], WINDOW_HEIGHT);
        SetSoundPitch(tickSound, pitch);
        PlaySound(tickSound);

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the points (smaller rectangles)
        for (int i = 0; i < NUM_BARS; i++) {
            // Merged elements are blue, everything else is white
            Color barColor = (i >= lStart && i < insertPos) ? BLUE : WHITE;
            DrawRectangle(i * BAR_WIDTH, WINDOW_HEIGHT - arr[i], BAR_WIDTH - 1, BAR_WIDTH - 1, barColor);
        }

        // Draw vertical cursors for merge process
        DrawRectangle(leftPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, RED);    // Left cursor
        DrawRectangle(rightPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, GREEN); // Right cursor
        DrawRectangle(insertPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, BLUE); // Insert cursor

        DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
        DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
        EndDrawing();
    }

    // Remaining elements from the left subarray
    while (leftPos <= mid - 1) {
        arr[insertPos] = arrayCopy[leftPos];
        leftPos++;
        insertPos++;
        numArrayAccesses += 2;

        float pitch = mapHeightToPitch(arr[insertPos - 1], WINDOW_HEIGHT);
        SetSoundPitch(tickSound, pitch);
        PlaySound(tickSound);

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the points (smaller rectangles)
        for (int i = 0; i < NUM_BARS; i++) {
            Color barColor = (i >= lStart && i < insertPos) ? BLUE : WHITE;
            DrawRectangle(i * BAR_WIDTH, WINDOW_HEIGHT - arr[i], BAR_WIDTH - 1, BAR_WIDTH - 1, barColor);
        }

        // Draw cursors
        DrawRectangle(leftPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, RED);    // Left cursor
        DrawRectangle(insertPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, BLUE); // Insert cursor

        DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
        DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
        EndDrawing();
    }

    // Remaining elements from the right subarray
    while (rightPos <= rEnd) {
        arr[insertPos] = arrayCopy[rightPos];
        rightPos++;
        insertPos++;
        numArrayAccesses += 2;

        float pitch = mapHeightToPitch(arr[insertPos - 1], WINDOW_HEIGHT);
        SetSoundPitch(tickSound, pitch);
        PlaySound(tickSound);

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw the points (smaller rectangles)
        for (int i = 0; i < NUM_BARS; i++) {
            Color barColor = (i >= lStart && i < insertPos) ? BLUE : WHITE;
            DrawRectangle(i * BAR_WIDTH, WINDOW_HEIGHT - arr[i], BAR_WIDTH - 1, BAR_WIDTH - 1, barColor);
        }

        // Draw cursors
        DrawRectangle(rightPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, GREEN); // Right cursor
        DrawRectangle(insertPos * BAR_WIDTH, 0, BAR_WIDTH, WINDOW_HEIGHT, BLUE); // Insert cursor

        DrawText(TextFormat("Comparisons: %d", numComparisons), 10, 10, 20, WHITE);
        DrawText(TextFormat("Array Accesses: %d", numArrayAccesses), 10, 40, 20, WHITE);
        EndDrawing();
    }
}

void mergeSort(std::vector<int>& arr, int start, int end) {
    int n = end - start + 1;
    if (n < 2) return;

    int mid = start + (n / 2);
    mergeSort(arr, start, mid - 1);
    mergeSort(arr, mid, end);
    merge(arr, start, mid, end);
}
