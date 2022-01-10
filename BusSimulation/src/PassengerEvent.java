//Written by Dario Orr and Osman Abdullahi


public class PassengerEvent implements IEvent{

  private BusStop busStop;

  public PassengerEvent(BusStop busStop){
    this.busStop = busStop;
  }
  public BusStop getStop(){
    return busStop;
  }
  @Override
  public void run() {
      Passenger newPerson = new Passenger();
      newPerson.setArrivalTime(BusSim.agenda.getCurrentTime()); //Sets arrival time to the current time of the sim
      if (newPerson.getDirection()==true) { //Going east
          BusSim.busStops[busStop.getStopNumber()].goingEast.add(newPerson); //Adds the new person to the specific stop
          //they are at to the busStops list and sets their direction to going east
          if (BusSim.busStops[busStop.getStopNumber()].goingEast.length() > busStop.getMaxEast())
              busStop.setMaxEast(BusSim.busStops[busStop.getStopNumber()].goingEast.length());
      }        //Sets new max east station the bus will need to go to if the new passenger is going farther
                //East than any of the previous passengers
      else {
          BusSim.busStops[busStop.getStopNumber()].goingWest.add(newPerson);//Adds the new person to the specific stop
          //they are at to the busStops list and sets their direction to going west
          if (BusSim.busStops[busStop.getStopNumber()].goingWest.length() > busStop.getMaxWest())
              busStop.setMaxWest(BusSim.busStops[busStop.getStopNumber()].goingWest.length());
          //Sets new max west station the bus will need to go to if the new passenger is going farther
          //west than any of the previous passengers
      }
      PassengerEvent newEvent = new PassengerEvent(busStop);
      BusSim.agenda.add(newEvent, newPerson.getScheduleTime());
      //Adds the new passenger to the agenda.

  }
}
