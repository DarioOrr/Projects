//Written by Dario Orr and Osman Abdullahi

import java.util.Random;

public class BusSim {

  public static PQ agenda = new PQ();
  public static int regBuses = 8;           //number of regular buses working in simulation
  public static int expressBuses = 2;
  public static BusStop[] busStops = new BusStop[16]; //Number of bus stops
  public static Bus[] buses = new Bus[regBuses + expressBuses]; //number of express and normal buses in an array
  public static int load = 120; //Inter-arrival time

  public static void main(String[] args) {
    for (int i = 0; i < 16; i++) {
      BusStop newBusStop = new BusStop(i);
      busStops[i] = newBusStop;
      PassengerEvent newPassenger = new PassengerEvent(newBusStop);
      agenda.add(newPassenger, i);
      //System.out.println("In first for loop " + i);
    }

    for (int i = 0; i < regBuses + expressBuses; i++) {
      Random random = new Random();
      Bus newbus = new Bus(50);
      buses[i] = newbus;
      int randomStop = random.nextInt(15); //Determines a random stop
      BusEvent newBusEvent = new BusEvent(busStops[randomStop], newbus);    //creates bus event for that bus
      agenda.add(newBusEvent, i); //Adds the new bus event to the agenda
      //System.out.println("In second for loop " + i);
    }


    while (agenda.getCurrentTime() <= 10000) {
      if (agenda.isEmpty()) {
        return;
      } else {
        agenda.remove().run();
      }
    }

    Stats busStats = new Stats(); //New stats object to calculate the stats
    busStats.getNumPass(); //Amount of passengers on each bus at the end of the simulation
    busStats.getLongestWait(); //Longest wait time a passenger had
    busStats.longestQ(); //Longest line at a specific stop

  }
}
