/*		
		A TV serial/trilogy trivia totally inspired by
		nothing but getting used to arrays and loops... XD
	
		Written by Redhart Nakamura Nokturnal
	
*/	


#include <iostream>
#include <string>
#include <iomanip> // for the setw() spacing
#include <algorithm> // for the transform() case switch

using namespace std;

int main(){
	const int arraySize = 10; // number of questions *constant*
	
	// greet
	cout << "\n\tWelcome to " << arraySize << "-questions game!\n\tGoodluck!\n\n Press ENTER to begin . . .\n\n";
	
	// pause
	string justNull;
	getline(cin, justNull);
	
	// clues
	string clues[arraySize];
	clues[0] = "Who knows nothing?";
	clues[1] = "Sirius Black was Harry Potter's _.";
	clues[2] = "Katerina Petrova became a vampire in ..?";
	clues[3] = "Fill in the missing word: The _ Games: Mockingjay?";
	clues[4] = "The URL of my website is..? (hint: full URL)";
	clues[5] = "Agent Ward betrayed S.H.I.E.L.D. because he was a spy for ..?";
	clues[6] = "Iron Man's best friend: _";
	clues[7] = "Leonardo Di Caprio still has no _.";
	clues[8] = "Hercules is the son of _.";
	clues[9] = "\"I met this girl, we talked, it was epic but when the sun came up, reality set in..\" - These are the words of ..?";

	// solutions
	string solutions[arraySize];
	solutions[0] = "Jon Snow";
	solutions[1] = "godfather";
	solutions[2] = "1864";
	solutions[3] = "Hunger";
	solutions[4] = "http://www.mantraloft.com";
	solutions[5] = "Hydra";
	solutions[6] = "JARVIS";
	solutions[7] = "Oscar";
	solutions[8] = "Zeus";
	solutions[9] = "Stefan Salvatore";
	
	// loop through and display each clue
	for(int i = 0; i < arraySize; ++i){
	cout << "\n\nQuestion " << i+1 << ": ";
	cout << clues[i] << setw(15);
	}
	
	cout << "\n\n\n";
	
	// capture player's answer
	string userAnswers[arraySize]; // the array
	for(int j = 0; j < arraySize; ++j){ // begin loop
		cout << "Answer to question " << j+1 << ": "; // ask
		getline(cin, userAnswers[j]); // capture line
	} // end loop
	
	cout << "\n\n\n";
	
	string Answers[arraySize];
	int finalAns = 0;
	
	for(int k = 0; k < arraySize; ++k){
		
		// convert player's line to lower case
		transform(userAnswers[k].begin(), userAnswers[k].end(), userAnswers[k].begin(), ::tolower);
		
		// convert solutions to lower case too for comparison
		transform(solutions[k].begin(), solutions[k].end(), solutions[k].begin(), ::tolower);
		
		if(userAnswers[k] == solutions[k]){ // if correct
			cout << "\n\nAnswer " << k+1 << " correct: " << solutions[k]; // cheer
			finalAns++;
		}
		else{
			cout << "\n\nAnswer " << k+1 << " incorrect: " << userAnswers[k] << " (" << solutions[k] << ")"; // boo
		}
	}
	
	 // Scoreboard
	cout << "\n\n\n\t==> Your Score: " << finalAns << "/" << arraySize << "\n\n\t==> ";
	if(finalAns >= (arraySize/2)){
		cout << "Good! Keep it up";
	}
	else if((arraySize-finalAns) < 2){
		cout << "Bravo! You did great.";
	}
	else if (finalAns == arraySize){
		cout << "Excellent! You know the game";
	}
	else{
		cout << "OOPS! Please try again.";
	}
	
	cout << "\n";
	
return 0;
}
