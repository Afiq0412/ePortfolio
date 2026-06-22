// HotelBookingSystem.java (Main)
import javax.swing.*;
import java.util.*;

public class HotelBookingSystem {
    public static void main(String[] args) {
        ArrayList<Hotel> rooms = new ArrayList<>();
        // add 4 types of hotel room
        rooms.add(new SingleRoom());
        rooms.add(new DoubleRoom());
        rooms.add(new FamilyRoom());
        rooms.add(new ExecutiveRoom());

        ImageIcon hotelIcon = new ImageIcon("hotel.png");

        while (true) {
            String[] options = {"Book Room", "Cancel Booking", "Exit"};
            int choice = JOptionPane.showOptionDialog(null, "Welcome to RoyalRest Hotel!", "Hotel System",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.INFORMATION_MESSAGE, hotelIcon, options, options[0]);

            if (choice == 0) {
                StringBuilder sb = new StringBuilder("Room Types:\n"); // suitable to append text efficiently
                int i = 1;
                for (Hotel room : rooms) { // to display each types of rooms
                    sb.append(i++).append(": ").append(room.infoDisplay()).append("\n");
                }

                String roomChoiceStr = JOptionPane.showInputDialog(sb.toString() + "\nEnter room number to book:");
                int roomChoice = Integer.parseInt(roomChoiceStr) - 1; // type of hotel
                Hotel selectedRoom = rooms.get(roomChoice);

                if (selectedRoom.getRoom() == 0) {
                    JOptionPane.showMessageDialog(null, "Room not available.");
                    continue;
                }

                String name = JOptionPane.showInputDialog("Enter Name:");
                String ic = JOptionPane.showInputDialog("Enter Identity Number:");
                String phone = JOptionPane.showInputDialog("Enter Phone Number:");

                String[] payOptions = {"Online (Full)", "Offline (50% Deposit)"};
                int payChoice = JOptionPane.showOptionDialog(null, "Choose payment method:", "Payment",
                        JOptionPane.DEFAULT_OPTION, JOptionPane.QUESTION_MESSAGE, null, payOptions, payOptions[0]);

                Booking method = (payChoice == 0) ? new Online() : new Offline();

                String durationStr = JOptionPane.showInputDialog("How many days you want to stay:");
                int duration = Integer.parseInt(durationStr);

                selectedRoom.setDuration(duration);
                Customer cust = new Customer(name, phone, ic);
                cust.placeBooking(selectedRoom, method);

                selectedRoom.room--; // Reduce availability
                HotelSystem.addCustomer(cust);

                JOptionPane.showMessageDialog(null, cust.getReceipt()); // print the receipt

            } else if (choice == 1) {
                String bookingId = JOptionPane.showInputDialog("Enter Booking ID to cancel:");
                Customer toCancel = HotelSystem.findCustomerById(bookingId);
                if (toCancel != null) {
                    HotelSystem.removeCustomer(bookingId);
                    JOptionPane.showMessageDialog(null, "Booking cancelled for ID: " + bookingId);
                } else {
                    JOptionPane.showMessageDialog(null, "No booking found with that ID.");
                }

            } else {
                break;
            }
        }
    }
}