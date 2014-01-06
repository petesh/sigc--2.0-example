#include "detector.h"
#include <unistd.h>

AlienDetector::AlienDetector() {}

void AlienDetector::run() {
    sleep(3); // wait for aliens
    signal_detected.emit(); // panic
}

