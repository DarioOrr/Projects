//Dario Orr - orrxx166 - CSCI 1933 Fall 2019
public class Board {
    private int num_cols;
    private int num_rows;
    private int num_boats;
    private boolean debugStatus;
    private Orientation boats[]; //Creates orientation object
    private Cell board[][]; //Create cell object
    private Cell[] temp; //Temporary cell object

    public Board(int m, int n, boolean debugStatus) {
        this.num_rows = m;
        this.num_cols = n;
        this.debugStatus = debugStatus;


        if (m == 3 || n == 3) { //Determines amount of boats on board based on board dimensions
            num_boats = 1;
        }
        else if (m > 3 && m <= 5 || n > 3 && n <= 5) {
            num_boats = 2;
        }
        else if (m > 5 && m <= 7 || n > 5 && n <= 7) {
            num_boats = 3;
        }
        else if (m > 7 && m <= 9 || n > 7 && n <= 9) {
            num_boats = 4;
        }
        else if (m > 9 && m <= 12 || n > 9 && n <= 12) {
            num_boats = 6;
        }
        boats = new Orientation[num_boats];
        board = new Cell[m][n]; //Creates cell objects based on the input dimensions

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                Cell cellObj = new Cell(i, j,' ');
                board[i][j] = cellObj;
            }
        }

        int z = 0;

        while (z < num_boats) {
            Orientation new_boat = new Orientation();
            double r1 = (m) * Math.random(); // Generates random positions in the array to place boats
            double r2 = (n) * Math.random();
            int x = (int) (Math.floor(r1));
            int y = (int) (Math.floor(r2)); //Removes decimal
            int spaceSeparate = 0; //Insures boats don't overlap
            if (new_boat.getOrientation() == true) {    //Horizontal Boat
                for (int b = 0; b < 3; b++) {
                    if (x + 2 < m) {
                        if (board[x + b][y].getStatus() == ' ') {
                            spaceSeparate++;
                        }
                    }
                }
                if (spaceSeparate == 3) {

                    for (int b = 0; b < 3; b++) {
                        board[x + b][y].setStatus('B');
                        new_boat.setSpaces(b, board[x + b][y]);
                        boats[z] = new_boat; //Adds objects to array
                    }
                    z++;
                }
            }
            else if (new_boat.getOrientation() == false) {   //Vertical boat
                for (int b = 0; b < 3; b++) { //Creates boat length
                    if (y + 2 < n) {
                        if (board[x][y + b].getStatus() == ' ') {
                            spaceSeparate++;
                        }
                    }
                }
                if (spaceSeparate == 3) {
                    for (int b = 0; b < 3; b++) {
                        board[x][y + b].setStatus('B');
                        new_boat.setSpaces(b, board[x][y + b]);
                        boats[z] = new_boat;
                    }
                    z++;
                }

            }
        }
    }

    private char debug(boolean debugMode, char o){ //For debug mode
        if(debugMode == true){
            return o;
        }
        else{
            switch(o){
                case 'H':
                    o = 'x';
                    break;
                case 'M':
                    o = 'o';
                    break;
                default:
                    o = '~';
                    break;
            }
            return o;
        }
    }


    public String toString(){

        String boardString = "\t"; //Tabs to center number positions of board
        for (int j = 0; j < num_cols-1; j++){
            boardString += j + " -" + "\t";
        }

        boardString += num_cols-1;

        for(int i = 0; i < num_rows; i++){
            boardString+= "\n" + i + "\t";
            for (int j = 0; j < num_cols; j++){
                boardString += debug(debugStatus, board[i][j].getStatus()) + "\t";
            }
        }

        boardString += "\n";
        return boardString;
    }

    //Takes a user's guess and returns result. Changes status to appropritate value if applicable.
    public int input(int row, int col){
        if ((row < 0 || row >= this.num_rows) || (col < 0 ||col >= this.num_cols)){
            return 0;
            //"Penalty: Out of Bounds";
        }
        else if (board[row][col].getStatus()== ' ') {
            board[row][col].setStatus('M'); //Miss statement
            return 1;
        }
        else if(board[row][col].getStatus()== 'B'){
            board[row][col].setStatus('H'); //Hit statement
            return 2;
            //"Hit";
        }
        else {
            return 3;
            //
        }
    }



    public int boatsAfloat(){
        int afloat_count = 0;

        for (int start=0; start < num_boats; start++) {
            int cellCheck = 0;
            temp = boats[start].getSpaces();
            for (int check = 0; check < 3; check++) {
                if (temp[check].getStatus() =='B') {
                    cellCheck++;
                }

            }
            if (cellCheck >= 1){
                afloat_count++;}
        }
        return afloat_count; //Returns number of boats remaining

    }


}




