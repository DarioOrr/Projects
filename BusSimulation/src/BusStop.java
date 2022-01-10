//Written by Dario Orr and Osman Abdullahi

public class BusStop {

    private int stopNumber;
    public Q goingEast;
    public Q goingWest;
    private int maxEast;
    private int maxWest;

    public BusStop(int stopNumber) {
        this.stopNumber = stopNumber;
        goingEast = new Q();
        goingWest = new Q();
    }

    public int getMaxEast() { //The most east stop a passenger has that is currently riding a bus
        return maxEast;
    }

    public int getMaxWest() {   //The most west stop a passenger has that is currently riding a bus
        return maxWest;
    }

    public void setMaxEast(int maxEast) {
        this.maxEast = maxEast;
    }

    public void setMaxWest(int maxWest) {
        this.maxWest = maxWest;
    }

    public int getStopNumber() {
        return stopNumber;
    }

    public String toString(){
        return (this.getStopNumber() + " " + this.getStopName());
    }

    //All stops that are apart of this project, used a switch method for simplicity rather than 15 if statements.
    public String getStopName() {
        String stopName = "";
        switch (stopNumber){
            case 0: stopName = "Ramp B";
                break;
            case 1: stopName = "4th and Nicollet";
                break;
            case 2: stopName = "Anderson Hall";
                break;
            case 3: stopName = "Jones Hall";
                break;
            case 4: stopName = "Kasota Circle";
                break;
            case 5: stopName = "Como & Eustis";
                break;
            case 6: stopName = "Como & Cleveland";
                break;
            case 7: stopName = "Como & Snelling";
                break;
            case 8: stopName = "Como and Hamline";
                break;
            case 9: stopName = "Maryland and Dale";
                break;
            case 10: stopName = "Maryland and Rice";
                break;
            case 11: stopName = "Front and Lexington";
                break;
            case 12: stopName = "Front and Dale";
                break;
            case 13: stopName = "Capitol";
                break;
            case 14: stopName = "Cedar";
                break;
            case 15: stopName = "Union Depot";
                break;
        }
        return stopName;
    }
}
