// DoubleRoom.java
import java.util.Random;

public class DoubleRoom extends Hotel {
    public DoubleRoom() {
        super(5, 150);
    }

    @Override
    public String infoDisplay() {
        return "Double Room | RM" + price + " | Available: " + room;
    }

    @Override
    public String generateBookingId() {
        Random random = new Random();
        int number = random.nextInt(900000) + 100000; // to generate random 6 digit number
        return "DR" + number;
    }
}
