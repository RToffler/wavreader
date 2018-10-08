#include <iostream>
#include <fstream>
#include "wavheader.h"

using namespace std;

WAVHeader extractHeader(std::string fileName){
    WAVHeader header;
    
    //memBlock for assigning null terminator.
    char * memBlock = new char[5];
    memBlock[4] = '\0';

    fstream stream;
    stream.open(fileName, fstream::in);
    
    stream.read(memBlock, 4);
    header.chunkID = memBlock;

    stream.read(memBlock, 4);
    header.chunkSize = atoi(memBlock);
    return header;
}