//Dario Orr - orrxx166 - CSCI 1933 Fall 2019
public class Orientation {
    private int size = 3;
    private boolean orientation;
    // if true, horizontal, if false, vertical
    private Cell[] spaces = new Cell[3];

    public Orientation() {
        double random = Math.random();
        if (random >=0.5) { //Determines if boat will be vertical or horizontal
            orientation = true;
        }
        else {
            orientation = false;
        }
    }

    public boolean getOrientation() {
        return orientation;
    }

    public int getSize() {
        return size;
    }

    public Cell[] getSpaces() {
        return spaces;
    }

    public void setSpaces(int s, Cell X) {
        spaces[s] = X;
    }
} //Close Orientation class
