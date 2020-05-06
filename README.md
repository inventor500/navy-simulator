# Navy Simulator

##Introduction
This is the traditional final project for CSC 231 at WLC.
This program takes in an orders file, and outputs a json file. This json file tracks the location of various aircraft and ships that were specified in the orders file.


## Usage
````Shell
Navy order.txt ouput.json
````
Orders are as following:

#### Create
Create an aircraft carrier: `CreateAirCraftCarrier Name ID Max-Aircraft-As-Integer Max-Speed-As-Integer`

Create a cruiser: `CreateCruiser Name ID Max-Missiles-As-Integer Max-Speed-As-Integer`

Create a fighter: `CreateFighter Name ID ID-Of-Ship Max-Speed-As-Integer Max-Ceiling-As-Integer Max-Bombs-As-Integer`


#### Simulation control
Start the simulation: `StartSim MM/DD/YYYY HH:MM:SS`

Stop the simulation: `StopSim MM/DD/YYYY HH:MM:SS`


#### Deployment
Deploy ship: `DeployShip M/D/YYYY HH:MM:SS ID Starting-X Starting-Y Heading Speed`

Deploy aircraft: `DeployAircraft MM/DD/YYYY HH:MM:SS ID Heading Speed Altitude`

Land aircraft: `LandAircraft MM/D/YYYY HH:MM:SS Ship-ID-To-Land-On Aircraft-ID`

*After LandAircraft is executed, the aircraft will continue towards the ship even if its orders are changed.*


#### Change orders
Change ship orders: `ChangeShipOrders MM/D/YYYY HH:MM:SS ID New-Heading New-Speed`

Change aircraft orders: `ChangeAircraftOrders MM/D/YYYY HH:MM:SS ID New-Heading New-Speed New-Altitude`

*If you do not want to change heading or speed in `ChangeShipOrders` or `ChangeAircraftOrders`, then replace with -1.*

#### Other

You can comment out a line by starting it with '#'.

## Things to be aware of
These aircraft are special. They take off vertically, and can land on each other.
