//
// Generated file, do not edit! Created by opp_msgc 4.2 from PowerMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PowerMessage_m.h"

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




Register_Class(PowerMessage);

PowerMessage::PowerMessage(const char *name, int kind) : cMessage(name,kind)
{
    this->idServingSrb_var = 0;
    this->idMS_var = 0;
    idSrb_arraysize = 0;
    this->idSrb_var = 0;
    potenze_arraysize = 0;
    this->potenze_var = 0;
}

PowerMessage::PowerMessage(const PowerMessage& other) : cMessage(other)
{
    idSrb_arraysize = 0;
    this->idSrb_var = 0;
    potenze_arraysize = 0;
    this->potenze_var = 0;
    copy(other);
}

PowerMessage::~PowerMessage()
{
    delete [] idSrb_var;
    delete [] potenze_var;
}

PowerMessage& PowerMessage::operator=(const PowerMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void PowerMessage::copy(const PowerMessage& other)
{
    this->idServingSrb_var = other.idServingSrb_var;
    this->idMS_var = other.idMS_var;
    delete [] this->idSrb_var;
    this->idSrb_var = (other.idSrb_arraysize==0) ? NULL : new int[other.idSrb_arraysize];
    idSrb_arraysize = other.idSrb_arraysize;
    for (unsigned int i=0; i<idSrb_arraysize; i++)
        this->idSrb_var[i] = other.idSrb_var[i];
    delete [] this->potenze_var;
    this->potenze_var = (other.potenze_arraysize==0) ? NULL : new double[other.potenze_arraysize];
    potenze_arraysize = other.potenze_arraysize;
    for (unsigned int i=0; i<potenze_arraysize; i++)
        this->potenze_var[i] = other.potenze_var[i];
}

void PowerMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idServingSrb_var);
    doPacking(b,this->idMS_var);
    b->pack(idSrb_arraysize);
    doPacking(b,this->idSrb_var,idSrb_arraysize);
    b->pack(potenze_arraysize);
    doPacking(b,this->potenze_var,potenze_arraysize);
}

void PowerMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idServingSrb_var);
    doUnpacking(b,this->idMS_var);
    delete [] this->idSrb_var;
    b->unpack(idSrb_arraysize);
    if (idSrb_arraysize==0) {
        this->idSrb_var = 0;
    } else {
        this->idSrb_var = new int[idSrb_arraysize];
        doUnpacking(b,this->idSrb_var,idSrb_arraysize);
    }
    delete [] this->potenze_var;
    b->unpack(potenze_arraysize);
    if (potenze_arraysize==0) {
        this->potenze_var = 0;
    } else {
        this->potenze_var = new double[potenze_arraysize];
        doUnpacking(b,this->potenze_var,potenze_arraysize);
    }
}

int PowerMessage::getIdServingSrb() const
{
    return idServingSrb_var;
}

void PowerMessage::setIdServingSrb(int idServingSrb)
{
    this->idServingSrb_var = idServingSrb;
}

int PowerMessage::getIdMS() const
{
    return idMS_var;
}

void PowerMessage::setIdMS(int idMS)
{
    this->idMS_var = idMS;
}

void PowerMessage::setIdSrbArraySize(unsigned int size)
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

unsigned int PowerMessage::getIdSrbArraySize() const
{
    return idSrb_arraysize;
}

int PowerMessage::getIdSrb(unsigned int k) const
{
    if (k>=idSrb_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idSrb_arraysize, k);
    return idSrb_var[k];
}

void PowerMessage::setIdSrb(unsigned int k, int idSrb)
{
    if (k>=idSrb_arraysize) throw cRuntimeError("Array of size %d indexed by %d", idSrb_arraysize, k);
    this->idSrb_var[k] = idSrb;
}

void PowerMessage::setPotenzeArraySize(unsigned int size)
{
    double *potenze_var2 = (size==0) ? NULL : new double[size];
    unsigned int sz = potenze_arraysize < size ? potenze_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        potenze_var2[i] = this->potenze_var[i];
    for (unsigned int i=sz; i<size; i++)
        potenze_var2[i] = 0;
    potenze_arraysize = size;
    delete [] this->potenze_var;
    this->potenze_var = potenze_var2;
}

unsigned int PowerMessage::getPotenzeArraySize() const
{
    return potenze_arraysize;
}

double PowerMessage::getPotenze(unsigned int k) const
{
    if (k>=potenze_arraysize) throw cRuntimeError("Array of size %d indexed by %d", potenze_arraysize, k);
    return potenze_var[k];
}

void PowerMessage::setPotenze(unsigned int k, double potenze)
{
    if (k>=potenze_arraysize) throw cRuntimeError("Array of size %d indexed by %d", potenze_arraysize, k);
    this->potenze_var[k] = potenze;
}

class PowerMessageDescriptor : public cClassDescriptor
{
  public:
    PowerMessageDescriptor();
    virtual ~PowerMessageDescriptor();

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

Register_ClassDescriptor(PowerMessageDescriptor);

PowerMessageDescriptor::PowerMessageDescriptor() : cClassDescriptor("PowerMessage", "cMessage")
{
}

PowerMessageDescriptor::~PowerMessageDescriptor()
{
}

bool PowerMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PowerMessage *>(obj)!=NULL;
}

const char *PowerMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PowerMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int PowerMessageDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *PowerMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idServingSrb",
        "idMS",
        "idSrb",
        "potenze",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int PowerMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idServingSrb")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMS")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "idSrb")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "potenze")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PowerMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "double",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *PowerMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PowerMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PowerMessage *pp = (PowerMessage *)object; (void)pp;
    switch (field) {
        case 2: return pp->getIdSrbArraySize();
        case 3: return pp->getPotenzeArraySize();
        default: return 0;
    }
}

std::string PowerMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PowerMessage *pp = (PowerMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdServingSrb());
        case 1: return long2string(pp->getIdMS());
        case 2: return long2string(pp->getIdSrb(i));
        case 3: return double2string(pp->getPotenze(i));
        default: return "";
    }
}

bool PowerMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PowerMessage *pp = (PowerMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdServingSrb(string2long(value)); return true;
        case 1: pp->setIdMS(string2long(value)); return true;
        case 2: pp->setIdSrb(i,string2long(value)); return true;
        case 3: pp->setPotenze(i,string2double(value)); return true;
        default: return false;
    }
}

const char *PowerMessageDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *PowerMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PowerMessage *pp = (PowerMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


