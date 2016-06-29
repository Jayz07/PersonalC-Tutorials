
public class Card {
	/**
	 * The follow string is for display purposes. They are what the user will see.
	 */
	public String cardName;
	public String value;
	public String suit;
	
	/**
	 * The following int values are for the program to determine the values for future card games.
	 */
	public int suitValue;
	public int cardValue;
	
	/**
	 * This is a Card constructor with two int variables. This will be used to create cards and assigning them a card name.
	 * @param a is an int ranging from 1-4
	 * @param b is an int ranging from 1-13
	 */
	public Card(int a,int b){
		setSuit(a);
		setCardValue(b);
		setCardName();
	}
	
	
	/**
	 * This empty constructor is used especially for the Hand.class to create an empty array of Cards.
	 */
	public Card(){
		
	}
	
	
	/**
	 * This is used to set the card name from the two variables.
	 */
	public void setCardName(){
		cardName = suit + " " + value;
	}
	
	
	/**
	 * Sets the suits after taking an int parameter..
	 * It will output both the suit String value and the suit int value.
	 * @param a is an int value ranging from 1-4.
	 */
	public void setSuit(int a){
		switch(a){
		case 1:
			suit = "DIAMONDS";
			break;
		case 2:
			suit = "CLUBS";
			break;
		case 3:
			suit = "HEARTS";
			break;
		case 4:
			suit = "SPADES";
			break;
		default:
			suit = null;
			break;
		}
		suitValue = a;
	}
	
	
	/**
	 * Sets the card value from K-A after taking in an int parameter
	 * It will output both value String value and the int card value value 
	 * @param a is an int value from 1-13
	 */
	public void setCardValue(int a){
		switch(a){
		case 13:
			value = "K";
			break;
		case 12:
			value = "Q";
			break;
		case 11:
			value = "J";
			break;
		case 1:
			value = "A";
			break;
		default:
			value = Integer.toString(a);
		}
		cardValue = a;
	}
	
	
}
