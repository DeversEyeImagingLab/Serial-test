// CSerial Library
// documentation: https://www.codeguru.com/network/cserial-a-c-class-for-serial-communications/
#include "CSerial/Serial.h"

// Other
#include <iostream>
//#include <cstdlib>

static const int STIM_SERIAL_PORT_NUMBER = 5; // 5 for COM 5
static const int STIM_SERIAL_BAUD_RATE = 9600; // Baud rate from civillaser documentation

int main(int argc, char* argv[])
{
	//std::cout << "Hello World!" << std::endl;

	// Create serial port
	CSerial serialPort;

    // Open serial port
    if (serialPort.Open(STIM_SERIAL_PORT_NUMBER, STIM_SERIAL_BAUD_RATE))
    {
        std::cout << "Serial connection opened to port COM" << STIM_SERIAL_PORT_NUMBER << std::endl;
    }
    else
    {
        std::cout << "Failed to open serial connection.\nExiting program.\n";
        return -1;
    }

    // Open serial port
    //if (!serialPort->Open(STIM_SERIAL_PORT_NUMBER, STIM_SERIAL_BAUD_RATE))
    //    std::cout << "\nFailed to open communications with Arduino!\n"
    //    << "Projector controls will not be supported!\n\n";
    //else
    //    std::cout << "Opened serial port successfully\n";

    // Send data
    // info on sending HEX data:
    // https://github.com/itas109/CSerialPort/issues/38 
    // converting hex to char:
    // https://www.rapidtables.com/convert/number/hex-to-ascii.html
    // https://stackoverflow.com/questions/1070497/c-convert-hex-string-to-signed-integer

    //  -   Try turning on / off laser
    // EF EF 03 26 01 08
    // ïï&
    std::string powerOn = "ïï&";
    serialPort.SendData(powerOn.c_str(), strlen(powerOn.c_str()));

    //serialPort->SendData(stop_projector_command, strlen(stop_projector_command));

    // Arduino thread
    /* Use this thread when debugging to make sure the serial port
       commands are correctly written to the arduino*/
       //std::thread arduinoThread(arduinoFeedback);

	return 0;
}

//void octSystem::arduinoFeedback()
//{
//    // Variables
//    int bytes_received = 0;
//    char* readBuffer = new char[100];
//
//    while (isSyncing.load())
//    {
//        bytes_received = serialPort->ReadData(readBuffer, 100);
//        if (bytes_received > 0)
//        {
//            std::cout << "Arduino: ";
//            for (int i = 0; i < bytes_received; i++)
//            {
//                std::cout << readBuffer[i];
//            }
//            std::cout << "\n";
//            //std::cout << "Arduino: " << readBuffer << "\n";
//            //std::cout << "Bytes received: " << bytes_received << "\n";
//            //readBuffer = new char[30];
//        }
//    }
//
//    delete[] readBuffer;
//}