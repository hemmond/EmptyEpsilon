#include <iostream>
#include <unordered_map>

#include "imageConfig.h"

ImageConfig imageConfig;

void ImageConfig::load()
{
    std::unordered_map<string, string> image_mapping;

    P<ResourceStream> stream = getResourceStream("gui/images.ini");
    if(!stream) {
        std::cout << "No stream to load, exitting." << std::endl;
        return;
    }
    
    while(stream->tell() < stream->getSize())
    {
        string line = stream->readLine();
        std::cout << "Parsing line: " << line << std::endl;

        if (line.find("//") > -1)
            line = line.substr(0, line.find("//")).strip();
        if (line.find("=") > -1)
        {
            string key = line.substr(0, line.find("=")).strip().lower();
            string value = line.substr(line.find("=") + 1).strip();

            std::cout << "Parsing key " << key << ": " << value << std::endl;
            store(key, value);
        } //end of IF for parsing lines with = sign
    } //end of while

    dump();
} //end of load()

void ImageConfig::store(string key, string value)
{
    std::cout << "Storing key " << key << ": " << value << std::endl;
    if(key.lower() == "science_graph_arrow")
        science_graph_arrow = value;
}

void ImageConfig::dump()
{
    //Debug method, dump all stored data to STDOUT.
    std::cout << "===== Image Config Dump =====" << std::endl;
    std::cout << "science_graph_arrow:" << science_graph_arrow << std::endl;
    std::cout << "===== End of Image Dump =====" << std::endl;
}