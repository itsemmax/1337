#include <fstream>
#include <iostream>

void replace(std::string &s1,std::string &s2,std::ifstream &infile,std::ofstream &outfile){
	std::string line;
		while(std::getline(infile, line))
		{
			size_t pos = 0;
			while((pos = line.find(s1, pos)) != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
			outfile << line << "\n";
		}
}

int main(int argc, char **argv){
	
		if (argc != 4) {
			std::cerr << "Usage: ./replace <filename> <s1> <s2>\n";
			return 1;
		}
		std::string filename = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];

		if(s1.empty()){
			std::cerr << "Error: <s1> must not be empty\n";
			return(1);
		}
		std::ifstream infile(filename.c_str());
		if(infile.fail()){
			std::cerr <<  "Error: Unable to open " << filename << " file!\n";
			return(1);
		}
		std::ofstream outfile((filename + ".replace").c_str());
		if(outfile.fail()){
			std::cerr <<  "Error: Unable to open " << filename + ".replace" << " file!\n";
			infile.close();
			return(1);
		}
		replace(s1,s2,infile,outfile);
	return(0);
}