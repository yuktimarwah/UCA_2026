import java.util.Scanner;

public class q19_optimizedMatrixZeroes {
	
	public static void MatrixZeroes (int[][] matrix) {
		boolean row0Zero = false;
		boolean col0Zero = false;

		int rows = matrix.length;
		int cols = matrix[0].length;

		for (int j = 0; j < cols; j++){
			if (matrix[0][j] == 0) {
				row0Zero = true;
			}
		}

		for (int i = 0; i < rows; i++) {
			if (matrix[i][0] == 0){
				col0Zero = true;
			}
		}

		for (int i = 1; i < rows; i++) {
			for (int j = 1; j < cols; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
			}
		}
		}

		for (int i = 1; i < rows; i++){
			for (int j = 1; j < cols; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		if (row0Zero) {
			for (int j = 0; j < cols; j++) {
				matrix[0][j] = 0;
			}
		}

		if(col0Zero) {
			for (int i = 0; i < rows; i++) {
				matrix[i][0] = 0;
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

    MatrixZeroes(matrix);

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



