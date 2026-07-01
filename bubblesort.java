public class bubblesort{
	static void bubblesort(int[] a){
		int n = a.length;

		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
	}
	public static void main(String[] args){
		int[] a = {7,6,4,8,2,1};
		bubblesort(a);
		for(int x:a){
			System.out.print(x+" ");
		}
		}
}
