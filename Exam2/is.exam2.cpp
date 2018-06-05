#include<iostream>
#include<vector>
#include<string>
class File {
	std::string name;
public:
	File() = default;
	File(std::string& _name) :name(_name) {}
	virtual unsigned int size() = 0;
	virtual void info() = 0;
	virtual void contents() = 0;
	std::string getName() {
		return name;
	}
	virtual void selfCopy(File*&) = 0;
};
class TextFile :public File {
	std::string description;
public:
	TextFile() = default;
	TextFile(std::string _name, std::string _description) :File(_name), description(_description) {}
	unsigned int size() {
		return description.size();
	}
	void info() {
		std::cout << getName();
	}
	void contents() {
		std::cout << description;
	}
	void selfCopy(File*& dest) {
		dest = new TextFile(*this);
	}
};
class Directory :public File {
	std::vector<File*> files;
public:
	Directory() = default;
	Directory(std::string _name) :File(_name) {}
	unsigned int size() {
		unsigned int sum = 0;
		for (File* singleFile : files) {
			sum += singleFile->size();
		}
		return sum;
	}
	void info() {
		for (File* singleFile : files) {
			singleFile->info();
			std::cout << std::endl;
		}
	}
	void contents() {
		for (File* singleFile : files) {
			singleFile->contents();
			std::cout << std::endl;
		}
	}
	void selfCopy(File*& dest) {
		dest = new Directory(*this);
	}
	void addFile(File* file) {
		File* temp;
		file->selfCopy(temp);
		files.push_back(temp);
	}
};
int main(){
	TextFile f1("file1", "desc1");
	f1.info();std::cout << std::endl;
	std::cout<<f1.size();std::cout << std::endl;
	f1.contents(); std::cout << std::endl;
	TextFile f2("file2", "desc2");
	Directory d1("dir1");
	d1.addFile(&f1);
	d1.addFile(&f2);
	d1.info(); std::cout << std::endl;
	d1.contents(); std::cout << std::endl;
	return 0;
}