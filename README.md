# Environment-Monitoring-System-Using-GSM-Web-Server
Developed Low Cost, High-Accuracy Environment Monitoring System (EMS) Using GSM and Web Server

## Introduction to Work Done (Overview, Applications & Features):

The proposed idea cropped as a result of designing an ambient air quality monitoring system that has a capability to track certain environment parameters continuously.

In this project environment parameters are processed by uploading the data’s to the internet using GPRS technology. The proposed idea involved two parts: 

1. Development of a cost effective environment monitoring prototype air quality sensor unit and 
2. The deployment of the unit to monitor different locations. 

The data from the sample monitoring locations will then be compiled and analyzed. The main objective is to develop a device which is able to monitor certain atmospheric components such as CO2, CO, alcohol etc. gases and display their data (concentration in ppm) on an LCD screen at the interval of 3 seconds. Since our system is available at any time, hence as soon as gas gets detected an SMS is sent to the authorized user. In addition to it, the data has to be displayed on a web server for continuous tracking of measured gas concentration (in ppm). 

The advantage of using GSM based technology is that GSM based communication network is widespread and have almost reached to every corners of this 21st century world. GSM technology also does provide users with high quality signal and channels, giving them access to high quality digital communication at very affordable rates.

## Objective of the Project:

The objective of this project is to design a low cost, easy to use, environment monitoring system in which an Arduino UNO board with built-in ATmega328 microcontroller is interfaced with JHD162A (16*2 LCD), MQ-135 Air Quality Gas Sensor and SIMCOM SIM900 series GSM Module to transmit sensed data wirelessly. The project aims at:-
•	Designing a quick response, less hardware involved device which is able to monitor certain atmospheric pollutants and transfer the data continuously for the display and being stored and updated at the database and onto the web server.

•	Analog data from MQ-135 air quality gas sensor is to be fetched and fed to one of the ADC channel of Arduino UNO board. 

•	Display the gas concentration (in ppm) on LCD screen at interval of 3 seconds, which is pre-processed and calculated by Arduino UNO board on Arduino IDE software. 

•	Send the rough and approximate measured gas concentration value (in ppm) to the authorized user with the help of GSM module (SIM 900 series) via SMS. 

•	Finally, the acquired data collected from sensor is then plotted in real-time on a PC and can be stored to a web server. 

## Main Hardware Involved:

1. Arduino UNO with built-in ATmega32 microcontroller, 
2. MQ-135 Air Quality Gas Sensor, 
3. Alphanumeric 16*2 LCD (JHD162A),
4. SIMCOM SIM 900 series GSM Module etc.

## Block Diagram:

![The Block Diagram](../master/BlockDiagram/BlockDiagram.png)


## Circuit Diagram:

![The Circuit Diagram](../master/CircuitDiagram/CircuitDiagram.png)

## Software Part:
A PHP based Web-Server was designed to aid continuous tracking of air pollutants gas concentration (in ppm) such as CO2, CO and Alcohol. It may also be useful for adding and testing purposes of gas concentration (in ppm). It is not intended to be a full-featured web server and should not be used on a public network.

![The PHP Web Server](../master/Images/PHP-WebServer.png)

![PHP WebServer Gas Check](../master/Images/PHP-WebServer-Gas-Check.png)

## Prototype:

![The Prototype](../master/Images/PrototypeModel.png)
