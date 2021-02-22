#ifndef QIIME2VIZPLUGIN_H
#define QIIME2VIZPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class Qiime2VizPlugin : public Plugin
{
public: 
 std::string toString() {return "Qiime2Viz";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::map<std::string, std::string> parameters;

};

#endif
