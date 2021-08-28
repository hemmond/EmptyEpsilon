#ifndef IMAGE_CONFIG_H
#define IMAGE_CONFIG_H

#include "resources.h"  //Containing also include for "string" class from SP's stringImproved.h

class ImageConfig 
{
    public:
        string science_graph_arrow; //Arrow pointing on the frequency of beams/shields in science graph, used in frequencyCurve.cpp


        void load();

    private:
        void dump();
        void store(string key, string value);
};
extern ImageConfig imageConfig;

#endif//IMAGE_CONFIG_H
