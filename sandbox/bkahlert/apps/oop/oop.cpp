#include <iostream>
#include <seqan/sequence.h>  // CharString, ...
#include <seqan/file.h>      // to stream a CharString into cout

int main(int, char const **)
{
    seqan::CharString mySeqanString = "Hello SeqAn!";
    
    // SeqAn OOP test
    int globalLength = length(mySeqanString);
    int memberLength = mySeqanString.length();
    std::cout << "global length: " << globalLength << std::endl;
    std::cout << "member length: " << memberLength << std::endl;
    std::cout << "CharString works? " << (globalLength == memberLength ? "yes" : "no") << "\n" << std::endl;
    
    seqan::DnaString dnaString = "GATTACA";
    std::cout << "DnaString.length() works? " << (dnaString.length() == length(dnaString) ? "yes" : "no") << std::endl;
    
    seqan::String<seqan::Dna, seqan::Packed<> > packedDnaString = "GATTACA";
    std::cout << "PackedDnaString.length() works? " << (packedDnaString.length() == length(packedDnaString) ? "yes" : "no") << std::endl;
    
    return 1;
}