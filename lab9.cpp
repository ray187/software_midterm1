//
//CMPS 3350
//
//Write a unit-test of the getFrequency() function.
//Isolate your unit test using preprocessor directives.
//See web page for detailed instructions.
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

enum note_t {
	//Do not modify this enum structure.
	C = 1,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	END = B,
	HALF_STEPS_PER_OCTAVE = B 
};

double getFrequency(note_t note, int octave_delta);


int main(int argc, char *argv[])
{
	note_t note;
	int octave_delta;

	if (argc != 3) {
		cout << "Usage:  " << argv[0] << " <NOTE> <OCTAVE_DELTA>" << endl;
		return 0;
	}
	//
	note = (note_t)(toupper(argv[1][0]) - 'A' - 1);
	switch (toupper(argv[1][0])) {
		case 'A':
			note = A;
			break;
		case 'B':
			note = B;
			break;
		case 'C':
			note = C;
			break;
		case 'D':
			note = D;
			break;
		case 'E':
			note = E;
			break;
		case 'F':
			note = F;
			break;
	}
	if (note > END) {
		cout << "Invalid note!" << endl;
		return 1;
	}
	octave_delta = atoi(argv[2]);
	cout << "half steps per octive: " << HALF_STEPS_PER_OCTAVE << endl;
	cout << "                 note: " << (char)toupper(argv[1][0]) << endl;
	cout << "            frequency: " << getFrequency(note, octave_delta);
	cout << endl;
	return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//-----------------------------------------------------------
double getFrequency(note_t note, int octave_delta)
{
	//Do not modify this function.
	double freq;
	double factor;
	double a;
	int no;
	int octave = octave_delta - F0_octave;

	//Do not modify this code.
	a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
	no = note - F0_note;
	freq = F0 * pow(a, (double)no);
	factor = pow(2.0, (double)octave);
	freq = freq * factor;
	return freq;
}


