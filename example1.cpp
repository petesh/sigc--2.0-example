#include <iostream>
#include <sigc++/sigc++.h>

class AlienDetector
{
public:
    AlienDetector();

    void run();

    sigc::signal<void> signal_detected;
};

AlienDetector::AlienDetector() {}

void AlienDetector::run() {
    sleep(3); // wait for aliens
    signal_detected.emit(); // panic
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
