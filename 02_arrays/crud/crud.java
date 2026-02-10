public class Main {
    public static void main(String[] args) {

        // ================= INSERT AT INDEX 2 =================
        System.out.println("Insert at index 2:");
        int[] arr1 = new int[6];
        arr1[0] = 5;
        arr1[1] = 4;
        arr1[2] = 6;
        arr1[3] = 7;
        arr1[4] = 8;   // last slot empty

        for (int i = 5; i > 2; i--) {
            arr1[i] = arr1[i - 1];  // shift right
        }
        arr1[2] = 10;

        for (int i = 0; i < 6; i++)
            System.out.print(arr1[i] + " ");
        System.out.println("\n");


        // ================= INSERT AT GIVEN POSITION =================
        System.out.println("Insert at position 3:");
        int[] arr2 = new int[6];
        arr2[0] = 9;
        arr2[1] = 7;
        arr2[2] = 8;
        arr2[3] = 2;
        arr2[4] = 5;

        int posInsert = 3;
        int element = 10;

        for (int i = 5; i > posInsert; i--) {
            arr2[i] = arr2[i - 1];  // shift right
        }
        arr2[posInsert] = element;

        for (int i = 0; i < 6; i++)
            System.out.print(arr2[i] + " ");
        System.out.println("\n");


        // ================= DELETE AT POSITION =================
        System.out.println("Delete at position 2:");
        int n = 5;
        int[] arr3 = {3, 5, 6, 4, 8};
        int posDelete = 2;

        for (int i = posDelete; i < n - 1; i++) {
            arr3[i] = arr3[i + 1];  // shift left
        }
        n--;  // logical size reduced

        for (int i = 0; i < n; i++)
            System.out.print(arr3[i] + " ");
    }
}
