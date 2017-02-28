#include "Vision.h"
#include "../RobotMap.h"
#include "PixySPI.h"
#include <SmartDashboard/SendableChooser.h>

PixySPI *pixy1;
SPI::Port port = SPI::Port::kOnboardCS0;
PixySPI::PacketMapSet *packets;

Vision::Vision() : Subsystem("Vision") {
	// Open a pipeline to a Pixy camera.
	pixy1 = new PixySPI(port);
	packets = pixy1->getPackets();

	SmartDashboard::PutString("Vision: Object created", "true");
}

void Vision::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// These values are the default if you instantiate a PixySPI without arguments.
// To create multiple PixySPI objects and thus use multiple Pixy cameras via SPI
// Copy the items below, change variable names as needed and especially change
// the SPI port used eg; Port.kOnboardCS[0-3] or Port.kMXP

void Vision::testPixy1(){
	// Get the packets from the pixy.
	int ret = pixy1->readPackets();
	pixy1->setDebugLvl(0);

	SmartDashboard::PutString("Pixy Vision: packets size: ", std::to_string(packets->size()));

	for(int i = 1; i <= pixy1->getPixySigCount() ; i++) {
		SmartDashboard::PutString("Pixy Vision: Signature: ", std::to_string(i));

		SmartDashboard::PutString("Pixy Vision: packet: " + std::to_string(i) + ": size: ", std::to_string(packets->at(i).size()));

		// Loop through the packets for this signature.
		for(int j=0; j < packets->at(i).size(); j++) {
			SmartDashboard::PutString("Pixy Vision: " + std::to_string(i) + ": X: ", std::to_string(packets->at(i).at(j).X));
			SmartDashboard::PutString("Pixy Vision: " + std::to_string(i) + ": Y: ", std::to_string(packets->at(i).at(j).Y));
			SmartDashboard::PutString("Pixy Vision: " + std::to_string(i) + ": Width: ", std::to_string(packets->at(i).at(j).Width));
			SmartDashboard::PutString("Pixy Vision: " + std::to_string(i) + ": Height: ", std::to_string(packets->at(i).at(j).Height));
		}
	}
}
