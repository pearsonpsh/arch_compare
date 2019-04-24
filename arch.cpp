#include"arch.h"

arch::arch(std::string file, std::string arc){
    std::cout << "Creating arch\n filename: " << file << "\narchitechture: " << arc << std::endl;
    fileName = file;
    architechture = arc;
}

void arch::readFile(){
    std::ifstream fileInput;
    fileInput.open(fileName);
    std::cout << "opening file:  " << fileName << std::endl;
    std::cout << "architechture: " << architechture << std::endl;
    if (fileInput.is_open()){
        while(getline(fileInput,line)){
                input.push_back(line);                                
        }
    }
    else
        std::cout << "Error opening file\n";

        fileInput.close();
}

void arch::findPrograms(){
    std::string pkgstr = "Package: ";
    for (int ii = 0; ii < input.size(); ii++){
        foundPos = input.at(ii).find(pkgstr);
        if (foundPos >= 0){
            line = input.at(ii).substr(9,input.at(ii).length() - 9);
            //cout << line << endl;
            packages.push_back(line);
        }
    }
}

void arch::listPrograms(){
    for (int ii = 0; ii < packages.size(); ii++){
        std::cout << packages.at(ii) << std::endl;
    }
}

void arch::listInput(){
    for (int ii = 0; ii < input.size(); ii++){
        std::cout << input.at(ii) << std::endl;
    }
}

void arch::listExclusives(){
    for (int ii = 0; ii < exclusives.size(); ii++){
        std::cout << exclusives.at(ii) << std::endl;
    }
}

void arch::writeExclusives(std::ofstream& o){
    for (int ii = 0; ii < exclusives.size(); ii++){
        o << exclusives.at(ii) << "\n";
    }
}

void arch::getExclusives(arch a){
    for (int ii = 0; ii < packages.size(); ii++){
        packagesb.push_back(false);
        for (int iii = 0; iii < a.packages.size(); iii++){
            //foundPos = arm64apps.at(ii).find(armhfapps.at(iii));
            if (packages.at(ii).compare(a.packages.at(iii)) == 0){
                packagesb.at(ii) = true;
                //std::cout << "found match: " << packages.at(ii) << " & " << a.packages.at(iii) << std::endl;
            }
        }
        if (!packagesb.at(ii))
            exclusives.push_back(packages.at(ii));
        //cout << arm64apps.at(ii) << " " << arm64b.at(ii) << endl;
    }
}

std::string arch::getFileName(){
    return fileName;
}

std::string arch::getArchitechture(){
    return architechture;
}


