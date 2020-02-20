//Dario Orr - orrxx166 - CSCI 1933 Fall 2019
public class Cell {
    private int row;
    private int col;
    private char status;

    public char getStatus() {
        return status; //Is the space occupied?
    }

    public void setStatus(char c) {
        status = c;
    }

    public Cell(int row, int col, char status) {
        this.row = row;
        this.col = col;
        this.status = status;
    }
}
