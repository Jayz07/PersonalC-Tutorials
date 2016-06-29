public class Hand{
	
	/**
	 * This is a hand class which creates a hand. When creating this hand class it will create an array of empty cards just like
	 * the deck class.
	 * The empty card constructor is being used here because initially the cards in hand are all null.
	 * Just like the deck class
	 */
	Card hand[] = new Card[53];
	int selectedCard;
	
	public Hand(){
		selectedCard = 0;
	}
	
	public void getFirstCardPosition(){
		if(hand[selectedCard] != null){
			selectedCard++;
		}
	}
	
	public void addCard(Card c){
		getFirstCardPosition();
		hand[selectedCard] = c;
	}
	
}
