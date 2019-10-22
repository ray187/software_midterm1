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

#ifdef UTEST
    double utest[][3] = {
        1, 16.35, 0,
        2, 17.32, 0,
        3, 18.35, 0,
        4, 19.45, 0,
        5, 20.60, 0,
        6, 21.83, 0,
        7, 23.12, 0,
        8, 24.50, 0,
        9, 25.96, 0,
        10, 27.50, 0,
        11, 29.14, 0,
        12, 30.87, 0,
        1, 32.70, 1,
        2, 34.65, 1,
        3, 36.71, 1,
        4, 38.89, 1,
        5, 41.20, 1,
        6, 43.65, 1,
        7, 46.25, 1,
        8, 49.00, 1,
        9, 51.91, 1,
        10, 55.00, 1,
        11, 58.27, 1,
        12, 61.74, 1,
        1, 65.41, 2,
        2, 69.30, 2,
        3, 73.42, 2,
        4, 77.78, 2,
        5, 82.41, 2,
        6, 87.31, 2,
        7, 92.50, 2,
        8, 98.00, 2,
        9, 103.83, 2,
        10, 110.00, 2,
        11, 116.54, 2,
        12, 123.47, 2 ,
        1, 130.81, 3,
        2, 138.59, 3,
        3, 146.83, 3 ,
        4, 155.56, 3,
        5, 164.81, 3 ,
        6, 174.61, 3,
        7, 185.00, 3,
        8, 196.00, 3,
        9, 207.65, 3,
        10, 220.00, 3,
        11, 233.08, 3,
        12, 246.94, 3,
        1, 261.63, 4,
        2, 277.18, 4,
        3, 293.66, 4,
        4, 311.13, 4,
        5, 329.63, 4,
        6, 349.23, 4,
        7, 369.99, 4,
        8, 392.00, 4,
        9, 415.30, 4,
        10, 440.00 ,4,
        11, 466.16 ,4 ,
        12, 493.88  ,4 ,
        1, 523.25   ,5 ,
        2, 554.37   , 5,
        3, 587.33   ,5,
        4, 622.25   ,5,
        5, 659.25   ,5,
        6, 698.46   ,5,
        7, 739.99   ,5,
        8, 783.99   ,5,
        9, 830.61,5,
        10, 880.00 ,5,
        11, 932.33 ,5,
        12, 987.77,5
            1, 1046.50  ,6,
        2, 1108.73 ,6,
        3, 1174.66  ,6,
        4, 1244.51 ,6,
        5, 1318.51  ,6,
        6, 1396.91  ,6,
        7, 1479.98  ,6,
        8, 1567.98  ,6,
        9, 1661.22  ,6,
        10, 1760.00    , 6,
        11, 1864.66     ,6,
        12, 1975.53     ,6,
        1, 2093.00  ,7,
        2, 2217.46  ,7,
        3, 2349.32  ,7,
        4, 2489.02  ,7,
        5, 2637.02  ,7,
        6, 2793.83 ,7,
        7, 2959.96  ,7,
        8, 3135.96  ,7,
        9, 3322.44  ,7,
        10, 3520.00    ,7,
        11, 3729.31     ,7,
        12, 3951.07 ,7,
        1, 4186.01  ,8,
        2, 4434.92  ,8,
        3, 4698.63  ,8,
        4, 4978.03  ,8,
        5, 5274.04  ,8,
        6, 5587.65  ,8,
        7, 5919.91,8,
        8, 6271.93 ,8,
        9, 6644.88 ,8,
        10,7040.00 ,8,
        11, 7458.62 ,8,
        12, 7902.13 ,8,
    };
    if(argc <= 2) {
        cout << "Usage: " << argv[0] << " <TOLERANCE> " << endl;
        return 0;
    }
    else if (note == (note_t)26 && octave_delta == 0 && argc == 4) {
    cout << " note active actual expected       difference" << endl;
    cout << " ----- ----- ------  -------      -----------" << endl;
    float diffrence;
    int count = 0;
    for (int i = 0; i < 108; i++) {
        note = (note_t)utest[i][0];
        octave_delta = test[i][2];
        diffrence = getFrequency(note, octave_delta) - utest[i][1];
        if (diffrence < 0) {
            diffrence = 0;
        }
        cout << " " << utest[i][0] << "    " << utest[i][2] << "   " << getFrequency(note,octave_delta) << "    " << utest[i][1]<< "      " << diffrence << "   ";
        (diffrence < atof(argv[1])) ? cout << "    good" <<endl : cout << "   <---bad" << endl;
        (diffrence < atof(argv[1])) ? count = count : count++;
    }
    cout << "bad element: " << count << endl;
    cout << "unit test complete. " << endl;
return 0;
#endif

        if (argc < 3 || argc > 4 ) {
            cout << "Usage:  " << argv[0] << " <NOTE> <OCTAVE_DELTA>" << endl;
            return 0;
        }
        //
        note = (note_t)(toupper(argv[1][0]) - 64);
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


