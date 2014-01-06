#include <iostream>
#include <sigc++/sigc++.h>

class AlienDetector
{
public:
    AlienDetector();

    void run();

    sigc::signal<void> signal_detected; // This is a slot container for void functions
};

AlienDetector::AlienDetector() {}

void AlienDetector::run() {
    sleep(3); // wait for aliens
    signal_detected.emit(); // send the signal. Because there's no parameter, none is passed to emit.
}

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
