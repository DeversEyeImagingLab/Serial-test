// CSerial Library
#include "CSerial/Serial.h"

// Other
#include <iostream>

static const int STIM_SERIAL_PORT_NUMBER = 5; // 5 for COM 5
static const int STIM_SERIAL_BAUD_RATE = 250000; // Highest "official" Windows
												 // baud rate, Arduino may be able to go
												 // up to 2M baud.

int main(int argc, char* argv[])
{
	//std::cout << "Hello World!" << std::endl;

	// Arduino
	CSerial serialPort();

    // Open serial port
    //if (!serialPort->Open(STIM_SERIAL_PORT_NUMBER, STIM_SERIAL_BAUD_RATE))
    //    std::cout << "\nFailed to open communications with Arduino!\n"
    //    << "Projector controls will not be supported!\n\n";
    //else
    //    std::cout << "Opened serial port successfully\n";


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