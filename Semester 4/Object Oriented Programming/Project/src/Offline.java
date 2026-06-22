public class Offline implements Booking {
    public static final double PAYMENT_RATE = 0.5;
    private double payment;

    public void bookHotel(Hotel hotel, Customer customer) {
        setPayment(hotel);
    }

    public void setPayment(Hotel hotel) {
        this.payment = hotel.getPrice() * PAYMENT_RATE * hotel.getDuration();
    }

    public double getPayment() {
        return payment;
    }
}