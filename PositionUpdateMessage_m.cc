//
// Generated file, do not edit! Created by opp_msgc 4.2 from PositionUpdateMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PositionUpdateMessage_m.h"

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




Register_Class(PositionUpdateMessage);

PositionUpdateMessage::PositionUpdateMessage(const char *name, int kind) : cMessage(name,kind)
{
    this->idMs_var = 0;
    this->deltaX_var = 0;
    this->deltaY_var = 0;
}

PositionUpdateMessage::PositionUpdateMessage(const PositionUpdateMessage& other) : cMessage(other)
{
    copy(other);
}

PositionUpdateMessage::~PositionUpdateMessage()
{
}

PositionUpdateMessage& PositionUpdateMessage::operator=(const PositionUpdateMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void PositionUpdateMessage::copy(const PositionUpdateMessage& other)
{
    this->idMs_var = other.idMs_var;
    this->deltaX_var = other.deltaX_var;
    this->deltaY_var = other.deltaY_var;
}

void PositionUpdateMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idMs_var);
    doPacking(b,this->deltaX_var);
    doPacking(b,this->deltaY_var);
}

void PositionUpdateMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idMs_var);
    doUnpacking(b,this->deltaX_var);
    doUnpacking(b,this->deltaY_var);
}

int PositionUpdateMessage::getIdMs() const
{
    return idMs_var;
}

void PositionUpdateMessage::setIdMs(int idMs)
{
    this->idMs_var = idMs;
}

double PositionUpdateMessage::getDeltaX() const
{
    return deltaX_var;
}

void PositionUpdateMessage::setDeltaX(double deltaX)
{
    this->deltaX_var = deltaX;
}

double PositionUpdateMessage::getDeltaY() const
{
    return deltaY_var;
}

void PositionUpdateMessage::setDeltaY(double deltaY)
{
    this->deltaY_var = deltaY;
}

class PositionUpdateMessageDescriptor : public cClassDescriptor
{
  public:
    PositionUpdateMessageDescriptor();
    virtual ~PositionUpdateMessageDescriptor();

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

Register_ClassDescriptor(PositionUpdateMessageDescriptor);

PositionUpdateMessageDescriptor::PositionUpdateMessageDescriptor() : cClassDescriptor("PositionUpdateMessage", "cMessage")
{
}

PositionUpdateMessageDescriptor::~PositionUpdateMessageDescriptor()
{
}

bool PositionUpdateMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PositionUpdateMessage *>(obj)!=NULL;
}

const char *PositionUpdateMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PositionUpdateMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PositionUpdateMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *PositionUpdateMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idMs",
        "deltaX",
        "deltaY",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PositionUpdateMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idMs")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "deltaX")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "deltaY")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PositionUpdateMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PositionUpdateMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int PositionUpdateMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PositionUpdateMessage *pp = (PositionUpdateMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PositionUpdateMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PositionUpdateMessage *pp = (PositionUpdateMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdMs());
        case 1: return double2string(pp->getDeltaX());
        case 2: return double2string(pp->getDeltaY());
        default: return "";
    }
}

bool PositionUpdateMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PositionUpdateMessage *pp = (PositionUpdateMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdMs(string2long(value)); return true;
        case 1: pp->setDeltaX(string2double(value)); return true;
        case 2: pp->setDeltaY(string2double(value)); return true;
        default: return false;
    }
}

const char *PositionUpdateMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *PositionUpdateMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PositionUpdateMessage *pp = (PositionUpdateMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


