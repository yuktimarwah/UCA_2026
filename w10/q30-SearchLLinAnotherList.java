class Solution {

	public static boolean find(Node head1, Node head2) {
		
		Node start = head2;
		
		while (start != null) {
			
			Node curr1 = head1;
			Node curr2 = start;
			
			while (curr1 != null && curr2 != null && curr1.data == curr2.data) {
				
				curr1 = curr1.next;
				curr2 = curr2.next;

			}

			if (curr1 == null) {

				return true;

			}

			start = start.next;

		}

		return false;

	}

}
       	
