package SEM2.oops_lab.endsemfin;
import java.util.Scanner;

class Election{
    int[] voteCount;
    int spoiltCount;
    int choice;
    Election(){
        this.voteCount = new int[5];
        this.choice = 0;
        this.spoiltCount = 0;
    }
    void voteCandidate(Scanner sc){
        do{
            System.out.println("Enter the candidate number to vote for (1-5) [-1 to exit]: ");
            choice = sc.nextInt();
            if(choice<1 || choice>5){
                spoiltCount++;
            } else {
                voteCount[choice-1]++; 
                System.out.println("Voted for candidate "+choice);
            }
        } while(choice != -1);
    }
    void displayVote(){
        System.out.println("Can 1| Can 2| Can 3| Can 4| Can 5");
        for(int vote : voteCount){        
            System.out.print(vote+"    |");
        }
        System.out.println();
        System.out.println("Spoilt Count: "+spoiltCount);
    }
}

public class fin4 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Election e = new Election();
        e.voteCandidate(sc);
        e.displayVote();
        sc.close();
    }
}
