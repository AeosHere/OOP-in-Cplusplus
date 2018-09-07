//Richard Yeung
//Recitation 10
//Inheritance Practice Continued

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Instrument {
public:
	void virtual makeSound() const = 0;
	void virtual makeNormalSound() const = 0;
private:
};

void Instrument::makeSound() const {
	cout << "To make a sound... ";
}

class Brass : public Instrument {
public:
	Brass(unsigned size) : mouthPieceSize(size) {}
	void virtual makeSound() const {
		Instrument::makeSound();
		cout << "blow on a mouthpiece of size " << mouthPieceSize << endl;
	}
private:
	unsigned mouthPieceSize;
};

class Trumpet : public Brass {
public:
	Trumpet(unsigned size) : Brass(size) {}
	void makeNormalSound() const {
		cout << "Toot";
	}
};

class Trombone : public Brass {
public:
	Trombone(unsigned size) : Brass(size) {}
	void makeNormalSound() const {
		cout << "Blat";
	}
};

class String : public Instrument {
public:
	String(unsigned pitch) : pitch(pitch) {}
	void virtual makeSound() const {
		Instrument::makeSound();
		cout << "bow a string with pitch " << pitch << endl;
	}
private:
	unsigned pitch;
};

class Violin : public String {
public:
	Violin(unsigned pitch) : String(pitch) {}
	void makeNormalSound() const {
		cout << "Screech";
	}
};

class Cello : public String {
public:
	Cello(unsigned pitch) : String(pitch) {}
	void makeNormalSound() const {
		cout << "Squawk";
	}
};

class Percussion : public Instrument {
public:
	void virtual makeSound() const {
		Instrument::makeSound();
		cout << "hit me!" << endl;
	}
private:
};

class Drum : public Percussion {
	void makeNormalSound() const {
		cout << "Boom";
	}
};

class Cymbal : public Percussion {
	void makeNormalSound() const {
		cout << "Crash";
	}
};

class MILL {
public:
	void receiveInstr(Instrument& anInstrument) {
		anInstrument.makeSound();
		for (size_t i = 0; i < instruments.size(); ++i) {
			if (instruments[i] == nullptr) {
				instruments[i] = &anInstrument;
				return;
			}
		}
		instruments.push_back(&anInstrument);
	}
	void dailyTestPlay() const {
		for (size_t i = 0; i < instruments.size(); ++i) {
			if (instruments[i] != nullptr) {
				instruments[i]->makeSound();
			}
		}
	}
	Instrument* loanOut() {
		for (size_t i = 0; i < instruments.size(); ++i) {
			if (instruments[i] != nullptr) {
				Instrument* tempInstrument = instruments[i];
				instruments[i] = nullptr;
				return tempInstrument;
			}
		}
		return nullptr;
	}
private:
	vector<Instrument*> instruments;
};

class Musician {
public:
	Musician() : instr( nullptr ) {}
	void acceptInstr( Instrument & i ) { instr = &i; }
	Instrument* giveBackInstr( ) { 
		Instrument* tmp(instr); 
		instr = nullptr;
		return tmp;
	}
	void testPlay() const {
		if( instr )
			instr->makeSound(); 
		else
			cerr << "have no instr\n";
	}
	void playInstrument() const {
		if (instr != nullptr) {
			instr->makeNormalSound();
		}
	}
private:
	Instrument* instr;
};

class Orch {
public:
	void addPlayer(Musician& aMusician){
		if (musicians.size() < 25) {
			musicians.push_back(&aMusician);
		}
		else {
			cerr << "This orchestra has 25 musicians already!" << endl;
		}
	}
	void play(){
		for (size_t i = 0; i < musicians.size(); ++i) {
			musicians[i]->playInstrument();
		}
		cout << endl;
	}
private:
	vector<Musician*> musicians;
};

// PART ONE
int main()
{
	/*
	cout << "PART ONE" << endl;
	cout << "Define some instruments ----------------------------------------\n";
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone( 4 );
	Trumpet trpt( 12 ) ;
	Violin violin( 567 ) ;
  
	// // use the debugger to look at the mill
	cout << "Define the MILL ------------------------------------------------\n";
	MILL mill;
  
	cout << "Put the instruments into the MILL ------------------------------\n";
	mill.receiveInstr( trpt );
	mill.receiveInstr( violin );
	mill.receiveInstr( tbone );
	mill.receiveInstr( drum );
	mill.receiveInstr( cello );
	mill.receiveInstr( cymbal );
  
	cout << "Daily test -----------------------------------------------------\n";
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;
  
	cout << "Define some Musicians-------------------------------------------\n";
	Musician j;
	Musician jj;
	Musician q;
  	
	cout << "TESTING: q.acceptInstr( *mill.loanOut() );-----------------------\n";
	q.testPlay();	
	cout << endl;
	q.acceptInstr( *mill.loanOut() );
	cout << endl;
	q.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
  
	cout << endl << endl;
  
	q.testPlay();	
	cout << endl;
	mill.receiveInstr( *q.giveBackInstr() );
	j.acceptInstr( *mill.loanOut() );
	q.acceptInstr( *mill.loanOut() );
	cout << endl;
	q.testPlay();
	cout << endl;
	j.testPlay();
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
  
	cout << "TESTING: mill.receiveInstr( *q.giveBackInstr() ); -------------\n";
  
	// // fifth
	mill.receiveInstr( *q.giveBackInstr() );
	cout << "TESTING: mill.receiveInstr( *j.giveBackInstr() ); -------------\n";
	mill.receiveInstr( *j.giveBackInstr() );

  
	cout << endl;
	cout << "dailyTestPlay()" << endl;
	mill.dailyTestPlay();
	cout << endl;
	// cout << endl;
	*/
	
	// The initialization phase
	cout << "PART TWO" << endl;
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;

	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

}

