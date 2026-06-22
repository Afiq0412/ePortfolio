// SingleRoom.java
import java.util.Random;

public class SingleRoom extends Hotel {
    public SingleRoom() {
        super(5, 100);
    }

    @Override
    public String infoDisplay() {
        return "Single Room | RM" + price + " | Available: " + room;
    }

    @Override
    public String generateBookingId() {
        Random random = new Random();
        int number = random.nextInt(900000) + 100000; // to generate random 6 digit number
        return "SR" + number;
    }
}
