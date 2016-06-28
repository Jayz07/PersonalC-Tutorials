public class Card {
	
	public String cardName; //this is the main card's name.
	int suitValue; //this card's suit value in integer.
	int value; //this card's value in integer.
	String cardValue;
	String suit;
	
	/**
	 * constructs a card
	 * @param a integer 1-4 for the suits
	 * @param b integer 1-13 for the values
	 */
	
	public Card(int a, int b){
		setSuit(a);
		setCardValue(b);
		cardName = suit + " " + cardValue;
	}
	
	/**
	 * setSuit() gets a integer number from 1-4 and returns a suit String. 
	 * @param suitNumber integer number ranging from 1-4
	 */
	
	public void setSuit(int suitNumber){
		
		switch(suitNumber){
		case 1:
			suit = "Diamond";
			break;
		case 2:
			suit = "Clubs";
			break;
		case 3:
			suit = "Hearts";
			break;
		case 4:
			suit = "Spades";
			break;
		default:
			suit = null;
			break;
		}
		suitValue = suitNumber;
		
	}
	
		/**
		 * setCardValue() gets a integer number from 13-1 and returns a card Value String.
		 * @param valueNumber integer ranging from 13-1.
		 */
	
		public void setCardValue(int valueNumber){
			
			switch(valueNumber){
			case 13:
				cardValue = "K";
				break;
			case 12:
				cardValue = "Q";
				break;
			case 11:
				cardValue = "J";
				break;
			case 1:
				cardValue = "A";
				break;
			default:
				cardValue = Integer.toString(valueNumber);
			}
			value = valueNumber;
		}

}
