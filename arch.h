#include<fstream>
#include<vector>
#include<iostream>

class arch
{
    public:
        arch(std::string file, std::string arc);
        std::string getFileName();
        std::string getArchitechture();
        void getExclusives(arch a);
        void readFile();
        void findPrograms();
        void listPrograms();
        void listExclusives();
        void writeExclusives(std::ofstream& o);
        void listInput();
    private:
        std::vector<std::string> input;
        std::vector<std::string> packages;
        std::vector<bool> packagesb;
        std::vector<std::string> exclusives;
        std::string fileName;
        std::string architechture;
        std::string line;
        int foundPos;
};
