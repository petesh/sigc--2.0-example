#include <sigc++/sigc++.h>
#include <string>
#include <iostream>

class Transmitter {
    protected:
        std::string m_origin; // parameter being sent to the slot
        sigc::signal<void, const std::string &> m_slot; // slot for the signal

    public:
        Transmitter(const std::string origin) : m_origin(origin) {}
        sigc::signal<void, const std::string &> &getSlot() { return m_slot; }

        void run(void);
};

void
Transmitter::run(void)
{
    sleep(2);
    m_slot.emit(m_origin); // Emit the signal
}

class Receiver {
    public:
        Receiver() {}

        void get_message(const std::string &message);
};

void
Receiver::get_message(const std::string &message)
{
    std::cout << "Got the message: " << message << std::endl;
}

int main()
{
    Transmitter transmit("This is the message");
    Receiver receipt;

    // connect the member function get_message to the transmission slot, record the connection
    sigc::connection conn1 = transmit.getSlot().connect( sigc::mem_fun(receipt, &Receiver::get_message) );
    sigc::connection conn2 = transmit.getSlot().connect( sigc::mem_fun(receipt, &Receiver::get_message) );

    std::cout << "Expect two messages" << std::endl;
    transmit.run();
    conn1.disconnect();
    std::cout << "Expect one messages" << std::endl;
    transmit.run();

    return 0;
}
