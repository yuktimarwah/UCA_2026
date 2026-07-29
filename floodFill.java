class Solution {
    class pair {
        int row;
        int col;

        pair (int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if (original == color) {
            return image;
        }
        image[sr][sc] = color;
        Queue<pair> q = new LinkedList<>();
        q.add(new pair(sr,sc));
        while (!q.isEmpty()) {
            pair curr = q.poll();
            int r = curr.row;
            int c = curr.col;

            int unewr = r-1;
            int unewc = c;
            if (0 <= unewr && unewr < image.length && 0 <= unewc && unewc < image[0].length) {
                if (image[unewr][unewc]==original) {
                    image[unewr][unewc] = color;
                    q.add(new pair(unewr,unewc));
                }
            }

            int dnewr = r+1;
            int dnewc = c;
            if (0 <= dnewr && dnewr < image.length && 0 <= dnewc && dnewc < image[0].length) {
                if (image[dnewr][dnewc]==original) {
                    image[dnewr][dnewc] = color;
                    q.add(new pair(dnewr,dnewc));
                }
            }

            int rnewr = r;
            int rnewc = c-1;
            if (0 <= rnewr && rnewr < image.length && 0 <= rnewc && rnewc < image[0].length) {
                if (image[rnewr][rnewc]==original) {
                    image[rnewr][rnewc] = color;
                    q.add(new pair(rnewr,rnewc));
                }
            }

            int lnewr = r;
            int lnewc = c+1;
            if (0 <= lnewr && lnewr < image.length && 0 <= lnewc && lnewc < image[0].length) {
                if (image[lnewr][lnewc]==original) {
                    image[lnewr][lnewc] = color;
                    q.add(new pair(lnewr,lnewc));
                }
            }
        } 
        return image;   
    }
}
