#include "common.h"
#include <cmath>
#include <cstring>

const int datapoint_width = 4;
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1200;
//const int WINDOW_WIDTH = 5120;
//const int WINDOW_HEIGHT = 1440;
const int NUM_BARS = WINDOW_WIDTH / datapoint_width;
const int BAR_WIDTH = datapoint_width;

std::vector<int> array(NUM_BARS);
int numComparisons = 0;
int numArrayAccesses = 0;
bool sortingCompleted = false;
Sound tickSound;
float baseFrequency = 500.0f;

float mapHeightToPitch(int height, int maxHeight) {
    return 0.5f + (float)height / (float)maxHeight * 2.0f;
}

Sound generateBaseSound(float frequency, int durationMs) {
    Wave wave = { 0 };
    wave.frameCount = durationMs * (44100 / 1000);
    wave.sampleRate = 44100;
    wave.sampleSize = 16;
    wave.channels = 1;
    wave.data = malloc(wave.frameCount * sizeof(short));
    memset(wave.data, 0, wave.frameCount * sizeof(short));

    for (int i = 0; i < wave.frameCount; i++) {
        float amplitude = sinf((2.0f * PI * frequency * i) / wave.sampleRate);
        ((short*)wave.data)[i] = (short)(amplitude * 32767);
    }

    return LoadSoundFromWave(wave);
}
