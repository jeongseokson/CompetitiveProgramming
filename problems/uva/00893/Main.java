import java.util.Scanner;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            int after = in.nextInt(),
                day = in.nextInt(),
                month = in.nextInt(),
                year = in.nextInt();

            if (after == 0 && day == 0 && month == 0 && year == 0)
                break;

            Calendar calendar = new GregorianCalendar(year, month - 1, day);
            calendar.add(Calendar.DATE, after);

            System.out.println(calendar.get(Calendar.DATE) + " "
                    + (calendar.get(Calendar.MONTH) + 1) + " "
                    + calendar.get(Calendar.YEAR));
        }

    }
}
