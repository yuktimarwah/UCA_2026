class Selectionsort{
	public static void selection(int [] arr){
		int n = arr.length;
		for(int i=0;i<n-1;i++){
			int min = i;
			for(int j=i+1;j<n;j++){
				if(arr[j]<arr[min]){
					min = j;
				}
			}
			if(min!=i){
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}
	public static void main(String[] args){
		int[] arr = {3,6,1,4,9,11,5,0};
		selection(arr);
		for(int x:arr){
			System.out.print(x + " " );
		}
	}
}
