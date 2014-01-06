#pragma once

#include <sigc++/sigc++.h>

class AlienDetector
{
public:
    AlienDetector();

    void run();

    sigc::signal<void> signal_detected;
};
