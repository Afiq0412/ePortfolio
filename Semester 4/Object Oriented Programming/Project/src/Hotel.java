import java.time.LocalDate;

public abstract class Hotel {
    protected final String hotelName = "DreamScape Hotel"; // Fixed name
    protected int room;
    protected double price;
    protected int duration;
    protected LocalDate checkIn;
    protected LocalDate checkOut;

    public Hotel(int room, double price) {
        this.room = room;
        this.price = price;
    }

    public String getHotelName() {
        return hotelName;
    }

    public int getRoom() {
        return room;
    }

    public double getPrice() {
        return price;
    }
    public LocalDate getCheckIn(){
        checkIn = LocalDate.now();
        return checkIn;
    }
    public LocalDate getCheckOut(){
        checkOut = checkIn.plusDays(getDuration());
        return checkOut;
    }
    public void setDuration(int duration) {
        this.duration = duration;
    }
    public int getDuration(){
        return duration;
    }
    public abstract String infoDisplay();
    public abstract String generateBookingId();
}
