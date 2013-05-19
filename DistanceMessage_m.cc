//
// Generated file, do not edit! Created by opp_msgc 4.2 from DistanceMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "DistanceMessage_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(DistanceMessage);

DistanceMessage::DistanceMessage(const char *name, int kind) : cMessage(name,kind)
{
    idSrb_arraysize = 0;
    this->idSrb_var = 0;
    distances_arraysize = 0;
    this->distances_var = 0;
}

DistanceMessage::DistanceMessage(const DistanceMessage& other) : cMessage(other)
{
    idSrb_arraysize = 0;
    this->idSrb_var = 0;
    distances_arraysize = 0;
    this->distances_var = 0;
    copy(other);
}

DistanceMessage::~DistanceMessage()
{
    delete [] idSrb_var;
    delete [] distances_var;
}

DistanceMessage& DistanceMessage::operator=(const DistanceMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void DistanceMessage::copy(const DistanceMessage& other)
{
    delete [] this->idSrb_var;
    this->idSrb_var = (other.idSrb_arraysize==0) ? NULL : new int[other.idSrb_arraysize];
    idSrb_arraysize = other.idSrb_arraysize;
    for (unsigned int i=0; i<idSrb_arraysize; i++)
        this->idSrb_var[i] = other.idSrb_var[i];
    delete [] this->distances_var;
    this->distances_var = (other.distances_arraysize==0) ? NULL : new double[other.distances_arraysize];
    distances_arraysize = other.distances_arraysize;
    for (unsigned int i=0; i<distances_arraysize; i++)
        this->distances_var[i] = other.distances_var[i];
}

void DistanceMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    b->pack(idSrb_arraysize);
    doPacking(b,this->idSrb_var,idSrb_arraysize);
    b->pack(distances_arraysize);
    doPacking(b,this->distances_var,distances_arraysize);
}

void DistanceMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    delete [] this->idSrb_var;
    b->unpack(idSrb_arraysize);
    if (idSrb_arraysize==0) {
        this->idSrb_var = 0;
    } else {
        this->idSrb_var = new int[idSrb_arraysize];
        doUnpacking(b,this->idSrb_var,idSrb_arraysize);
    }
    delete [] this->distances_var;
    b->unpack(distances_arraysize);
    if (distances_arraysize==0) {
        this->distances_var = 0;
    } else {
        this->distances_var = new double[distances_arraysize];
        doUnpacking(b,this->distances_var,distances_arraysize);
    }
}

void DistanceMessage::setIdSrbArraySize(unsigned int size)
{
    int *idSrb_var2 = (size==0) ? NULL : new int[size];
    unsigned int sz = idSrb_arraysize < size ? idSrb_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        idSrb_var2[i] = this->idSrb_var[i];
    for (unsigned int i=sz; i<size; i++)
        idSrb_var2[i] = 0;
    idSrb_arraysize = size;
    delete [] this->idSrb_var;
    this->idSrb_var = idSrb_var2;
}

unsigned int DistanceMessage::getIdSrbArraySize() const
{
    return idSrb_arraysize;
}

int DistanceMessage::getIdSrb(unsigned int k) const
{
    if (k>=idSrb_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idSrb_arraysize, k);
    return idSrb_var[k];
}

void DistanceMessage::setIdSrb(unsigned int k, int idSrb)
{
    if (k>=idSrb_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idSrb_arraysize, k);
    this->idSrb_var[k] = idSrb;
}

void DistanceMessage::setDistancesArraySize(unsigned int size)
{
    double *distances_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = distances_arraysize < size ? distances_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        distances_var2[i] = this->distances_var[i];
    for (unsigned int i=sz; i<size; i++)
        distances_var2[i] = 0;
    distances_arraysize = size;
    delete [] this->distances_var;
    this->distances_var = distances_var2;
}

unsigned int DistanceMessage::getDistancesArraySize() const
{
    return distances_arraysize;
}

double DistanceMessage::getDistances(unsigned int k) const
{
    if (k>=distances_arraysize) throw cRuntimeError("Array of size %d indexed by %d", distances_arraysize, k);
    return distances_var[k];
}

void DistanceMessage::setDistances(unsigned int k, double distances)
{
    if (k>=distances_arraysize) throw cRuntimeError("Array of size %d indexed by %d", distances_arraysize, k);
    this->distances_var[k] = distances;
}

class DistanceMessageDescriptor : public cClassDescriptor
{
  public:
    DistanceMessageDescriptor();
    virtual ~DistanceMessageDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DistanceMessageDescriptor);

DistanceMessageDescriptor::DistanceMessageDescriptor() : cClassDescriptor("DistanceMessage", "cMessage")
{
}

DistanceMessageDescriptor::~DistanceMessageDescriptor()
{
}

bool DistanceMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DistanceMessage *>(obj)!=NULL;
}

const char *DistanceMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DistanceMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int DistanceMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *DistanceMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idSrb",
        "distances",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int DistanceMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idSrb")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "distances")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DistanceMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *DistanceMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DistanceMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DistanceMessage *pp = (DistanceMessage *)object; (void)pp;
    switch (field) {
        case 0: return pp->getIdSrbArraySize();
        case 1: return pp->getDistancesArraySize();
        default: return 0;
    }
}

std::string DistanceMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DistanceMessage *pp = (DistanceMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdSrb(i));
        case 1: return double2string(pp->getDistances(i));
        default: return "";
    }
}

bool DistanceMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DistanceMessage *pp = (DistanceMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdSrb(i,string2long(value)); return true;
        case 1: pp->setDistances(i,string2double(value)); return true;
        default: return false;
    }
}

const char *DistanceMessageDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *DistanceMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DistanceMessage *pp = (DistanceMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


