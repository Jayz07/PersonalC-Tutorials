import java.util.Random;

public class Deck {
	
	/**
	 * cardDeck array is an array of card objects. A poker card deck has only 52 cards. But this Array will create 53 cards.
	 * This is to use cardDeck[52] as a reference stating that it's already the end of the deck.
	 */
	public Card cardDeck[] = new Card[53];
	public int selectedCard;
	
	
	/**
	 * The Deck constructor automatically makes a deck and shuffles it when a Deck instance is being made.
	 */
	public Deck(){
		makeDeck();
		shuffle();
		selectedCard = 0;
	}
	
	
	/**
	 * It makes 52 cards using the Card constructor. 
	 * Leaves one Card object as null.
	 */
	public void makeDeck(){
		int c = 0;	
			for(int a = 1; a <=4; a++){
				for(int b = 1; b <=13; b++){
					cardDeck[c] = new Card(a,b);
					c++;
				}
			}
		}
	
	
	/**
	 * Shuffles the deck.
	 */
	public void shuffle(){
		Card card1;
		Card card2;
		int a;
		int b;
		for(int i = 0; i < new Random().nextInt(999999)+9999; i++){
			a = new Random().nextInt(52);
			b = new Random().nextInt(52);
			card1 = cardDeck[a];
			card2 = cardDeck[b];
			cardDeck[2] = card1;
			cardDeck[1] = card2;
		}
	}
	
	/**
	 * A static method used to display all the cards in a Card object Array including empty ones.
	 * @param c is a Card object Array.
	 */
	public static void displayCards(Card c[]){
		int i;
		for(i = 0; i < 52; i ++){
			Card card1 = c[i];
			if(card1 == null){
				System.out.printf("%-13s: %-2s = %s\n",
						"Card position", i, "empty");
			}else{
				System.out.printf("%-13s: %-2s = %-20s\n",
						"Card position", i, card1.cardName);
			}
		}
	}
	
	/**
	 * A static method that displays all cards except for empty ones.
	 * @param c is a Card object Array.
	 */
	public static void displayCards2(Card c[]){
		int i;
		for(i = 0; i < 52; i ++){
			Card card1 = c[i];
			if(card1 != null){
				System.out.printf("%-13s: %-2s = %-20s\n",
						"Card position", i, card1.cardName);
			}
		}
	}
	
	
	/**
	 * A static method used for displaying all the empty cards and it's card position.
	 * Generally used for debugging.
	 * @param c Has to be a Card object Array.
	 */
	public static void displayEmptyCards(Card c[]){
		int i;
		for(i = 0; i < 52; i++){
			if(c[i] ==null){
				System.out.printf("%-13s: %-2s = %s\n",
						"Card position", i, "empty");
			}
		}
	}
	
	
	/**
	 * Removes the card from the Deck.
	 * Considering the change it into a static method since both hand and deck uses this simple method.
	 * @param is an int ranging from 0-52. 53 is not allowed to be changed as it is used to mark the end of the deck.
	 */
	public void removeCard(int i){
		cardDeck[i] = null;
	}
	
	
	/**
	 * Returns the position of the first card from the top.
	 * @return int value ranging from 0-52. 53 is not allowed to be used.
	 */
	public void getFirstCardPosition(){
		if(cardDeck[selectedCard] == null){
			selectedCard++;
		}
	}
	
	
	/**
	 * This method is used to transfer a card from the deck to a hand object
	 * @param h must be a hand object
	 */
	public void giveCard(Hand h){
		getFirstCardPosition();
		h.addCard(cardDeck[selectedCard]);
		removeCard(selectedCard);
	}
	
	/**
	 * test program for shuffle()
	 */
	public static void main(String args[]){
		Deck deckA = new Deck();
		Deck.displayCards(deckA.cardDeck);
		
	}
}
