//
// Generated file, do not edit! Created by opp_msgc 4.2 from HandoverMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "HandoverMessage_m.h"

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




Register_Class(HandoverMessage);

HandoverMessage::HandoverMessage(const char *name, int kind) : cMessage(name,kind)
{
    this->idMs_var = 0;
    this->idServingSrb_var = 0;
    this->idDriftSrb_var = 0;
}

HandoverMessage::HandoverMessage(const HandoverMessage& other) : cMessage(other)
{
    copy(other);
}

HandoverMessage::~HandoverMessage()
{
}

HandoverMessage& HandoverMessage::operator=(const HandoverMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void HandoverMessage::copy(const HandoverMessage& other)
{
    this->idMs_var = other.idMs_var;
    this->idServingSrb_var = other.idServingSrb_var;
    this->idDriftSrb_var = other.idDriftSrb_var;
}

void HandoverMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idMs_var);
    doPacking(b,this->idServingSrb_var);
    doPacking(b,this->idDriftSrb_var);
}

void HandoverMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idMs_var);
    doUnpacking(b,this->idServingSrb_var);
    doUnpacking(b,this->idDriftSrb_var);
}

int HandoverMessage::getIdMs() const
{
    return idMs_var;
}

void HandoverMessage::setIdMs(int idMs)
{
    this->idMs_var = idMs;
}

int HandoverMessage::getIdServingSrb() const
{
    return idServingSrb_var;
}

void HandoverMessage::setIdServingSrb(int idServingSrb)
{
    this->idServingSrb_var = idServingSrb;
}

int HandoverMessage::getIdDriftSrb() const
{
    return idDriftSrb_var;
}

void HandoverMessage::setIdDriftSrb(int idDriftSrb)
{
    this->idDriftSrb_var = idDriftSrb;
}

class HandoverMessageDescriptor : public cClassDescriptor
{
  public:
    HandoverMessageDescriptor();
    virtual ~HandoverMessageDescriptor();

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

Register_ClassDescriptor(HandoverMessageDescriptor);

HandoverMessageDescriptor::HandoverMessageDescriptor() : cClassDescriptor("HandoverMessage", "cMessage")
{
}

HandoverMessageDescriptor::~HandoverMessageDescriptor()
{
}

bool HandoverMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HandoverMessage *>(obj)!=NULL;
}

const char *HandoverMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HandoverMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int HandoverMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *HandoverMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idMs",
        "idServingSrb",
        "idDriftSrb",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int HandoverMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMs")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idServingSrb")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "idDriftSrb")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HandoverMessageDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *HandoverMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HandoverMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HandoverMessage *pp = (HandoverMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HandoverMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HandoverMessage *pp = (HandoverMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdMs());
        case 1: return long2string(pp->getIdServingSrb());
        case 2: return long2string(pp->getIdDriftSrb());
        default: return "";
    }
}

bool HandoverMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HandoverMessage *pp = (HandoverMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdMs(string2long(value)); return true;
        case 1: pp->setIdServingSrb(string2long(value)); return true;
        case 2: pp->setIdDriftSrb(string2long(value)); return true;
        default: return false;
    }
}

const char *HandoverMessageDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *HandoverMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HandoverMessage *pp = (HandoverMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


