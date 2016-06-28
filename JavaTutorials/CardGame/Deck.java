import java.util.Random;

public class Deck {
	
	Card cardsInDeck []= new Card[52];
	
	public Deck(){
		int value;//values
		int suit;//suits
		int i = 0;
		
		for(suit = 1; suit <=4; suit++){
			for(value = 1; value <=13; value++){
				cardsInDeck[i] = new Card(suit,value);
				i++;
			}
		}
	}
	
	public void showDeck(){
		int cardPosition = 1;
		for(Card a: cardsInDeck){
			System.out.println("Card position = " + cardPosition + " is " + a.cardName);
			cardPosition++;
		}
	}
	
	public void shuffle(){
		Random shuffle = new Random();
		Card card1;
		Card card2;
		int a;
		int b;
		
		for(int shuffleCount = 0; shuffleCount <=9999; shuffleCount++){
			a = shuffle.nextInt(52);
			b = shuffle.nextInt(52);
			card1 = cardsInDeck[a];
			card2 = cardsInDeck[b];
			cardsInDeck[a] = card2;
			cardsInDeck[b] = card1;
		}
	}
	
	
	public static void main(String args[]){
		Deck deckA = new Deck();
		deckA.shuffle();
	}
	
}
