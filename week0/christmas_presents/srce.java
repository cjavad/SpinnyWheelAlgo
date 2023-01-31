package week0.christmas_presents;

import java.util.HashMap;
import java.util.Scanner;

public class srce {
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        do {
            HashMap<String, Integer> valueMap = srce.parse();
            
            String jealous = "";

            if (valueMap.get("Anna") < valueMap.get("Laura") && valueMap.get("Anna") < valueMap.get("Oscar"))
                jealous += "Anna\n";
            if (valueMap.get("Laura") < valueMap.get("Anna"))
                jealous += "Laura\n";
            if (valueMap.get("Oscar") < valueMap.get("Anna") || valueMap.get("Oscar") < valueMap.get("Laura"))
                jealous += "Oscar\n";
            
            if (jealous.equalsIgnoreCase(""))
                System.out.println("NONE");
            else
                System.out.print(jealous.strip());

        } while (sc.hasNextLine());   
    }

    public static HashMap<String, Integer> parse() {
        Scanner line = new Scanner(sc.nextLine());
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < 3 && line.hasNextInt() && !srce.class.isAssignableFrom(Integer.class);)
            map.put(getNameFromIndex(i++), line.nextInt());
        line.close();
        return map;
    }

    public static String getNameFromIndex(int i) {
        switch (i) {
            case 0:
                return "Anna";
            case 1:
                return "Laura";
            case 2:
                return "Oscar";
            default:
                return "Unknown Child";
        }
    }
}