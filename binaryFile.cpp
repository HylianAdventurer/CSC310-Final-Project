#include "binaryFile.h"

// /**************************** PRIVATE: txtToBinary ****************************/
// void binaryFile::p_TxtToBinary(char fname[]) {
//     ifstream infile;
//     infile.open(fname);
//     file.seekg(indexOffset,file.beg);
//     while(!infile.eof()) {
//         employee e;
//         fill(&e.name,&e.name+30,0);
//         infile >> e.department;
//         infile >> e.employee_id;
//         infile.ignore(); // Ignores comma
//         for(int i = 0; i < 30 && infile.peek()!='\n'; i++) infile >> e.name[i];
//         file.write((char*)&e, sizeof(e));
//     }
//     p_sort();
//     file.seekg(0,file.beg);
//     for(int dep = 0, offset = 0; dep < 5 && !file.eof(); offset++) {
//         employee e;
//         file.seekg(indexOffset+offset*sizeof(employee),file.beg);
//         file.read(&e,sizeof(employee));
//         if(e.department == dep) {
//             file.seekg(dep * sizeof(int),file.beg);
//             file << dep++;
//         }
//     }
// }

// /**************************** PRIVATE: sort ****************************/
// void binaryFile::p_Sort() {

// }

// /**************************** PRIVATE: search ****************************/
// int binaryFile::p_Search(int dep, int id) {
//     int offset;
//     employee e;
//     file.seekg(dep * sizeof(int),file.beg);
//     file >> offset;
//     file.seekg(indexOffset + offset * sizeof(employee),file.beg);
//     do {
//         file.read((char*)&e,sizeof(employee));
//         if(e.employee_id == id) return offset;
//         offset++;
//     } while(!file.eof() && e.department == dep);

//     return -1;
// }

// /**************************** PRIVATE: retrieve ****************************/
// employee binaryFile::p_Retrieve(int offset) {
//     employee e;
//     file.seekg(indexOffset + offset * sizeof(employee),file.beg);
//     file.read((char*)&e,sizeof(employee));
//     return e;
// }

// /**************************** PRIVATE: update ****************************/
// bool binaryFile::p_Update(employee employee) {
//     int offset = p_Search(employee.dep,employee.id);
//     if(offset == -1) return false;
// }