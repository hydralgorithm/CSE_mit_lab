import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

interface ThreatScorer {
    int score(int baseThreat);
}

class LowScorer implements ThreatScorer {
    public int score(int baseThreat) {
        return baseThreat * 1;
    }
}

class MediumScorer implements ThreatScorer {
    public int score(int baseThreat) {
        return baseThreat * 3;
    }
}

class HighScorer implements ThreatScorer {
    public int score(int baseThreat) {
        return baseThreat * 7 + 50;
    }
}

public class CyberThreatScoringEngine {

    public static void main(String[] args) {

        Map<String, ThreatScorer> scoringMap = new HashMap<String, ThreatScorer>();

        scoringMap.put("LOW",    new LowScorer());
        scoringMap.put("MEDIUM", new MediumScorer());
        scoringMap.put("HIGH",   new HighScorer());

        scoringMap.put("CRITICAL", new ThreatScorer() {
            public int score(int baseThreat) {
                int result = baseThreat * 10 + 100;
                System.out.println("CRITICAL ALERT: score = " + result);
                return result;
            }
        });

        Scanner sc = new Scanner(System.in);

        System.out.println("--- Cyber Threat Scoring Engine ---");
        System.out.print("Enter number of threats: ");
        int n = sc.nextInt();

        int[] total = {0};

        for (int i = 0; i < n; i++) {
            System.out.print("Enter threat level and base value (e.g. HIGH 10): ");
            String level     = sc.next();
            int    baseValue = sc.nextInt();

            ThreatScorer scorer = scoringMap.get(level);

            if (scorer == null) {
                System.out.println(level + ": Unknown threat level. Skipped.");
                continue;
            }

            total[0] += scorer.score(baseValue);
        }

        sc.close();

        System.out.println("Total Threat Score: " + total[0]);
    }
}