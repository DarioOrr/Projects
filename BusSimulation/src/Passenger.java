import java.util.Random;
public class Passenger{
  private double arrivalTime;

  private int scheduleTime;

  private double waitingTime;

  private int pickupStop;

  private int dropoffStop;

  private boolean direction;


  public Passenger(){
    Arrival passengerArrival = new Arrival();
    pickupStop = passengerArrival.getArrivalStop();    // all methods of arrival class
    scheduleTime = passengerArrival.getArrivalTime();   //randomly determine passenger variables
    direction = passengerArrival.direction();

    Random random = new Random();
    int randInt = random.nextInt(15);
    dropoffStop = randInt;
    if(dropoffStop == pickupStop){
      dropoffStop = random.nextInt(15);
    }
  }

  public void setArrivalTime(double time){
    arrivalTime = time;
  }

  public double getArrivalTime(){
    return arrivalTime;
  }

  public int getpickupStop(){
    return pickupStop;
  }

  public int getdropOffStop(){
    return dropoffStop;
  }

  public boolean getDirection(){
    return direction;
  }

  public double getWaitingTime(){
    return waitingTime;
  }

  public void setWaitingTime(double time){
    waitingTime = time;
  }

  public int getScheduleTime(){
    return scheduleTime;
  }

  public Passenger compareTo(Passenger p) {
    if (this==null){
      return p;
    }
    if (p==null){
      return this;
    }
    if (this.getWaitingTime() >= p.getWaitingTime()) {
      return this;
    }
    return p;
  }

  public String toString() {
    return ("arrival time: " + scheduleTime + " at stop: " + getpickupStop());
  }


}
