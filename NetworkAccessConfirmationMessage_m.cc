//
// Generated file, do not edit! Created by opp_msgc 4.2 from NetworkAccessConfirmationMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "NetworkAccessConfirmationMessage_m.h"

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




Register_Class(NetworkAccessConfirmationMessage);

NetworkAccessConfirmationMessage::NetworkAccessConfirmationMessage(const char *name, int kind) : cMessage(name,kind)
{
    this->idSrb_var = 0;
    this->idMs_var = 0;
}

NetworkAccessConfirmationMessage::NetworkAccessConfirmationMessage(const NetworkAccessConfirmationMessage& other) : cMessage(other)
{
    copy(other);
}

NetworkAccessConfirmationMessage::~NetworkAccessConfirmationMessage()
{
}

NetworkAccessConfirmationMessage& NetworkAccessConfirmationMessage::operator=(const NetworkAccessConfirmationMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void NetworkAccessConfirmationMessage::copy(const NetworkAccessConfirmationMessage& other)
{
    this->idSrb_var = other.idSrb_var;
    this->idMs_var = other.idMs_var;
}

void NetworkAccessConfirmationMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idSrb_var);
    doPacking(b,this->idMs_var);
}

void NetworkAccessConfirmationMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idSrb_var);
    doUnpacking(b,this->idMs_var);
}

int NetworkAccessConfirmationMessage::getIdSrb() const
{
    return idSrb_var;
}

void NetworkAccessConfirmationMessage::setIdSrb(int idSrb)
{
    this->idSrb_var = idSrb;
}

int NetworkAccessConfirmationMessage::getIdMs() const
{
    return idMs_var;
}

void NetworkAccessConfirmationMessage::setIdMs(int idMs)
{
    this->idMs_var = idMs;
}

class NetworkAccessConfirmationMessageDescriptor : public cClassDescriptor
{
  public:
    NetworkAccessConfirmationMessageDescriptor();
    virtual ~NetworkAccessConfirmationMessageDescriptor();

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

Register_ClassDescriptor(NetworkAccessConfirmationMessageDescriptor);

NetworkAccessConfirmationMessageDescriptor::NetworkAccessConfirmationMessageDescriptor() : cClassDescriptor("NetworkAccessConfirmationMessage", "cMessage")
{
}

NetworkAccessConfirmationMessageDescriptor::~NetworkAccessConfirmationMessageDescriptor()
{
}

bool NetworkAccessConfirmationMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<NetworkAccessConfirmationMessage *>(obj)!=NULL;
}

const char *NetworkAccessConfirmationMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NetworkAccessConfirmationMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int NetworkAccessConfirmationMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *NetworkAccessConfirmationMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idSrb",
        "idMs",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int NetworkAccessConfirmationMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idSrb")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMs")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NetworkAccessConfirmationMessageDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *NetworkAccessConfirmationMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int NetworkAccessConfirmationMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    NetworkAccessConfirmationMessage *pp = (NetworkAccessConfirmationMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NetworkAccessConfirmationMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    NetworkAccessConfirmationMessage *pp = (NetworkAccessConfirmationMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdSrb());
        case 1: return long2string(pp->getIdMs());
        default: return "";
    }
}

bool NetworkAccessConfirmationMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    NetworkAccessConfirmationMessage *pp = (NetworkAccessConfirmationMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdSrb(string2long(value)); return true;
        case 1: pp->setIdMs(string2long(value)); return true;
        default: return false;
    }
}

const char *NetworkAccessConfirmationMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *NetworkAccessConfirmationMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    NetworkAccessConfirmationMessage *pp = (NetworkAccessConfirmationMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


