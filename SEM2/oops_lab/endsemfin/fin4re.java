package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

class Candidate{
    int candidateNum;
    int voteCount;
    Candidate(int candidateNum){
        this.candidateNum = candidateNum;
        this.voteCount = 0;
    }
}
class Election{
    Candidate[] candidates;
    int spoiltCount;
    Election(){
        this.candidates = new Candidate[5];
        this.spoiltCount = 0;
        for(int i=0; i<5; i++){
            this.candidates[i] = new Candidate(i+1);
        }
    }
    void readVote(Scanner sc){
        System.out.print("Enter num of votes: ");
        int n = sc.nextInt();
        for(int i=0; i<n; i++){
            System.out.print("Enter vote: ");
            int vote = sc.nextInt();
            count(vote);
        }
        System.out.println();
    }
    void count(int vote){
        if(vote<1 || vote>5){
            spoiltCount++;
        } else{
            candidates[vote-1].voteCount++;
        }
    }
    void display(){
        for(Candidate c: candidates){
            System.out.println("Candidate num: "+c.candidateNum+" | Candidate Votes: "+c.voteCount);
        }
        System.out.println("Spoilt Count: "+spoiltCount);
    }
    
}
public class fin4re {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Election e = new Election();
        e.readVote(sc);
        e.display();
        sc.close();
    }
}
