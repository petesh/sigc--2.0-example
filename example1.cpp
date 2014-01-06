#include <iostream>
#include <sigc++/sigc++.h>
#include "detector.h"

using namespace std;

void warn_people()
{
    cout << "There are aliens in the carpark!" << endl;
}

int main()
{
    AlienDetector mydetector;
    mydetector.signal_detected.connect( sigc::ptr_fun(warn_people) );

    mydetector.run();

    return 0;
}
