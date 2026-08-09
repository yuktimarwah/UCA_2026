import java.util.Scanner;

public class q19_MatrixZeroes {


public static void matrixZeroes (int[][] matrix) {
	int rows = matrix.length;
	int col = matrix[0].length;

	boolean []rowZeroes = new boolean[rows];
	boolean []colZeroes = new boolean[col];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 0) {
	                    rowZeroes[i] = true;
                            colZeroes[j] = true;
			}
		}
	}

	for (int i = 0; i < rows; i++) {
                for (int j = 0; j < col; j++) {
			if (rowZeroes[i] == true || colZeroes[j] == true) {
				matrix[i][j] = 0;
			}
		}
	}
}



public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows: ");
        int rows = sc.nextInt();

        System.out.print("Enter number of columns: ");
        int cols = sc.nextInt();

        int[][] matrix = new int[rows][cols];

        System.out.println("Enter matrix elements:");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        matrixZeroes(matrix);

        System.out.println("Matrix after setting zeroes:");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
