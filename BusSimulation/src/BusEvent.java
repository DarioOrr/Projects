//Written by Dario Orr and Osman Abdullahi

public class BusEvent implements IEvent {
  private BusStop currStop;
  private Bus bus;

  public BusEvent(BusStop curStop, Bus bus) {
  	this.currStop = curStop;
    this.bus = bus;
	}


	@Override
	public void run() {
		int totaltime=0;

		//People deboarding
		if (bus.removePassenger(currStop).equals(true)) {
			bus.removePassenger(currStop);
			BusEvent deboard = new BusEvent(currStop, bus);
			BusSim.agenda.add(deboard, bus.numReturn*2);  //2 seconds for every passenger to deboard
			totaltime += bus.numReturn*2;
			return;
		}

		//People are boarding on the bus
		if (bus.isFull()==false && (BusSim.busStops[currStop.getStopNumber()].goingEast.length()!=0 || BusSim.busStops[currStop.getStopNumber()].goingWest.length()!=0)){

		    int numBoarded=0;

			if (bus.getDirection() == false) {      //bus headed west
				if (BusSim.busStops[currStop.getStopNumber()].goingWest.length() != 0) {
					for (int i = 0; i < BusSim.busStops[currStop.getStopNumber()].goingWest.length(); i++) {
						Passenger add = (Passenger)BusSim.busStops[currStop.getStopNumber()].goingWest.remove();
						if (bus.addPassenger(add)) {
							add.setWaitingTime(BusSim.agenda.getCurrentTime()-add.getArrivalTime());
							numBoarded++;
						}
						else{
							break;
						}
					}
				}
			}

            else {   // bus headed East
                if (BusSim.busStops[currStop.getStopNumber()].goingEast.length() != 0){  //if eastbound passengers at stop
                    for (int i = 0; i < BusSim.busStops[currStop.getStopNumber()].goingEast.length(); i++) {
                        Passenger add = (Passenger)BusSim.busStops[currStop.getStopNumber()].goingEast.remove();
                        if (bus.addPassenger(add)) {
                            numBoarded++;
                            add.setWaitingTime(BusSim.agenda.getCurrentTime()-add.getArrivalTime());
                        }
                        else{
                            break;
                        }

                    }
                }
            }

			BusEvent board = new BusEvent(currStop, bus);
			totaltime+= numBoarded*3;//Amount of time it takes each passenger to board
		}


		if (totaltime < 15){ //Bus stops for 15 seconds at each stop
			int restOfTime = 15 - totaltime;
			BusEvent wait = new BusEvent(currStop, bus);
			BusSim.agenda.add(wait, restOfTime);
			return;
		}

		BusStop nextStop;
		if (currStop.getStopNumber()==15 && bus.getDirection()){  //Bus is at the east most stop, have to turn it around
			bus.setDirection(false);                              //To go east
		}
		if (currStop.getStopNumber()==0 && !bus.getDirection()){ //Bus is at the west most stop, have to turn it around
																//To go east
			bus.setDirection(true);
		}
		if (bus.getDirection()){
			nextStop= BusSim.busStops[currStop.getStopNumber() + 1]; //If bus is going east, incrememnt the stop
		}
		else{
			nextStop = BusSim.busStops[currStop.getStopNumber() - 1]; //If bus is going west, decrement the stop
			//if westbound decrement to next stop
		}

		BusEvent nextEvent = new BusEvent(nextStop, bus);
		BusSim.agenda.add(nextEvent, 240); //Bus goes to next stop, takes 240 seconds
	}
}
