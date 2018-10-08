#include <iostream>
#include <string>
#include <fstream>
#include "wavheader.h"
#include "wavreader.h"

using namespace std;

/**
 * Alan Miller
 * This program is mostly just me toying around with the structure
 * of .wav files and exploring methods of parsing them.  Its functionality
 * may possibly be integrated with a qt application in the future for
 * visualization of audio data.
 * */
int main(){
    
    std::string filename;

    WAVHeader header;
    audioData data;

    cout << "Enter .wav file path : ";
    getline(cin, filename);

    fstream stream;
    stream.open(filename.data(), std::fstream::in | std::fstream::binary);
    
    if(stream.fail()){
        cout << "\nError opening file, terminating\n";
        return -1;
    }
    
    cout << "\nFile opened successfully\n";

    header = extractHeader(filename);
    
    cout << "chunkID = " << header.chunkID << "\n";
    cout << "chunkSize = " << header.chunkSize << "\n";

    return 0;
}