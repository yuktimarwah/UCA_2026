import java.util.*;

public class Main {

    static class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    static int[] count;

    static List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        count = new int[n];

        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        mergeSort(arr, 0, n - 1);

        List<Integer> ans = new ArrayList<>();
        for (int x : count)
            ans.add(x);

        return ans;
    }

    static void mergeSort(Pair[] arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    static void merge(Pair[] arr, int left, int mid, int right) {
        Pair[] temp = new Pair[right - left + 1];

        int i = left;
        int j = mid + 1;
        int k = 0;
        int rightCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i].value <= arr[j].value) {
                count[arr[i].index] += rightCount;
                temp[k++] = arr[i++];
            } else {
                rightCount++;
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = 0; i < temp.length; i++) {
            arr[left + i] = temp[i];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();
        while (sc.hasNextInt()) {
            list.add(sc.nextInt());
        }

        int[] nums = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            nums[i] = list.get(i);
        }

        List<Integer> ans = countSmaller(nums);

        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i));
            if (i != ans.size() - 1)
                System.out.print(" ");
        }
    }
}
