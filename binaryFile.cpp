#include "binaryFile.h"

/**************************** PUBLIC: constructor ****************************/
binaryFile::binaryFile(const char * fname) {
    file.open(fname, ios::binary);
}

/**************************** PUBLIC: constructor ****************************/
binaryFile::binaryFile(const string& fname) {
    file.open(fname, ios::binary);
}

/**************************** PUBLIC: constructor ****************************/
binaryFile::binaryFile(const char * fname, const char * infname) : binaryFile(fname) {
    p_TxtToBinary(infname);
}

/**************************** PUBLIC: constructor ****************************/
binaryFile::binaryFile(const string& fname, const string& infname) : binaryFile(fname) {
    p_TxtToBinary(infname.c_str());
}

/**************************** PUBLIC: destructor ****************************/
binaryFile::~binaryFile() {
    file.close();
}

/**************************** PUBLIC: search ****************************/
bool binaryFile::search(int dep, int id) {
    return p_Search(dep,id) == -1;
}

/**************************** PUBLIC: retrieve ****************************/
e_EMPLOYEE binaryFile::retrieve(int dep, int id) {
    int i = p_Search(dep,id);
    return i != -1 ? p_Retrieve(i) : *(new e_EMPLOYEE);
}

/**************************** PUBLIC: update ****************************/
bool binaryFile::update(e_EMPLOYEE employee) {
    return p_Update(employee);
}

/**************************** PRIVATE: txtToBinary ****************************/
void binaryFile::p_TxtToBinary(const char * fname) {
    ifstream infile;
    infile.open(fname);
    if(!infile.good()) throw new myException("File does not exist",ERROR);
    file.seekg(indexOffset,file.beg);
    int total = 0;
    while(!infile.eof()) {
        e_EMPLOYEE employee;
        fill(&employee.name,&employee.name+30,0);
        infile >> employee.department;
        infile >> employee.employee_id;
        infile.ignore(); // Ignores comma
        for(int i = 0; i < 30 && infile.peek()!='\n'; i++) infile >> employee.name[i];
        file.write((char*)&employee, sizeof(e_EMPLOYEE));
        total++;
    }
    file.seekg(indexOffset, file.beg);
    file << total;
    p_Sort();
    file.seekg(0,file.beg);
    for(int dep = 0, offset = 0; dep < 5 && !file.eof(); offset++) {
        e_EMPLOYEE e;
        file.seekg(indexOffset+offset*sizeof(e_EMPLOYEE),file.beg);
        file.read((char*)&e,sizeof(e_EMPLOYEE));
        if(e.department == dep) {
            file.seekg(dep * sizeof(int),file.beg);
            file << dep++;
        }
    }
}

/**************************** PRIVATE: sort ****************************/
void binaryFile::p_Sort() {

}

/**************************** PRIVATE: search ****************************/
int binaryFile::p_Search(int dep, int id) {
    int offset;
    e_EMPLOYEE employee;
    file.seekg(dep * sizeof(int),file.beg);
    file >> offset;
    file.seekg(indexOffset + offset * sizeof(e_EMPLOYEE),file.beg);
    do {
        file.read((char*)&employee,sizeof(e_EMPLOYEE));
        if(employee.employee_id == id) return offset;
        offset++;
    } while(!file.eof() && employee.department == dep);

    return -1;
}

/**************************** PRIVATE: retrieve ****************************/
e_EMPLOYEE binaryFile::p_Retrieve(int offset) {
    e_EMPLOYEE e;
    file.seekg(indexOffset + offset * sizeof(e_EMPLOYEE),file.beg);
    file.read((char*)&e,sizeof(e_EMPLOYEE));
    return e;
}

/**************************** PRIVATE: update ****************************/
bool binaryFile::p_Update(e_EMPLOYEE employee) {
    int offset = p_Search(employee.department,employee.employee_id);
    bool change = false;
    file.seekg(indexOffset + offset * sizeof(e_EMPLOYEE));
    for(int i = 0; i < sizeof(e_EMPLOYEE); i++) {
        change |= file.peek() - ((char*)&employee)[i] == 0;
        file.write(((char*)&employee)+i,1);
    }
    return change;
}