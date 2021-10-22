#ifndef INDEXOBJECT_H
#define INDEXOBJECT_H

/**
* @brief
* @details
*
* @author Myint Aung
*/
class indexObject
{
private:
    std::string keytype, reftype, pkey, ref;
    int keylength, reflength, headersize;

public:
    indexObject();
    const int getKeylength();
    const int getReflength();
    const int getHeadersize();
    const std::string getReftype();
    const std::string getKeytype();
    const std::string getPkey();
    const std::string getRef();

    void setKeylength(int Length);
    void setReflength(int refLength);
    void setHeadersize(int size);
    void setKeytype(std::string keyType);
    void setReftype(std::string refType);
    void setPkey(std::string Pkey);
    void setRef(std::string Ref);
};
    
#endif
