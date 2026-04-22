class Notification{
    int notificationId;
    String userName, message;
    Notification(int id, String n, String m){
        this.notificationId = id;
        this.userName = n;
        this.message = m;
    }
    void display(){
        System.out.println(buildMessage());
    }
    String buildMessage(){
        StringBuffer sb = new StringBuffer();
        sb.append("Notification ID: "+notificationId+"\n");
        sb.append("User: "+userName+"\n");
        sb.append("Message: "+message);
        return sb.toString();
    }
}
class PriorityNotification extends Notification{
    String priorityLevel;
    int retryCount;
    PriorityNotification(int id, String n, String m, String pl, int rc){
        super(id,n,m);
        this.priorityLevel = pl;
        this.retryCount = rc;
    }
    @Override
    void display(){
        System.out.println(buildMessage());
    }
    @Override
    String buildMessage(){
        StringBuffer sb = new StringBuffer();
        sb.append("Notification ID: "+notificationId+"\n");
        sb.append("User: "+userName+"\n");
        sb.append("Message: "+message+"\n");
        sb.append("Priority: "+priorityLevel+"\n");
        sb.append("Retry Attempts: "+retryCount);
        return sb.toString();
    }
}
public class smartNotif {
    public static void main(String[] args){
        Notification n = new Notification(101, "Bobi", "Package delivered!");
        n.buildMessage();
        n.display();
        PriorityNotification pn = new PriorityNotification(102, "Ron", "Package delayed for some time.", "HIGH", 3);
        pn.buildMessage();
        pn.display();
    }
}
