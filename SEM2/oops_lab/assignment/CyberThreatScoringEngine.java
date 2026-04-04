import java.util.*;

// Functional interface for threat scoring
interface ThreatScorer {
    int score(int baseThreat);
}

// Concrete class for LOW level
class LowScorer implements ThreatScorer {
    public int score(int baseThreat) {
        return baseThreat * 1;
    }
}

// Concrete class for MEDIUM level
class MediumScorer implements ThreatScorer {
    public int score(int baseThreat) {
        return baseThreat * 3;
    }
}

// Concrete class for HIGH level
class HighScorer implements ThreatScorer {
    public int score(int baseThreat) {
        return baseThreat * 7 + 50;
    }
}

public class CyberThreatScoringEngine {

    public static void main(String[] args) {

        // Map to store all scoring strategies
        Map<String, ThreatScorer> map = new HashMap<>();

        map.put("LOW", new LowScorer());
        map.put("MEDIUM", new MediumScorer());
        map.put("HIGH", new HighScorer());

        // Anonymous class for CRITICAL level
        map.put("CRITICAL", new ThreatScorer() {
            public int score(int baseThreat) {
                int result = baseThreat * 10 + 100;
                System.out.println("CRITICAL ALERT: score = " + result);
                return result;
            }
        });

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        /*  
            In Java, variables used inside anonymous classes must be final or effectively final.
            Since we need to modify total inside the loop, we use an array as a workaround.
            Arrays are mutable, so total[0] can be updated.
        */
        int[] total = {0};

        for (int i = 0; i < n; i++) {

            String level = sc.next();
            int base = sc.nextInt();

            ThreatScorer scorer = map.get(level);

            if (scorer == null) {
                System.out.println(level + ": Unknown threat level. Skipped.");
                continue;
            }

            total[0] += scorer.score(base);
        }

        System.out.println("Total Threat Score: " + total[0]);

        sc.close();
    }
}