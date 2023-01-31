package week6.course_planning;

import java.util.Scanner;
import java.util.ArrayList;

// Type your code here, or load an example.
class srce {

    static ArrayList<ArrayList<Integer>> deps;
    static int[] depth;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // cor
        int m = sc.nextInt(); // dep

        deps = new ArrayList<ArrayList<Integer>>();
        depth = new int[n + 1];
        deps.add(null);

        for (int i = 1; i <= n; i++) {
            deps.add(new ArrayList<Integer>());
            depth[i] = -1;
        }

        for (int i = 0; i < m; i++) {
            int c = sc.nextInt(); // cor
            int d = sc.nextInt(); // dep

          deps.get(c).add(d);
        }

        int max_depth = 0;

        for (int i = 1; i <= n; i++) {
            if (getDepth(i) > max_depth) max_depth = depth[i];
        }

        System.out.println(max_depth);
    }

    public static int getDepth(int index) {
        if (depth[index] == -1) {
            int max = 0;
            for (int dep : deps.get(index)) {
                int d = getDepth(dep);
                if (d > max) max = d;
            }
            depth[index] = max + 1;
        }
        return depth[index];
    }

}