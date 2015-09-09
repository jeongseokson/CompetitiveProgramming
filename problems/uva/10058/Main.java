import java.util.Scanner;

public class Main {
	private static final String VERB = "(hate|love|know|like)s?";
	private static final String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
	private static final String ARTICLE = "(a|the)";
	private static final String ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
	private static final String ACTIVE_LIST = ACTOR + "( and " + ACTOR + ")*";
	private static final String ACTION = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST;
	private static final String STATEMENT = ACTION + "( , " + ACTION + ")*";

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNextLine()) {
			String str = sc.nextLine();
			if (str.matches(STATEMENT))
				System.out.println("YES I WILL");
			else
				System.out.println("NO I WON'T");
		}
		sc.close();
	}
}
