public class Customer {
    private String name;
    private String phone;
    private String ic;
    private Hotel hotel;
    private String bookingId;
    private Booking bookingMethod;

    public Customer(String name, String phone, String ic) {
        this.name = name;
        this.phone = phone;
        this.ic = ic;
    }

    public void placeBooking(Hotel hotel, Booking bookingMethod) {
        this.hotel = hotel;
        this.bookingMethod = bookingMethod;
        bookingMethod.bookHotel(hotel, this);
    }

    public String getBookingId() {
        return bookingId;
    }

    public String getReceipt() {
        return "\n======== Booking Receipt ========" +
                "\nHotel: " + hotel.getHotelName() +
                "\nName: " + name +
                "\nIC: " + ic +
                "\nPhone: " + phone +
                "\n======== Room Details ========" +
                "\nRoom: " + hotel.getClass().getSimpleName() + // return hotel name
                "\nPrice (Per Day): RM" + hotel.getPrice() + 
                "\nDuration: " + hotel.getDuration() + " days" +
                "\nBooking ID: " + hotel.generateBookingId() +
                "\nCheck In: " + hotel.getCheckIn() + " - " + hotel.getCheckOut() +
                "\nPayment Method: " + bookingMethod.getClass().getSimpleName() + // return room name
                "\nTotal Payment: RM" + bookingMethod.getPayment();
    }
}