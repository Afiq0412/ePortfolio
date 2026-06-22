// ExecutiveRoom.java
import java.util.Random;

public class ExecutiveRoom extends Hotel {
    public ExecutiveRoom() {
        super(2, 300);
    }

    @Override
    public String infoDisplay() {
        return "Executive Room | RM" + price + " | Available: " + room;
    }

    @Override
    public String generateBookingId() {
        Random random = new Random();
        int number = random.nextInt(900000) + 100000; // to generate random 6 digit number
        return "ER" + number;
    }
}
