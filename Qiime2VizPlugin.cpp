#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "Qiime2VizPlugin.h"

void Qiime2VizPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void Qiime2VizPlugin::run() {
   
}

void Qiime2VizPlugin::output(std::string file) {  
   std::string myPrefix = std::string(PluginManager::prefix());
   std::string command = "eval \"$(conda shell.bash hook)\"; ";
   command += "conda activate qiime2-2020.11; ";
   command += "qiime ";
   std::string op1, op2;
   op1 = parameters["op1"];
   op2 = parameters["op2"];
   command += op1+" ";
   command += op2+" ";
   if (op1 == "demux") {
      command += "--i-data "+myPrefix+"/"+parameters["data"]+" ";
   }
   else if (op1 == "metadata") {
      command += "--m-input-file "+myPrefix+"/"+parameters["inputfile"]+" ";
   }
   else if (op1 == "deblur") {
      command += "--i-deblur-stats "+myPrefix+"/"+parameters["deblurstats"]+" ";
   }
   else if (op1 == "feature-table") {
      if (op2 == "tabulate-seqs")
         command += "--i-data "+myPrefix+"/"+parameters["data"]+" ";
      else { // summarize
	 command += "--i-table "+myPrefix+"/"+parameters["table"]+" ";
	 command += "--m-sample-metadata-file "+myPrefix+"/"+parameters["metadata"]+" ";
      }
   }
   else if (op1 == "taxa") {
	 command += "--i-table "+myPrefix+"/"+parameters["table"]+" ";
	 command += "--i-taxonomy "+myPrefix+"/"+parameters["taxonomy"]+" ";
	 command += "--m-metadata-file "+myPrefix+"/"+parameters["metadata"]+" ";
   }
   command += " --o-visualization "+file+"; conda deactivate";
 //std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<Qiime2VizPlugin> Qiime2VizPluginProxy = PluginProxy<Qiime2VizPlugin>("Qiime2Viz", PluginManager::getInstance());
