#include <fstream>
#include "customErrorClass.h"

using namespace std;

typedef struct employee
{
	int department;
	int employee_id;
	char name[30];
} e_EMPLOYEE;

class binaryFile {
    public:
        binaryFile(char fname[]) { file.open(fname, ios::binary); }
        binaryFile(char fname[], char infname[]) : binaryFile(fname) { p_TxtToBinary(infname); }
        ~binaryFile() { file.close(); }
        bool search(int dep, int id) { return p_Search(dep,id) == -1; }
        employee retrieve(int dep, int id) { 
            int i = p_Search(dep,id);
            return i != -1 ? p_Retrieve(i) : *(new employee);
        }
        bool update(employee e) { return p_Update(e); }
    private:
        fstream file;
        const int indexOffset = 5 * sizeof(employee);
        void p_TxtToBinary(char[]);
        void p_Sort();
        int p_Search(int dep,int id);
        employee p_Retrieve(int offset);
        bool p_Update(employee e);
};