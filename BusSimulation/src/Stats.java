//Written by Dario Orr and Osman Abdullahi

public class Stats{

  public void getNumPass(){
    for (int i=0; i<BusSim.buses.length; i++){
      System.out.println("Bus " + (i+1) + " has " + BusSim.buses[i].numPassengers + " passengers on board");
    }
  }

  //Maximum time a passeneger spent waiting for a bus/
  public double getLongestWait(){
    Passenger longestWait = BusSim.buses[0].pplInBus[0]; //Setting longest wait to the first passenger and iteratively comparing
    BusStop stop = BusSim.busStops[0];
    for (int i=0; i<BusSim.buses.length; i++) {        //for all of the busses
      for (int j = 0; j < BusSim.buses[i].pplInBus.length; j++) {  //for every passenger on the bus
        if (BusSim.buses[i].pplInBus[j] != null) {
          if (longestWait.compareTo(BusSim.buses[i].pplInBus[j]) == BusSim.buses[i].pplInBus[j]) {
            longestWait = BusSim.buses[i].pplInBus[j];
          }
        }
      }
    }
    System.out.println("The max wait time for a passenger is " + longestWait.getWaitingTime() + " at stop " + longestWait.getpickupStop());
    return longestWait.getWaitingTime();
  }

  public int longestQ(){
    Q longestQ = BusSim.busStops[0].goingEast; //Sets initial comparison to the bus at stop 0 going east.
    BusStop stop = BusSim.busStops[0];
    for (int i=0; i<BusSim.busStops.length; i++){
      Q maxAtStop = BusSim.busStops[i].goingEast.compareTo(BusSim.busStops[i].goingWest);
      if (maxAtStop.compareTo(longestQ)==maxAtStop){
        longestQ = maxAtStop;
        stop = BusSim.busStops[i];
      }
    }
    System.out.println("The stop with longest queue length with " + longestQ.length() + " is stop " + stop);
    return longestQ.length();
  }
}
