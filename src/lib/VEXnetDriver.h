/**
 * @file VEXnetDriver.h
 * @author Eric Heinke (sudo-Eric), Zrp200
 * @version 0.5a
 * @date September 30 2022
 * @brief Code for communicating using the VEXnet
 */

#ifndef VEXNETDRIVER_H
#define VEXNETDRIVER_H

#include "serialib.h"
#include "DecodeStatusCodes.h"
#include "VEXnetPacket.h"

struct VEXnetDriver {
    enum DeviceType {
        VEX_LCD_Display,
        VEXnet_Joystick_Partner_Port
    };

    VEXnetDriver() {};
    VEXnetDriver(const char *device, DeviceType deviceType, bool showSuccess);
    VEXnetDriver(const char *device, unsigned int bauds, SerialDataBits dataBits, 
                 SerialParity parity, SerialStopBits stopBits, bool showSuccess);
    ~VEXnetDriver() {serial.closeDevice();};

    bool isDeviceOpen() { return serial.isDeviceOpen(); }
    void SendVexProtocolPacket(const VEXnetPacket &packet);
    VEXnetPacket* ReceiveVexProtocolPacket();

private:
    serialib serial;
    DecodeStatusCodes statusCodes;
};

#endif // VEXNETDRIVER_H