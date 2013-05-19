//
// Generated file, do not edit! Created by opp_msgc 4.2 from HelloMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "HelloMessage_m.h"

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




Register_Class(HelloMessage);

HelloMessage::HelloMessage(const char *name, int kind) : cMessage(name,kind)
{
    this->idSRB_var = 0;
    this->frequenzaCanalePilota_var = 0;
    this->frequenzaCanaleDati_var = 0;
    this->frequenzaCanaleSegnalazione_var = 0;
}

HelloMessage::HelloMessage(const HelloMessage& other) : cMessage(other)
{
    copy(other);
}

HelloMessage::~HelloMessage()
{
}

HelloMessage& HelloMessage::operator=(const HelloMessage& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void HelloMessage::copy(const HelloMessage& other)
{
    this->idSRB_var = other.idSRB_var;
    this->frequenzaCanalePilota_var = other.frequenzaCanalePilota_var;
    this->frequenzaCanaleDati_var = other.frequenzaCanaleDati_var;
    this->frequenzaCanaleSegnalazione_var = other.frequenzaCanaleSegnalazione_var;
}

void HelloMessage::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->idSRB_var);
    doPacking(b,this->frequenzaCanalePilota_var);
    doPacking(b,this->frequenzaCanaleDati_var);
    doPacking(b,this->frequenzaCanaleSegnalazione_var);
}

void HelloMessage::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->idSRB_var);
    doUnpacking(b,this->frequenzaCanalePilota_var);
    doUnpacking(b,this->frequenzaCanaleDati_var);
    doUnpacking(b,this->frequenzaCanaleSegnalazione_var);
}

int HelloMessage::getIdSRB() const
{
    return idSRB_var;
}

void HelloMessage::setIdSRB(int idSRB)
{
    this->idSRB_var = idSRB;
}

double HelloMessage::getFrequenzaCanalePilota() const
{
    return frequenzaCanalePilota_var;
}

void HelloMessage::setFrequenzaCanalePilota(double frequenzaCanalePilota)
{
    this->frequenzaCanalePilota_var = frequenzaCanalePilota;
}

double HelloMessage::getFrequenzaCanaleDati() const
{
    return frequenzaCanaleDati_var;
}

void HelloMessage::setFrequenzaCanaleDati(double frequenzaCanaleDati)
{
    this->frequenzaCanaleDati_var = frequenzaCanaleDati;
}

double HelloMessage::getFrequenzaCanaleSegnalazione() const
{
    return frequenzaCanaleSegnalazione_var;
}

void HelloMessage::setFrequenzaCanaleSegnalazione(double frequenzaCanaleSegnalazione)
{
    this->frequenzaCanaleSegnalazione_var = frequenzaCanaleSegnalazione;
}

class HelloMessageDescriptor : public cClassDescriptor
{
  public:
    HelloMessageDescriptor();
    virtual ~HelloMessageDescriptor();

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

Register_ClassDescriptor(HelloMessageDescriptor);

HelloMessageDescriptor::HelloMessageDescriptor() : cClassDescriptor("HelloMessage", "cMessage")
{
}

HelloMessageDescriptor::~HelloMessageDescriptor()
{
}

bool HelloMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HelloMessage *>(obj)!=NULL;
}

const char *HelloMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HelloMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int HelloMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *HelloMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "idSRB",
        "frequenzaCanalePilota",
        "frequenzaCanaleDati",
        "frequenzaCanaleSegnalazione",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int HelloMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "idSRB")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frequenzaCanalePilota")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "frequenzaCanaleDati")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "frequenzaCanaleSegnalazione")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HelloMessageDescriptor::getFieldTypeString(void *object, int field) const
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
        "double",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *HelloMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HelloMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HelloMessage *pp = (HelloMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HelloMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HelloMessage *pp = (HelloMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getIdSRB());
        case 1: return double2string(pp->getFrequenzaCanalePilota());
        case 2: return double2string(pp->getFrequenzaCanaleDati());
        case 3: return double2string(pp->getFrequenzaCanaleSegnalazione());
        default: return "";
    }
}

bool HelloMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HelloMessage *pp = (HelloMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIdSRB(string2long(value)); return true;
        case 1: pp->setFrequenzaCanalePilota(string2double(value)); return true;
        case 2: pp->setFrequenzaCanaleDati(string2double(value)); return true;
        case 3: pp->setFrequenzaCanaleSegnalazione(string2double(value)); return true;
        default: return false;
    }
}

const char *HelloMessageDescriptor::getFieldStructName(void *object, int field) const
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

void *HelloMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HelloMessage *pp = (HelloMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


