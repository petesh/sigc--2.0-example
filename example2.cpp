#include <sigc++/sigc++.h>
#include <string>
#include <iostream>

class Transmitter {
    protected:
        std::string m_origin;
        sigc::signal<void, const std::string &> m_slot;

    public:
        Transmitter(const std::string origin) : m_origin(origin) {}
        sigc::signal<void, const std::string &> &getSlot() { return m_slot; }

        void run(void);
};

void
Transmitter::run(void)
{
    sleep(2);
    m_slot.emit(m_origin);
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

    transmit.getSlot().connect( sigc::mem_fun(receipt, &Receiver::get_message) );

    transmit.run();

    return 0;
}
