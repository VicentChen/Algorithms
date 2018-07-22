import edu.princeton.cs.algs4.WeightedQuickUnionUF;

/**
 * Created by Vicent_Chen on 2018/7/21.
 */
public class Percolation {
    private final int n;
    private boolean[][] sites;
    private boolean[] help;
    private int openSites;
    private final WeightedQuickUnionUF wuf;
    private final int fakeTop;

    // create n-by-n grid, with all sites blocked
    public Percolation(int n) {
        if (n <= 0) throw new IllegalArgumentException();

        this.n = n;
        this.sites = new boolean[n][n];
        this.help = new boolean[n * n + 1];
        this.openSites = 0;
        this.wuf = new WeightedQuickUnionUF(n * n + 1);
        this.fakeTop = n * n;

        // initialize
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                sites[x][y] = false;
                help[x * n + y] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            help[n * (n - 1) + i] = true;
        }
    }

    // open site (row, col) if it is not open already
    public void open(int row, int col) {
        if (row < 1 || row > n) throw new IllegalArgumentException();
        if (col < 1 || col > n) throw new IllegalArgumentException();

        int x = row - 1;
        int y = col - 1;
        int currLoc = flatten(row, col);

        // open site
        if (this.sites[x][y]) return;
        this.sites[x][y] = true;
        this.openSites++;

        boolean helpFlag = false;
        if (help[wuf.find(currLoc)]) helpFlag = true;
        if (y > 0 && sites[x][y - 1]) { // left
            if (!helpFlag && help[wuf.find(currLoc - 1)]) helpFlag = true;
            wuf.union(currLoc - 1, currLoc);
        }
        if (y < n - 1 && sites[x][y + 1]) { // right
            if (!helpFlag && help[wuf.find(currLoc + 1)]) helpFlag = true;
            wuf.union(currLoc + 1, currLoc);
        }
        if (x > 0 && sites[x - 1][y]) { // up
            if (!helpFlag && help[wuf.find(currLoc - n)]) helpFlag = true;
            wuf.union(currLoc - n, currLoc);
        } else if (x == 0) { // connect fake top
            wuf.union(this.fakeTop, currLoc);
        }
        if (x < n - 1 && sites[x + 1][y]) { // down
            if (!helpFlag && help[wuf.find(currLoc + n)]) helpFlag = true;
            wuf.union(currLoc + n, currLoc);
        }
        if (helpFlag) help[wuf.find(currLoc)] = true;
    }

    // is site (row, col) open?
    public boolean isOpen(int row, int col) {
        if (row < 1 || row > n) throw new IllegalArgumentException();
        if (col < 1 || col > n) throw new IllegalArgumentException();

        return sites[row - 1][col - 1];
    }

    // is site (row, col) full?
    public boolean isFull(int row, int col) {
        if (row < 1 || row > n) throw new IllegalArgumentException();
        if (col < 1 || col > n) throw new IllegalArgumentException();

        return wuf.connected(this.fakeTop, flatten(row, col));
    }

    // number of open sites
    public int numberOfOpenSites() {
        return this.openSites;
    }

    // does the system percolate?
    public boolean percolates() {
        return help[wuf.find(this.fakeTop)];
    }

    private int flatten(int row, int col) {
        return (row - 1) * n + col - 1;
    }

    // test client (optional)
    public static void main(String[] args) {
        // empty main
    }
}
