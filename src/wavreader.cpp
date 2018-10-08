#include<iostream>
#include<fstream>

using namespace std;

typedef struct RIFFdescriptor{
    char chunkID[4];
    long chunkSize;
    char format[4];
};

typedef struct fmtChunk{
    char subchunkOneID[4];
    long subchunkOneSize;
    int audioFormat;
    int numChannels;
    long sampleRate;
    long byteRate;
    int blockAlign;
    int bitsPerSample;
};

typedef struct audioData{
    char subchunkTwoID[4];
    long subchunkTwoSize;
    int * data;
};
