//Dario Orr - orrxx166 - CSCI 1933 Fall 2019
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        boolean debugStatus = false; //Debug mode, set to true if you would like to enter debug mode
        int yourScore = 0;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the amount of columns you would like your board to have " +
                "(At least three, no more than twelve): \n");
        int columns = scan.nextInt();
        System.out.println("Enter the amount of rows you would like your board to have " +
                "(At least three, no more than twelve): \n");
        int rows = scan.nextInt();

        Board board = new Board(columns, rows, debugStatus);
        int boatsAfloat = board.boatsAfloat();
        System.out.println("Number of boats on board: " + boatsAfloat + "\n");

        while (boatsAfloat > 0) {
            System.out.println("Enter the row you would like to attack " +
                    "(Remember entering 0 is the first row): \n");
            rows = scan.nextInt();
            System.out.println("Enter the column you would like to attack " +
                    "(Remember entering 0 is the first column(: \n");
            columns = scan.nextInt();
            int result = board.input(rows, columns);
            System.out.println(board + "\n");
            yourScore = scoreUpdater(yourScore, result);
            boatsAfloat = board.boatsAfloat();
            System.out.println("Boats afloat: " + boatsAfloat + "\nYour score: " + yourScore);


        }
        System.out.println("Final score: " + yourScore);
    }
    private static int scoreUpdater(int yourScore, int result) {
        if (result == 0) {
            System.out.println("Penalty, your shot was out of bounds!");
            return yourScore + 2; //Out of bounds, higher penalty
        }
        else if (result == 1) {
            System.out.println("Your shot missed!");
            return 1 + yourScore;
        }
        else if (result == 2) {
            System.out.println("Hit!");
            return 0 + yourScore; //Lower score, the better
        }
        else {
            System.out.println("Penalty, you already shot at this location!");
            return 2 + yourScore; //Returns a higher score since they already shot there
        }
    }
}
