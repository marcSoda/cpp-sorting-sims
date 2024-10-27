#pragma once
#include "raylib.h"
#include <vector>

extern const int datapoint_width;
extern const int WINDOW_WIDTH;
extern const int WINDOW_HEIGHT;
extern const int NUM_BARS;
extern const int BAR_WIDTH;

// Shared variables
extern std::vector<int> array;
extern int numComparisons;
extern int numArrayAccesses;
extern bool sortingCompleted;
extern Sound tickSound;
extern float baseFrequency;

float mapHeightToPitch(int height, int maxHeight);
Sound generateBaseSound(float frequency, int durationMs);
