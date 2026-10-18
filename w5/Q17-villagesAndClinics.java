class Solution {

	public static boolean isPossible(int n, int[] populations, int k, double mid) {

		int clinicNeeded = 0;

		for (int i = 0; i < n; i++) {

			clinicNeeded += (int) Math.ceil(populations[i] / mid);

		}

		if (clinicNeeded > k) {

			return false;

		}
		else {
			
			return true;

		}

	}

	public static double villagesAndClinics(int n, int[] populations, int k) {

		int highestPop = 0;

		for (int i = 0; i < n; i++) {

			if (populations[i] > highestPop) {

				highestPop = populations[i];

			}

		}

		int low = highestPop / k;
		int high = highestPop;

		double ans = highestPop;

		while (high - low > 0.00001) {

			double mid = low + (high - low) / 2;

			if (isPossible(n,populations,k,mid)) {

				ans = mid;
				high = mid;

			}
			else {
				
				low = mid;

			}

		}

		return ans;

	}

}



