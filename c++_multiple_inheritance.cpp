//###########################################################################
/*
 * Multiple Inheritance
 *
 *  -- A class is directly derived from more than one base classes.
 *
 *  -- Is it worth the trouble?
 */

//###########################################################################

#include <iostream>

using namespace std;

/*
 * Multiple Inheritance
 */

// class InputFile {
// public:
//     void read();
// };

// class OutputFile {
// public:
//     void write();
// };

// class IOFile : public InputFile, public OutputFile {};

// int main() {
//     IOFile f;
// }

// Notes:
//   void open();
//   f.open();
//Correction:
//f.Output::open();

// class File {            //         File
// public:                 //         /  \        -
//     string name;        // InputFile  OutputFile
//     void open(){};      //         \  /
// };                      //        IOFile

// // class InputFile : public File {};
// class InputFile : virtual public File {};

// // class OutputFile : public File {};
// class OutputFile : virtual public File {};

// class IOFile : public InputFile,
//                public OutputFile {}; // Diamond shape of hierarchy

// int main() {
//     IOFile f;
//     f.open();
//     // f.InputFile::name = "File1";
//     // f.OutputFile::name = "File2";
// }

// Compile Error: Ambiguous call to open()
// f.InputFile::name  = "File1";
// f.OutputFile::name = "File2";

// class File {
// public:
//     File(string fname);
// };

// class InputFile : virtual public File {
//     InputFile(string fname) : File(fname) {
//     }
// };

// class OutputFile : virtual public File {
//     OutputFile(string fname) : File(fname) {
//     }
// };

// class IOFile : public InputFile, public OutputFile {
//     IOFile(string fname) : OutputFile(fname), InputFile(fname), File(fname) {
//     }
// };

// int main() {
//     IOFile f;
// }

/*
 * Interface Segregation Principle
 *
 * Split large interfaces into smaller and more specific ones so that clients
 * only need to know about the methods that are of interest to them.
 */

// class Engineer {
// public:
//     ...; // 40 APIs
// };

// class Son {
// public:
//     ...; // 50 APIs
// };

// ...

//     class Andy : public Engineer,
//                  Son {
// public:
//     ...; // 500 APIs
// };

// /*
//  * Benefits of ISP:
//  * 1. Easy-to-use interfaces
//  * 2. Static type safety
//  */

/*
 *  Pure Abstract Classes
 *
 *  Abstract Class: A class has one or more pure virtural functions.
 *
 *  Pure Abstract Classes:
 *  A class containing only pure virtual functions
 *    - no data
 *    - no concrete functions
 *    - no private protected functions
 */

// class OutputFile {
// public:
//     void write() = 0;
//     void open() = 0;
// };

//###########################################################################
/*
 * Summary:
 * 1. Multiple Inheritance is an important technique, e.g. ISP
 * 2. Derive only from PACs when using Multiple Inheritance.
 */
//###########################################################################

/*
 * Guidelines for Implementation Inheritance:
 * 1. Do not use inheritance for code reuse, use composition.
 * 2. Minimize the implementation in base classes. Base classes should be thin.
 * 3. Minimize the level of hierarchies in implementation inheritance.
 */

/*
 * "Inheritance is evil"  ???
 *
 * "Inheritance is often useful, but more often overused (abused)."
 */

/*
 *  Pure Abstract Class (PAC)
 *
 *  Abstract Class: A class has one or more pure virtual functions.
 *
 *  Pure Abstract Classes:
 *  A class containing only pure virtual public functions
 *    - no data
 *    - no concrete functions
 *    - no private or protected functions
 */

// class File {
// public:
//     /* Open a file with the name of "filename"
//     * param filename  C-string name of the file to be opened.
//     */
//     void open(const char* filename) = 0;

//     /* Close the file
//     */
//     void close() = 0;
// };
