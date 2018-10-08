#pragma once
#include<string>

struct WAVHeader{
    std::string chunkID; //Contains "RIFF" in ASCII, big-endian
    long chunkSize; //Entire filesize minus these first 8 bytes.
    std::string format; //Contains letters "WAVE" in ASCII, big-endian.
    std::string subchunkOneID; //Contains letters fmt, big-endian.
    long subchunkOneSize; //Size of the rest of the header following this.
    int audioFormat; //Should be 1 for PCM, other values indicate compression.
    int numChannels;
    long sampleRate;
    long byteRate; //sampleRate * numChannels * bitsPerSample / 8.
    int blockAlign; //numChannels * bitsPerSample / 8.
    int bitsPerSample;
};

struct audioData{
    std::string subchunkTwoID; //Contains ASCII letters "data", big-endian.
    long subchunkTwoSize; // == numSamples * numChannels * bitsPerSample / 8.
    int * data; //pointer to array of sample data.
};