public class EnumTest1 {
    enum Day {
        SUNDAY, MONDAY, TUESDAY, WEDNESDAY,
        THURSDAY, FRIDAY, SATURDAY
    }

    public static void main(String[] args) {
        Day workday;
        workday = Day.THURSDAY;
        System.out.println("Today is " + workday);
        System.out.println("Yesterday was " + Day.WEDNESDAY);

        System.out.println("Ordinal value: " + workday + " - " + workday.ordinal());

        Day myDay = Day.FRIDAY;
        if (myDay.equals(workday))
            System.out.println("same day ");
        else
            System.out.println("different day ");

        Day tDay = Day.SATURDAY;
        int result = tDay.compareTo(workday);
        System.out.println(result);

        for (Day d : Day.values()) {
            System.out.println(d);
        }
    }
}
