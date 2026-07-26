import java.util.*;

public class Main {

    static long inversionCount(int[] arr) {
        return mergeSort(arr, 0, arr.length - 1);
    }

    static long mergeSort(int[] arr, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        long count = mergeSort(arr, left, mid)
                   + mergeSort(arr, mid + 1, right);

        count += merge(arr, left, mid, right);

        return count;
    }

    static long merge(int[] arr, int left, int mid, int right) {
        int[] temp = new int[right - left + 1];

        int i = left;
        int j = mid + 1;
        int k = 0;
        long count = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // All remaining elements in left half are greater
                count += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = 0; i < temp.length; i++)
            arr[left + i] = temp[i];

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();
        while (sc.hasNextInt()) {
            list.add(sc.nextInt());
        }

        int[] arr = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }

        System.out.println(inversionCount(arr));
    }
}
