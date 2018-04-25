# -------------------------------------------------------------- SOUND SENSOR PROJECT --------------------------------------------------------------

This project is meant to collect sound level at a proximity of a Raspberry Pi device. The RPi is equipped a USB sound card (C-Media Electronics, Inc.
Audio Adapter) and a microphone. The sound is recorded at 16000Hz samples rate and every second will produce 80 pieces of RMS value as a bar-diagram...

Table of Content

1. Configuration

	1.1 Hardware requirements:
		This project is built on a Raspberry Pi 3. Users need a USB Sound card and a microphone. In order that the acoustic data could be sent 
		to a server, Ethernet connection is also needed.
	1.2 Software configuration:
		a. Setting USB Sound card as default audio device:
			*Run command "alsamixer" to see if the USB Sound card is the default audio device.
			*Make sure the volume of your microphone is 100 so it can record everything.
		b. Downgrading alsa-utils from 1.0.28 to 1.0.25
			*Version 1.0.28 of alsa-utils has an error with recording, you need to use the 1.0.25 version.
			*To check if the microphone is working, a test1.wav file is generated in your current folder by running "apply test1.wav" to 
			see if your recording is alright.
		c. Installing libcurl libary:
			To send data to the server, you  need to install the libcurl library. Type command "sudo apt-get install libcurl4-openssl-dev"
			and wait for the installation.
		
2. Installation

	How to untar the package and how to generate the executable:
	*When you have the package as final.tar file, you can untar it by using command "tar -xvf [file_name].tar". All the source files will appear in 
	the same folder.
	*Type command "make" to generate executable files
	
3. Operation

	To run the application, simply type command "./test.a" and start recording on your microphone. You will be able to see the bars with different 
	heights and colors indicating the volumes of your sounds.
	To stop recording, press Ctrl+C
	
4. Manifest (List of files and short description of their roles)

5. License

	Copyright (C) 2018
	
	This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the 
	Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILIY
	or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	
6. Contact information
	
	Thao Nguyen
	VAMK, Vaasa University of Applied Sciences
	Email: thao.nguyen.6.2.1991@gmail.com
	
