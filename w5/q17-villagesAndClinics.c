#include <stdio.h>
#include <math.h>

double villagesAndClinics (int n, int population[], int k) {
	double low = 0;
	double high = population[0];

	for (int i = 0; i < n; i++) {
		if (population[i] > high) {
			high = population[i];
		}
	}

	for (int i = 0; i < 100; i++) {
		double mid = (low + high) / 2.0;
		
		int totalClinics = 0;

		for (int j = 0; j < n; j++) {
			int clinicsNeeded = ceil(population[j]/mid);
			totalClinics += clinicsNeeded;
		}

		if (totalClinics <= k) {
			high = mid;
		}
		else {
			low = mid;
		}
	}
	return (low+high) / 2.0;
}

int main() {
       	int n, k;
       	printf("Enter number of villages: ");
       	scanf("%d", &n);
       	int population[n];
       	printf("Enter population of each village:\n");
       	for (int i = 0; i < n; i++) {
	       	scanf("%d", &population[i]);
       	}
       	printf("Enter number of clinics: ");
       	scanf("%d", &k);
       	double answer = villagesAndClinics(n, population, k);
       	printf("Minimum maximum population per clinic = %.2f\n", answer); return 0;
}
