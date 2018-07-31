import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

public class BruteCollinearPoints {

    private final int numberOfSegments;
    private final LineSegment[] segments;

    // finds all line segments containing 4 points
    public BruteCollinearPoints(Point[] points) {

        if (points == null) throw new IllegalArgumentException();
        for (int i = 0; i < points.length; i++)
            if (points[i] == null) throw new IllegalArgumentException();
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                if (points[i].compareTo(points[j]) == 0) throw new IllegalArgumentException();
            }
        }

        int size = points.length;
        int[][] endPointIndex = new int[size][2];
        int number = 0;

        for (int w = 0; w < size - 3; w++) {
            for (int x = w + 1; x < size - 2; x++) {
                double WX = points[w].slopeTo(points[x]);

                for (int y = x + 1; y < size - 1; y++) {
                    double WY = points[w].slopeTo(points[y]);
                    if (WX != WY) continue;

                    for (int z = y + 1; z < size; z++) {
                        double WZ = points[w].slopeTo(points[z]);
                        if (WX != WZ) continue;

                        int min = w, max = w;
                        if (points[min].compareTo(points[x]) > 0) min = x;
                        else if (points[max].compareTo(points[x]) < 0) max = x;
                        if (points[min].compareTo(points[y]) > 0) min = y;
                        else if (points[max].compareTo(points[y]) < 0) max = y;
                        if (points[min].compareTo(points[z]) > 0) min = z;
                        else if (points[max].compareTo(points[z]) < 0) max = z;

                        endPointIndex[number][0] = min;
                        endPointIndex[number][1] = max;
                        number++;
                    }
                }
            }
        }
        numberOfSegments = number;
        segments = new LineSegment[numberOfSegments];
        for (int i = 0; i < numberOfSegments; i++) {
            segments[i] = new LineSegment(points[endPointIndex[i][0]], points[endPointIndex[i][1]]);
        }
    }

    // the number of line segments
    public int numberOfSegments() {
        return numberOfSegments;
    }

    // the line segments
    public LineSegment[] segments() {
        return segments.clone();
    }

    public static void main(String[] args) {
        // read the n points from a file
//        In in = new In(args[0]);
        In in = new In("equidistant.txt");
        int n = in.readInt();
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            points[i] = new Point(x, y);
        }

        // draw the points
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        for (Point p : points) {
            p.draw();
        }
        StdDraw.show();

        // print and draw the line segments
        BruteCollinearPoints collinear = new BruteCollinearPoints(points);
        for (LineSegment segment : collinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        StdDraw.show();
    }
}