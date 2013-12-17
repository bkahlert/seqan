#include <iostream>
#include <seqan/sequence.h>  // CharString, ...
#include <seqan/file.h>      // to stream a CharString into cout

namespace mynamespace
{
    template<typename TSpec>
    class MyT;
    
    template<typename Q>
    int notlength(Q t);
    
    template<typename TSpec>
    int notlength(MyT<TSpec> t);
    
template<typename TThis>
class OOPString
{
public:
    int notlength()
    {
        return ::mynamespace::notlength(*(static_cast<TThis*>(this)));
    }
};

template<typename TSpec>
class MyT : public OOPString<MyT<TSpec> >
{};

    template<typename Q>
    int notlength(Q t)
    {
        return 20;
    }
    
    template<typename TSpec>
    int notlength(MyT<TSpec> t)
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
    mynamespace::MyT<void> myT;
    std::cout << myT.notlength() << std::endl;
    std::cout << "Custom implementation works: " << (myT.notlength() == 10 ? "yes" : "no") << std::endl;
    
    return 1;
}