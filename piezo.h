#ifndef PIEZO_H
#define PIEZO_H

#include <QMutex>
#include <wiringPi.h>
#include <softTone.h>

class Piezo
{
public:
    static Piezo* instance()
    {
        static QMutex mutex;
        if (!m_Instance)
        {
            mutex.lock();

            if (!m_Instance)
            {
                m_Instance = new Piezo;
            }

            mutex.unlock();
        }

        return m_Instance;
    }

    static void drop()
    {
        static QMutex mutex;
        mutex.lock();
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

private:
    Piezo() {}
    Piezo(const Piezo &);
    Piezo& operator=(const Piezo &);
    static Piezo* m_Instance;

public:
    void good(int pin = 0);
    void bad(int pin = 0);
    void caution(int pin = 0);
};


#endif // PIEZO_H
