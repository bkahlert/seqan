#include <iostream>
#include <seqan/sequence.h>  // CharString, ...
#include <seqan/file.h>      // to stream a CharString into cout

namespace mynamespace
{
    
template<typename TSpec>
class TestString;
    
template<typename Q>
int xlength(Q t);
    
template<typename TSpec>
int xlength(TestString<TSpec> t);
    
template<typename TThis>
class OTestString
{
public:
    int xlength()
    {
        return ::mynamespace::xlength(*static_cast<TThis*>(this));
    }
};

template<typename TSpec>
class TestString : public OTestString<TestString<TSpec> >
{};

template<typename Q>
int xlength(Q t)
{
    return 20;
}
    
template<typename TSpec>
int xlength(TestString<TSpec> t)
{
    return 10;
}

    
}


int main(int, char const **)
{
    seqan::String<char, seqan::Alloc<void> > mySeqanString = "Hello SeqAn!";
    
    // SeqAn OOP test
    int globalLength = length(mySeqanString);
    int memberLength = mySeqanString.length();
    std::cout << "global length: " << globalLength << std::endl;
    std::cout << "member length: " << mySeqanString.length() << std::endl;
    std::cout << "SeqAn OOP layer works: " << (globalLength == memberLength ? "yes" : "no") << std::endl;
    
    // Custom OOP test
    mynamespace::TestString<void> testString;
    std::cout << testString.xlength() << std::endl;
    std::cout << "Custom implementation works: " << (testString.xlength() == 10 ? "yes" : "no") << std::endl;
    
    return 1;
}