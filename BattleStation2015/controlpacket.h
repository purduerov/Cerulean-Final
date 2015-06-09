#ifndef CONTROLPACKET_H
#define CONTROLPACKET_H

#include "main.h"
#include "motor.h"

#include <QByteArray>

#define PACKET_SIZE 20

#define HEADER 0x12
#define TAIL 0x13

#define CONTROL 0x01

#define CRC_BYTE 0xC5

#define THRUSTER_BYTE_START 2

#define FOOT_TURNER 10

#define TOOLS 11

#define STEPPER 12

#define LED_START 13

#define THRUSTER_COUNT 8

#define LED_COUNT 5


class ControlPacket
{
public:
    ControlPacket();
    ~ControlPacket();

    void setThrusters(Motor** motors);


    void setFootTurner(Motor* motor);

    void setCamMux1(bool camMux1);

    void setCamMux2(bool camMux2);

    void setBilgePump(bool enabled);

    void setVoltageMeasurement(bool enabled);

    void setLaser(bool enabled);

    void setClaw(bool active, bool opening, bool parallel);

    void setLEDs(quint8 values[5]);

    void setVStepper(bool upDirection, quint8 value);

    void setHStepper(bool rightDirection, quint8 value);


    QByteArray getPacket();

    void reset();

    void print();


private:
    quint8 size;
    QByteArray data;


    quint8 thrusterValues[THRUSTER_COUNT];
    quint8 footTurner;

    bool camMux1;
    bool camMux2;

    bool bilgePump;

    bool voltageMeasurement;

    bool laser;

    bool clawOpening;
    bool clawClosing;

    bool clawParallel;

    bool vStepperUpDirection;
    quint8 vStepperAmount;

    bool hStepperRightDirection;
    quint8 hStepperAmount;

    quint8 ledValues[LED_COUNT];

    void setThruster(Motor* motor);

    quint8 getToolByte();

    quint8 getStepperByte();

    void assemblePacket();

    quint8 crc(QByteArray data);

};

#endif // CONTROLPACKET_H
