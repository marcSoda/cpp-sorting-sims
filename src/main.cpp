#include "heap.h"
#include "merge.h"
#include "quick.h"
#include "common.h"
#include <cstring>
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <merge|heap|quick>" << std::endl;
        return 1;
    }

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sorting Visualization - raylib");
    InitAudioDevice();
    SetTargetFPS(1000);

    srand(time(0));
    for (int i = 0; i < NUM_BARS; i++) {
        array[i] = rand() % WINDOW_HEIGHT;
    }

    std::shuffle(array.begin(), array.end(), std::default_random_engine(std::time(0)));
    tickSound = generateBaseSound(baseFrequency, 10);

    if (strcmp(argv[1], "merge") == 0) {
        mergeSort(array, 0, NUM_BARS - 1);
    } else if (strcmp(argv[1], "heap") == 0) {
        heapSort(array);
    } else if (strcmp(argv[1], "quick") == 0) {
        quickSort(array, 0, NUM_BARS - 1);  // Call quickSort
    } else {
        std::cerr << "Invalid argument. Use 'merge', 'heap', or 'quick'." << std::endl;
        return 1;
    }

    CloseAudioDevice();
    UnloadSound(tickSound);
    CloseWindow();

    return 0;
}
