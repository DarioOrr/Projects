//Written by Dario Orr and Osman Abdullahi

import java.util.Random;

public class Arrival {

    private double[] arrivalPercents = {.75, .75, .5, .5, .5, .2, .2, .2, .2, 0, 0, -.2,
            -.2, -.2, -.2, -.5, -.5, -.5, -.75, -.75};
    //What we did is instead of going all the way up to 29, we just counted stops in the middle as two.
    //Such as stop 3 is stop 3 and stop 27, but we counted 3 twice instead of using 27.
    int[] stopSelect = {0, 0, 1, 1, 1, 1, 14, 14, 15, 15, 14, 14,
            2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
            13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

    public int getArrivalTime() {
        Random random = new Random();
        int randomNum = random.nextInt(20);
        int time = (int) (BusSim.load + arrivalPercents[randomNum] * BusSim.load); //Equation from project outline.
        return time;
    }

    public int getArrivalStop(){
        Random rand = new Random();
        int randomNum = rand.nextInt(15); //Randomly selects which stop
        return stopSelect[randomNum];
    }


    public boolean direction(){
        Random random = new Random();
        return random.nextBoolean(); //Randomly determines which direction each passenger will go.
        //True is going east, false is going west.
    }



}
