class Solution {

	public static int Find(int n, int[] arr) {

		int res = 0;

		for (int i = 0; i < 32; i++) {

			int count = 0;

			for (int num : arr) {

				if (((num >> i) & 1) != 0) {

					count++;

				}

			}

			if (count % 3 == 1) {

				res |= (1 << i);

			}

		}

		return res;

	}

}
