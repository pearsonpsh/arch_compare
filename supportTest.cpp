#include<iostream>
#include<fstream>
#include <vector>
#include"arch.h"
using namespace std;

int main(int argc, char *argv[]){
    ofstream fileOutput;   
    vector<arch> archs;

    string pkgstr = "Package: ";
    int foundPos;
    for (int i = 1; i < argc; i++){
        if (i % 2 != 0)
            archs.push_back(arch(argv[i],argv[i+1]));
              
    }


    for (int a = 0; a < archs.size(); a++){
        archs.at(a).readFile();
        //archs.at(a).listInput();
        archs.at(a).findPrograms();
        //archs.at(a).listPrograms();
    }

    string outputName = archs.at(0).getArchitechture() + "VS" + archs.at(1).getArchitechture() + ".txt";
    fileOutput.open(outputName); 

    archs.at(0).getExclusives(archs.at(1));
    archs.at(1).getExclusives(archs.at(0));

    //cout << "\n" << archs.at(0).getArchitechture() << " exclusives: \n";
    fileOutput << "\n" << archs.at(0).getArchitechture() << " exclusives: \n";
    //archs.at(0).listExclusives();
    archs.at(0).writeExclusives(fileOutput);
    //cout << "\n" << archs.at(1).getArchitechture() << " exclusives: \n";
    fileOutput << "\n" << archs.at(1).getArchitechture() << " exclusives: \n";
    //archs.at(1).listExclusives();
    archs.at(1).writeExclusives(fileOutput);
    fileOutput.close();
   
    return 0;
}
