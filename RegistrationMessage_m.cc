//
// Generated file, do not edit! Created by opp_msgc 4.2 from RegistrationMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RegistrationMessage_m.h"

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




Register_Class(RegistrationMessage);

RegistrationMessage::RegistrationMessage(const char *name, int kind) : cMessage(name,kind)
{
    this->idMS_var = 0;
    this->idSRB_var = 0;
}

RegistrationMessage::RegistrationMessage(const RegistrationMessage& other) : cMessage(other)
{
    copy(other);
}

RegistrationMessage::~RegistrationMessage()
{
}

RegistrationMessage& RegistrationMessage::operator=(const RegistrationMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void RegistrationMessage::copy(const RegistrationMessage& other)
{
    this->idMS_var = other.idMS_var;
    this->idSRB_var = other.idSRB_var;
}

void RegistrationMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idMS_var);
    doPacking(b,this->idSRB_var);
}

void RegistrationMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idMS_var);
    doUnpacking(b,this->idSRB_var);
}

int RegistrationMessage::getIdMS() const
{
    return idMS_var;
}

void RegistrationMessage::setIdMS(int idMS)
{
    this->idMS_var = idMS;
}

int RegistrationMessage::getIdSRB() const
{
    return idSRB_var;
}

void RegistrationMessage::setIdSRB(int idSRB)
{
    this->idSRB_var = idSRB;
}

class RegistrationMessageDescriptor : public cClassDescriptor
{
  public:
    RegistrationMessageDescriptor();
    virtual ~RegistrationMessageDescriptor();

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

Register_ClassDescriptor(RegistrationMessageDescriptor);

RegistrationMessageDescriptor::RegistrationMessageDescriptor() : cClassDescriptor("RegistrationMessage", "cMessage")
{
}

RegistrationMessageDescriptor::~RegistrationMessageDescriptor()
{
}

bool RegistrationMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RegistrationMessage *>(obj)!=NULL;
}

const char *RegistrationMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RegistrationMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int RegistrationMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *RegistrationMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idMS",
        "idSRB",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int RegistrationMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMS")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idSRB")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RegistrationMessageDescriptor::getFieldTypeString(void *object, int field) const
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

const char *RegistrationMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RegistrationMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationMessage *pp = (RegistrationMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RegistrationMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationMessage *pp = (RegistrationMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdMS());
        case 1: return long2string(pp->getIdSRB());
        default: return "";
    }
}

bool RegistrationMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationMessage *pp = (RegistrationMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdMS(string2long(value)); return true;
        case 1: pp->setIdSRB(string2long(value)); return true;
        default: return false;
    }
}

const char *RegistrationMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *RegistrationMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RegistrationMessage *pp = (RegistrationMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


