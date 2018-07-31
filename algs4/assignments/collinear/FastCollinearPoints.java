import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;

import java.util.Arrays;

public class FastCollinearPoints {

    private final int numberOfSegments;
    private final LineSegment[] segments;

    private class FastSlope implements Comparable<FastSlope> {
        private double slope;
        private int index;

        @Override
        public int compareTo(FastSlope o) {
            if (slope < o.slope) return -1;
            else if (slope > o.slope) return 1;
            else return 0;
        }
    }

    // finds all line segments containing 4 or more points
    public FastCollinearPoints(Point[] points) {
        // null array
        if (points == null) throw new IllegalArgumentException();

        // null element
        int size = points.length;
        for (int i = 0; i < size; i++)
            if (points[i] == null) throw new IllegalArgumentException();

        int[][] endPoints = new int[size][2];

        Point[] sortedPoints = points.clone();
        Arrays.sort(sortedPoints);

        // duplicate
        for (int i = 0; i < size - 1; i++) {
            if (sortedPoints[i].compareTo(sortedPoints[i+1]) == 0)
                throw new IllegalArgumentException();
        }

        double[][] slopes = new double[size][size];
        FastSlope[] fastSlopes = new FastSlope[size];
        for (int i = 0; i < size; i++) {
            fastSlopes[i] = new FastSlope();
        }

        boolean[][] saveFlag = new boolean[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                saveFlag[i][j] = true;
            }
        }

        int number = 0;
        for (int i = 0; i <= size - 4; i++) {

            for (int j = 0; j < size; j++) {
                fastSlopes[j].index = j;
                if (i <= j)
                    slopes[i][j] = slopes[j][i] = sortedPoints[i].slopeTo(sortedPoints[j]);
                fastSlopes[j].slope = slopes[i][j];
            }
            Arrays.sort(fastSlopes);

            int begin = 1, end = 2;
            for (int index = 1; index <= size - 3; index = end) {
                begin = index;
                double beginSlope = fastSlopes[begin].slope;
                for (end = begin + 1; end < size && beginSlope == fastSlopes[end].slope; end++) {
                }
                if (end - begin >= 3) {
                    int realBegin = begin, realEnd = end - 1;

                    if (fastSlopes[realBegin].index > fastSlopes[0].index) realBegin = 0;
                    if (fastSlopes[realEnd].index < fastSlopes[0].index) realEnd = 0;

                    int beginIndex = fastSlopes[realBegin].index;
                    int endIndex = fastSlopes[realEnd].index;

                    if (saveFlag[beginIndex][endIndex]) {
                        saveFlag[beginIndex][endIndex] = false;
                        endPoints[number][0] = beginIndex;
                        endPoints[number][1] = endIndex;

                        number++;
                        if (number == endPoints.length) {
                            int[][] newEndPoints = new int[endPoints.length * 2][2];
                            for (int k = 0; k < number; k++) {
                                newEndPoints[k][0] = endPoints[k][0];
                                newEndPoints[k][1] = endPoints[k][1];
                            }
                            endPoints = newEndPoints;
                        }
                    }
                }
            }
        }

        numberOfSegments = number;
        segments = new LineSegment[numberOfSegments];
        for (int i = 0; i < numberOfSegments; i++) {
            segments[i] = new LineSegment(sortedPoints[endPoints[i][0]], sortedPoints[endPoints[i][1]]);
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
        In in = new In("input400.txt");
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
        FastCollinearPoints collinear = new FastCollinearPoints(points);
        for (LineSegment segment : collinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        StdDraw.show();
    }
}