#include <fstream>
#include "customErrorClass.h"

using namespace std;

typedef struct e_EMPLOYEE
{
	int department;
	int employee_id;
	char name[30];
} e_EMPLOYEE;

class binaryFile {
    public:
        binaryFile(const char*);
        binaryFile(const string&);
        binaryFile(const char*, const char*);
        binaryFile(const string&, const string&);
        ~binaryFile();
        bool search(int,int);
        e_EMPLOYEE retrieve(int,int);
        bool update(e_EMPLOYEE);
    private:
        fstream file;
        const int indexOffset = 6 * sizeof(e_EMPLOYEE);
        void p_TxtToBinary(const char*);
        void p_Sort();
        int p_Search(int,int);
        e_EMPLOYEE p_Retrieve(int);
        bool p_Update(e_EMPLOYEE);
};