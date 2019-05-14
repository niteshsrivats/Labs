package basicprograms;

import java.util.Arrays;
import java.util.Scanner;

public class Matrix {

    private static Scanner s = new Scanner(System.in);

    private static int[][] multiply(int[][] matrixA, int[][] matrixB) {

        int[][] matrix = new int[matrixA.length][matrixA.length];
        for (int k = 0; k < matrix.length; k++)
            for (int j = 0; j < matrix.length; j++)
                for (int i = 0; i < matrix.length; i++)
                    matrix[i][j] += matrixA[i][k] * matrixB[k][j];
        return matrix;
    }

    private static int[][] add(int[][] matrixA, int[][] matrixB) {

        int[][] matrix = new int[matrixA.length][matrixA.length];
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix.length; j++)
                matrix[i][j] = matrixA[i][j] + matrixB[i][j];
        return matrix;
    }

    private static int[][] getSquareMatrix(int size) {

        int[][] matrix = new int[size][size];
        for (int i = 0; i < size; i++) {
            System.out.print("Enter Row " + (i + 1) + ": ");
            for (int j = 0; j < size; j++)
                matrix[i][j] = s.nextInt();
        }
        return matrix;
    }

    private static void displayMatrix(int[][] matrix) {

        for (int i = 0; i < matrix.length; i++)
            System.out.println(Arrays.toString(matrix[i]));
    }

    public static void main(String[] args) {
        System.out.println("Enter Matrix Size: ");
        int size = s.nextInt();
        System.out.println("Enter Matrix A: ");
        int[][] matrixA = getSquareMatrix(size);
        System.out.println("Enter Matrix B: ");
        int[][] matrixB = getSquareMatrix(size);

        int[][] sumMatrix = add(matrixA, matrixB);
        System.out.println("Sum Matrix:");
        displayMatrix(sumMatrix);

        int[][] productMatrix = multiply(matrixA, matrixB);
        System.out.println("Product Matrix:");
        displayMatrix(productMatrix);
    }
}
