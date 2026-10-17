class Solution {

	public static Node findIntersection(Node head1, Node head2) {

		Node curr1 = head1;

		Node curr2 = head2;

		Node dummy = new Node(0);

		Node res = dummy;

		while (curr1 != null && curr2 != null) {

			if (curr1.data == curr2.data) {
				
				Node newNode = new Node(curr1.data);

				res.next = newNode;

				res = res.next;

				curr1 = curr1.next;
				curr2 = curr2.next;
			}

			else if (curr1.data < curr2.data) {

				curr1 = curr1.next;

			}

			else {
				
				curr2 = curr2.next;

			}

		}

		return dummy.next;
	}

}

