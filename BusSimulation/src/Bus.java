//Written by Dario Orr and Osman Abdullahi

import java.util.Random;

public class Bus{
	private static int busSize;
 	public int numPassengers; //Number of passengers present in bus
	private static boolean direction; //If true, bus going east, if false, bus going west.
	private boolean express = false;
 	Passenger[] pplInBus; //List of people in the bus
 	public int numReturn;


 	public Bus(int busSize) {  //Constructor for creating bus, the size, and adding passenger
		this.busSize = busSize;
   		pplInBus = new Passenger[busSize];
   		Random random = new Random();
   		direction = random.nextBoolean();
 	}

	public Bus(boolean express){
		numPassengers = 0;
      	pplInBus = new Passenger[50];
      	direction = true;
      	express = express;
  	}

  	public int getNum() {
 		return numPassengers;
  	}

	public boolean addPassenger(Passenger pass) { //Adds passengers to bus
	  	for(int i = 0; i< pplInBus.length-1; i++){
		  	if (pplInBus[i] == null){
			  	pplInBus[i] = pass;
			  	numPassengers++; //Increments amount of passengers on bus
			  	return true;
		  	}
	  	}
	  	return false;
  	}



	public Passenger[] removePassenger(BusStop stop){ //Removes passengers at specific stop
		Passenger[] dropOff = new Passenger[busSize];
		int numOff = 0;
		for(int i = 0; i < numPassengers; i++){
			if(pplInBus[i] != null && pplInBus[i].getdropOffStop()==stop.getStopNumber()){ //Ensures that there will be no
				//null pointer exception
				dropOff[numOff] = pplInBus[i];
				numOff++;
				pplInBus[i] = null;
				numPassengers--; //Decrements the amount of passengers on bus
			}
		}
		return dropOff;
	}

  	public boolean isExpress(){
    	return express;
  	}

  	public boolean getDirection() {
  		return direction;
  	}

	public void setDirection(boolean diffDirection) {
		direction = diffDirection;
	}

	public boolean isFull() {
 		if(numPassengers == 50) {
		    return true;
		}
 		return false;
	}
}
